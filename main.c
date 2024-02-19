#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <stdio.h>
#include "forwards.h"
#include "slf.h"
#include "slf_functions.h"

#define DIRECTINPUT_VERSION 0x0800
#include <dinput.h>
#include <stdint.h>
#pragma comment(lib, "Dinput8.lib")
#pragma comment(lib, "Dxguid.lib")


#define panic(x) {\
	if (NULL == x) \
	{ \
		printf("Quitting as %s is null", #x); \
		exit(-1); \
	} \
}

void* my_malloc(size_t _Size) {
	void* res = malloc(_Size);
	panic(res);
	return res;
}

void* g_game_ptr = NULL;
void* g_world_ptr = (void*)0x0095C770;

DWORD* ai_current_player = NULL;
DWORD* fancy_player_ptr = NULL;

char* injected_pack = NULL;


DWORD for_pack_loading[2];


#undef IsEqualGUID
BOOL WINAPI IsEqualGUID(
	REFGUID rguid1,
	REFGUID rguid2)
{
	return !memcmp(rguid1, rguid2, sizeof(GUID));
}



uint8_t color_ramp_function(float ratio, int period_duration, int cur_time) {

	if (cur_time <= 0 || 4 * period_duration <= cur_time)
		return 0;

	if (cur_time < period_duration) {

		float calc = ratio * cur_time;

		return (uint8_t)(min(calc, 1.0f) * 255);
	}


	if (period_duration <= cur_time && cur_time <= 3 * period_duration) {
		return 255;
	}


	if (cur_time <= 4 * period_duration) {

		int adjusted_time = cur_time - 3 * period_duration;
		float calc = 1.f - ratio * adjusted_time;

		return (uint8_t)(min(calc, 1.0f) * 255);
	}

	// never reached
	return 0;
}


typedef struct _list{
	struct _list* next;
	struct _list* prev;
	void* data;
}list;

typedef struct {
	DWORD unk0;
	DWORD strlen;
	char* actualString;
	BYTE unk[256];//not sure how big
}mString;

#define MAX_CHARS_SAFE 63
#define MAX_CHARS MAX_CHARS_SAFE+1
#define EXTEND_NEW_ENTRIES 20
#define MAX_ELEMENTS_PAGE 18

#pragma pack(1)
typedef struct {
	uint8_t unk[0x50];
	uint8_t status;
	uint8_t unk1[0x53];
	float x;
	float y;
	float z;
	uint8_t unk2[0x10];
	DWORD district_id;
	uint8_t unk3[0x4];
	uint8_t variants;
	uint8_t unk4[0x6B];
}region;


typedef enum {
	NORMAL,
	BOOLEAN_E,
	CUSTOM
}debug_menu_entry_type;


typedef enum {
	LEFT,
	RIGHT,
	ENTER
}custom_key_type;


struct _debug_menu_entry;
typedef void (*custom_string_generator_ptr)(struct _debug_menu_entry* entry);

typedef void (*menu_handler_function)(struct _debug_menu_entry*, custom_key_type key_type);
typedef void (*custom_entry_handler_ptr)(struct _debug_menu_entry* entry, custom_key_type key_type, menu_handler_function menu_handler);
typedef struct _debug_menu_entry {

	char text[MAX_CHARS];
	debug_menu_entry_type entry_type;
	void* data;
	void* data1;
	custom_string_generator_ptr custom_string_generator;
	custom_entry_handler_ptr custom_handler;
}debug_menu_entry;

typedef void (*go_back_function)();

typedef struct {
	char title[MAX_CHARS];
	DWORD capacity;
	DWORD used_slots;
	DWORD window_start;
	DWORD cur_index;
	go_back_function go_back;
	menu_handler_function handler;
	debug_menu_entry* entries;
}debug_menu;



debug_menu* start_debug = NULL;
debug_menu* warp_menu = NULL;
debug_menu* district_variants_menu = NULL;
debug_menu* char_select_menu = NULL;
debug_menu* options_menu = NULL;
debug_menu* script_menu = NULL;
debug_menu* progression_menu = NULL;


debug_menu** all_menus[] = {
	&start_debug,
	&warp_menu,
	&district_variants_menu,
	&char_select_menu,
	&options_menu,
	&script_menu,
	&progression_menu
};

debug_menu* current_menu = NULL;



void goto_start_debug() {
	current_menu = start_debug;
}



void unlock_region(region* cur_region) {

	cur_region->status &= 0xFE;
}

void remove_debug_menu_entry(debug_menu_entry* entry) {
	

	DWORD to_be = (DWORD)entry;
	for (int i = 0; i < (sizeof(all_menus) / sizeof(void*)); i++) {

		debug_menu *cur = *all_menus[i];

		DWORD start = (DWORD)cur->entries;
		DWORD end = start + cur->used_slots * sizeof(debug_menu_entry);

		if (start <= (DWORD)entry && (DWORD)entry < end) {


			int index = (to_be - start) / sizeof(debug_menu_entry);

			memcpy(&cur->entries[index], &cur->entries[index + 1], cur->used_slots - (index + 1));
			memset(&cur->entries[cur->used_slots - 1], 0, sizeof(debug_menu_entry));
			cur->used_slots--;
			return;
		}
		
	}

	printf("FAILED TO DEALLOCATE AN ENTRY :S %08X\n", (DWORD)entry);

}

void* add_debug_menu_entry(debug_menu* menu, debug_menu_entry* entry) {

	if (menu->used_slots < menu->capacity) {
		void* ret = &menu->entries[menu->used_slots];
		memcpy(ret, entry, sizeof(debug_menu_entry));
		menu->used_slots++;
		return ret;
	}

	DWORD current_entries_size = sizeof(debug_menu_entry) * menu->capacity;
	DWORD new_entries_size = sizeof(debug_menu_entry) * EXTEND_NEW_ENTRIES;


	void* new_ptr = realloc(menu->entries, current_entries_size + new_entries_size);

	panic(new_ptr);
	menu->capacity += EXTEND_NEW_ENTRIES;
	menu->entries = new_ptr;
	memset(&menu->entries[menu->used_slots], 0, new_entries_size);

	return add_debug_menu_entry(menu, entry);
}




debug_menu* create_menu(const char* title, go_back_function go_back, menu_handler_function function, DWORD capacity) {

	debug_menu* menu = my_malloc(sizeof(debug_menu));

	memset(menu, 0, sizeof(debug_menu));

	strncpy(menu->title, title, MAX_CHARS_SAFE);

	menu->capacity = capacity;
	menu->handler = function;
	menu->go_back = go_back;

	DWORD total_entries_size = sizeof(debug_menu_entry) * capacity;
	menu->entries = my_malloc(total_entries_size);
	memset(menu->entries, 0, total_entries_size);

	return menu;

}


int vm_debug_menu_entry_garbage_collection_id = -1;

typedef int (*script_manager_register_allocated_stuff_callback_ptr)(void* func);
script_manager_register_allocated_stuff_callback_ptr script_manager_register_allocated_stuff_callback = (script_manager_register_allocated_stuff_callback_ptr)0x005AFE40;

typedef int (*construct_client_script_libs_ptr)();
construct_client_script_libs_ptr construct_client_script_libs = (construct_client_script_libs_ptr)0x0058F9C0;


void vm_debug_menu_entry_garbage_collection_callback(void* a1, list* lst) {

	list* end = lst->prev;

	for (list* cur = end->next; cur != end; cur = cur->next) {

		debug_menu_entry* entry = ((debug_menu_entry*)cur->data);
		//printf("Will delete %s %08X\n", entry->text, entry);
		remove_debug_menu_entry(entry);
	}
	
}

int construct_client_script_libs_hook() {


	if (vm_debug_menu_entry_garbage_collection_id == -1) {
		int res = script_manager_register_allocated_stuff_callback(vm_debug_menu_entry_garbage_collection_callback);
		vm_debug_menu_entry_garbage_collection_id = res;
	}
	return construct_client_script_libs();
}


typedef (__fastcall* mString_constructor_ptr)(mString* this, void* edx, char* str);
mString_constructor_ptr mString_constructor = (void*)0x00421100;

typedef (__fastcall* mString_finalize_ptr)(mString* this, void* edx, int zero);
mString_finalize_ptr mString_finalize = (void*)0x004209C0;


region** all_regions = (region**)0x0095C924;
DWORD* number_of_allocated_regions = (DWORD*)0x0095C920;

typedef char* (__fastcall* region_get_name_ptr)(void* this);
region_get_name_ptr region_get_name = (region_get_name_ptr)0x00519BB0;


typedef int (__fastcall *region_get_district_variant_ptr)(region* this);
region_get_district_variant_ptr region_get_district_variant = (region_get_district_variant_ptr)0x005503D0;


typedef char(__fastcall* terrain_set_district_variant_ptr)(void* this, void* edx, DWORD district_id, int variant, char one);
terrain_set_district_variant_ptr terrain_set_district_variant = (terrain_set_district_variant_ptr)0x00557480;


typedef void (*us_lighting_switch_time_of_day_ptr)(int time_of_day);
us_lighting_switch_time_of_day_ptr us_lighting_switch_time_of_day = (void*)0x00408790;

void set_text_writeable() {

	const DWORD text_end = 0x86F000;
	const DWORD text_start = 0x401000;

	DWORD old;
	VirtualProtect((void*)text_start, text_end - text_start, PAGE_EXECUTE_READWRITE, &old);
}

void set_rdata_writeable() {

	const DWORD end = 0x91B000;
	const DWORD start = 0x86F564;

	DWORD old;
	VirtualProtect((void*)start, end - start, PAGE_READWRITE, &old);
}

void HookFunc(DWORD callAdd, void* funcAdd, BOOLEAN jump, const unsigned char* reason) {

	//Only works for E8/E9 hooks	
	DWORD jmpOff = (DWORD)funcAdd - callAdd - 5;

	BYTE shellcode[] = { 0, 0, 0, 0, 0 };
	shellcode[0] = jump ? 0xE9 : 0xE8;

	memcpy(&shellcode[1], &jmpOff, sizeof(jmpOff));
	memcpy((void*)callAdd, shellcode, sizeof(shellcode));

	if (reason)
		printf("Hook: %08X -  %s\n", callAdd, reason);

}


void WriteDWORD(DWORD address, void* newValue, const unsigned char* reason) {
	*(DWORD*)address = (DWORD)newValue;
	if (reason)
		printf("Wrote: %08X -  %s\n", (DWORD)address, reason);
}

typedef int (*nflSystemOpenFile_ptr)(HANDLE* hHandle, LPCSTR lpFileName, unsigned int a3, LARGE_INTEGER liDistanceToMove);
nflSystemOpenFile_ptr nflSystemOpenFile_orig = NULL;

nflSystemOpenFile_ptr* nflSystemOpenFile_data = (void*)0x0094985C;


HANDLE USM_handle = INVALID_HANDLE_VALUE;

int nflSystemOpenFile(HANDLE* hHandle, LPCSTR lpFileName, unsigned int a3, LARGE_INTEGER liDistanceToMove) {


	//printf("Opening file %s\n", lpFileName);
	int ret = nflSystemOpenFile_orig(hHandle, lpFileName, a3, liDistanceToMove);


	if (strstr(lpFileName, "ultimate_spiderman.PCPACK")) {

	}
	return ret;
}



typedef int (*ReadOrWrite_ptr)(int a1, HANDLE* a2, int a3, DWORD a4, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite);
ReadOrWrite_ptr* ReadOrWrite_data = (void*)0x0094986C;
ReadOrWrite_ptr ReadOrWrite_orig = NULL;

int ReadOrWrite(int a1, HANDLE* a2, int a3, DWORD a4, LPCVOID lpBuffer, DWORD nNumberOfBytesToWrite) {

	int ret = ReadOrWrite_orig(a1, a2, a3, a4, lpBuffer, nNumberOfBytesToWrite);

	if (USM_handle == *a2) {
		printf("USM buffer was read %08X\n", (DWORD)lpBuffer);


	}
	return ret;
}


typedef void (*aeps_RenderAll_ptr)();
aeps_RenderAll_ptr aeps_RenderAll_orig = (void*)0x004D9310;

void** nglSysFont = (void**)0x00975208;

typedef void (*nglListAddString_ptr)(void* font, float x, float y, float z, DWORD color, float x_scale, float y_scale, char* format, ...);
nglListAddString_ptr nglListAddString = (void*)0x00779E90;



#define nglColor(r,g,b,a) ( (a << 24) |  (r << 16) | (g << 8) | (b & 255) )


typedef struct {
	BYTE unk[100];
}nglQuad;

typedef void (*nglInitQuad_ptr)(void*);
nglInitQuad_ptr nglInitQuad = (void*)0x0077AC40;


typedef void (*nglSetQuadRect_ptr)(void*, float, float, float, float);
nglSetQuadRect_ptr nglSetQuadRect = (void*)0x0077AD30;


typedef void (*nglSetQuadColor_ptr)(void*, unsigned int);
nglSetQuadColor_ptr nglSetQuadColor = (void*)0x0077AD10;


typedef void (*nglListAddQuad_ptr)(void*);
nglListAddQuad_ptr nglListAddQuad = (void*)0x0077AFE0;


typedef int (*nglListBeginScene_ptr)(int);
nglListBeginScene_ptr nglListBeginScene = (void*)0x0076C970;


typedef void (*nglListEndScene_ptr)();
nglListEndScene_ptr nglListEndScene = (void*)0x00742B50;


typedef void (*nglSetQuadZ_ptr)(void*, float);
nglSetQuadZ_ptr nglSetQuadZ = (void*)0x0077AD70;

typedef void (*nglSetClearFlags_ptr)(int);
nglSetClearFlags_ptr nglSetClearFlags = (void*)0x00769DB0;

void aeps_RenderAll() {



	static cur_time = 0;
	int period = 60;
	int duration = 6 * period;
	float ratio = 1.f / period;

	uint8_t red = color_ramp_function(ratio, period, cur_time + 2 * period) + color_ramp_function(ratio, period, cur_time - 4 * period);
	uint8_t green = color_ramp_function(ratio, period, cur_time);
	uint8_t blue = color_ramp_function(ratio, period, cur_time - 2 * period);

	nglListAddString(*nglSysFont, 0.1f, 0.2f, 0.2f, nglColor(red, green, blue, 255), 1.f, 1.f, "Krystalgamer's Debug menu");

	cur_time = (cur_time + 1) % duration;


	aeps_RenderAll_orig();
}


int debug_enabled = 0;
uint32_t keys[256];





typedef int (*nglGetStringDimensions_ptr)(void*, char* EndPtr, int*, int*, float, float);
nglGetStringDimensions_ptr nglGetStringDimensions = (void*)0x007798E0;



void getStringDimensions(char* str, int* width, int* height) {
	nglGetStringDimensions(*nglSysFont, str, width, height, 1.0, 1.0);
}

int getStringHeight(char* str) {
	int height;
	nglGetStringDimensions(*nglSysFont, str, NULL, &height, 1.0, 1.0);
	return height;
}


char* getRealText(debug_menu_entry* entry, char* str) {



	if (entry->entry_type == BOOLEAN_E) {
		BYTE* val = entry->data;
		sprintf(str, "%s: %s", entry->text, *val ? "True" : "False");
		return str;
	}

	if (entry->entry_type == CUSTOM) {
		entry->custom_string_generator(entry);
	}


	return entry->text;
}

void render_current_debug_menu() {



	char text_buffer[128];
#define UP_ARROW " ^ ^ ^ "
#define DOWN_ARROW " v v v "


	int num_elements = min(MAX_ELEMENTS_PAGE, current_menu->used_slots - current_menu->window_start);
	int needs_down_arrow = ((current_menu->window_start + MAX_ELEMENTS_PAGE) < current_menu->used_slots) ? 1 : 0;


	int cur_width, cur_height;
	int debug_width = 0;
	int debug_height = 0;

#define get_and_update(x) {\
	 getStringDimensions(x, &cur_width, &cur_height); \
	 debug_height += cur_height; \
	 debug_width = max(debug_width, cur_width);\
	}
	//printf("new size: %s %d %d (%d %d)\n", x, debug_width, debug_height, cur_width, cur_height); \


	get_and_update(current_menu->title);
	get_and_update(UP_ARROW);





	int total_elements_page = needs_down_arrow ? MAX_ELEMENTS_PAGE : current_menu->used_slots - current_menu->window_start;

	for (int i = 0; i < total_elements_page; i++) {

		debug_menu_entry *entry = &current_menu->entries[current_menu->window_start + i];
		char* cur = getRealText(entry, text_buffer);
		get_and_update(cur);
	}


	if (needs_down_arrow) {
		get_and_update(DOWN_ARROW);
	}

	nglQuad quad;


	int menu_x_start = 20, menu_y_start = 40;
	int menu_x_pad = 24, menu_y_pad = 18;

	nglInitQuad(&quad);
	nglSetQuadRect(&quad, (float)menu_x_start, (float)menu_y_start, (float)(menu_x_start + debug_width + menu_x_pad), (float)(menu_y_start + debug_height + menu_y_pad));
	nglSetQuadColor(&quad, 0xBE0A0A0A);
	nglSetQuadZ(&quad, 0.5f);
	nglListAddQuad(&quad);


	int white_color = nglColor(255, 255, 255, 255);
	int yellow_color = nglColor(255, 255, 0, 255);
	int green_color = nglColor(0, 255, 0, 255);
	int pink_color = nglColor(255, 0, 255, 255);


	int render_height = menu_y_start;
	render_height += 12;
	int render_x = menu_x_start;
	render_x += 8;
	nglListAddString(*nglSysFont, (float)render_x, (float)(render_height), 0.2f, green_color, 1.f, 1.f, current_menu->title);
	render_height += getStringHeight(current_menu->title);


	if (current_menu->window_start) {
		nglListAddString(*nglSysFont, (float)render_x, (float)render_height, 0.2f, pink_color, 1.f, 1.f, UP_ARROW);
	}
	render_height += getStringHeight(UP_ARROW);



	for (int i = 0; i < total_elements_page; i++) {

		int current_color = current_menu->cur_index == i ? yellow_color : white_color;

		debug_menu_entry* entry = &current_menu->entries[current_menu->window_start + i];
		char* cur = getRealText(entry, text_buffer);
		nglListAddString(*nglSysFont, (float)render_x, (float)render_height, 0.2f, current_color, 1.f, 1.f, cur);
		render_height += getStringHeight(cur);
	}

	if (needs_down_arrow) {
		nglListAddString(*nglSysFont, (float)render_x, (float)render_height, 0.2f, pink_color, 1.f, 1.f, DOWN_ARROW);
		render_height += getStringHeight(DOWN_ARROW);
	}




}
void myDebugMenu() {


	if (debug_enabled) {
		render_current_debug_menu();
	}
	nglListEndScene();
}


typedef int (*wndHandler_ptr)(HWND, UINT, WPARAM, LPARAM);
wndHandler_ptr orig_WindowHandler = (void*)0x005941A0;


/*
	STDMETHOD(GetDeviceState)(THIS_ DWORD,LPVOID) PURE;
	STDMETHOD(GetDeviceData)(THIS_ DWORD,LPDIDEVICEOBJECTDATA,LPDWORD,DWORD) PURE;

*/


typedef int(__stdcall* GetDeviceState_ptr)(IDirectInputDevice8*, DWORD, LPVOID);
GetDeviceState_ptr GetDeviceStateOriginal = NULL;



typedef (__fastcall* game_pause_unpause_ptr)(void* this);
game_pause_unpause_ptr game_pause = (game_pause_unpause_ptr)0x0054FBE0;
game_pause_unpause_ptr game_unpause = (game_pause_unpause_ptr)0x0053A880;




typedef (__fastcall* game_get_cur_state_ptr)(void* this);
game_get_cur_state_ptr game_get_cur_state = (game_get_cur_state_ptr)0x005363D0;



typedef (__fastcall* world_dynamics_system_remove_player_ptr)(void* this, void* edx, int number);
world_dynamics_system_remove_player_ptr world_dynamics_system_remove_player = (void*)0x00558550;


typedef (__fastcall* world_dynamics_system_add_player_ptr)(void* this, void* edx, mString* str);
world_dynamics_system_add_player_ptr world_dynamics_system_add_player = (void*)0x0055B400;


DWORD changing_model = 0;
char* current_costume = "ultimate_spiderman";


typedef (*entity_teleport_abs_po_ptr)(DWORD, float*, int one);
entity_teleport_abs_po_ptr entity_teleport_abs_po = (void*)0x004F3890;


typedef DWORD* (__fastcall* ai_ai_core_get_info_node_ptr)(DWORD* this, void* edx, int a2, char a3);
ai_ai_core_get_info_node_ptr ai_ai_core_get_info_node = (void*)0x006A3390;




typedef struct {
	DWORD unk[32];
}string_hash;

typedef void(__fastcall* string_hash_initialize_ptr)(string_hash* this, void* edx, int a2, char* Str1, int a4);
string_hash_initialize_ptr string_hash_initialize = (void*)0x00547A00;


typedef int(__fastcall* script_object_find_func_ptr)(script_object* this, void* edx, string_hash* a2);
script_object_find_func_ptr script_object_find_func = (void*)0x0058EF80;


typedef DWORD  (__fastcall *script_executable_add_allocated_stuff_ptr)(script_executable* this, void *edx, int a2, int a3, int a4);
script_executable_add_allocated_stuff_ptr script_executable_add_allocated_stuff = (void*)0x005A34B0;


uint8_t __stdcall slf__debug_menu_entry__set_handler__str(slf* function, void* unk) {

	vm_stack_pop(function, 8);

	void** params = (void**)function->stack_ptr;

	debug_menu_entry* entry = params[0];
	char* scrpttext = params[1];

	string_hash strhash;
	string_hash_initialize(&strhash, NULL, 0, scrpttext, 0);


	script_instance* instance = function->thread->instance;
	int functionid = script_object_find_func(instance->object, NULL, *(void**)&strhash);
	entry->data = instance;
	entry->data1 = (void*)functionid;
	
	return 1;
}

uint8_t __stdcall slf__destroy_debug_menu_entry__debug_menu_entry(slf* function, void* unk) {

	vm_stack_pop(function, 4);

	debug_menu_entry** entry = (void*)function->stack_ptr;

	remove_debug_menu_entry(*entry);

	return 1;
}


uint8_t __stdcall slf__create_progression_menu_entry(slf *function, void *unk) {


	vm_stack_pop(function, 8);

	char** strs = (void*)function->stack_ptr;

	//printf("Entry: %s -> %s\n", strs[0], strs[1]);


	string_hash strhash;
	string_hash_initialize(&strhash, NULL, 0, strs[1], 0);


	script_instance* instance = function->thread->instance;
	int functionid = script_object_find_func(instance->object, NULL, *(void**)&strhash);

	debug_menu_entry entry;
	memset(&entry, 0, sizeof(entry));
	entry.entry_type = NORMAL;
	entry.data = instance;
	entry.data1 = (void*)functionid;

	strcpy(entry.text, strs[0]);

	add_debug_menu_entry(progression_menu, &entry);






	/*
	if(function->thread->instance->object->vmexecutable[functionid]->params != 4)
	*/
	
	int push = 0;
	vm_stack_push(function, &push, sizeof(push));
	return 1;
}

uint8_t __stdcall slf__create_debug_menu_entry(slf* function, void* unk) {

	vm_stack_pop(function, 4);

	char** strs = (void*)function->stack_ptr;

	//printf("Entry: %s ", strs[0]);


	debug_menu_entry entry;
	memset(&entry, 0, sizeof(entry));
	entry.entry_type = NORMAL;
	strcpy(entry.text, strs[0]);

	void *res = add_debug_menu_entry(script_menu, &entry);

	script_executable* se = function->thread->vmexecutable->unk_struct->scriptexecutable;
	script_executable_add_allocated_stuff(se, NULL, vm_debug_menu_entry_garbage_collection_id, (int)res, 0);

	//printf("%08X\n", res);

	int push = (int)res;
	vm_stack_push(function, &push, sizeof(push));
	return 1;
}


DWORD modulo(int num, DWORD mod) {
	if (num >= 0) {
		return num % mod;
	}

	int absolute = abs(num);
	if (absolute % mod == 0)
		return 0;


	return mod - absolute % mod;
}


void menu_go_down() {


	if ((current_menu->window_start + MAX_ELEMENTS_PAGE) < current_menu->used_slots) {

		if (current_menu->cur_index < MAX_ELEMENTS_PAGE / 2)
			current_menu->cur_index++;
		else
			current_menu->window_start++;
	}
	else {

		int num_elements = min(MAX_ELEMENTS_PAGE, current_menu->used_slots - current_menu->window_start);
		current_menu->cur_index = modulo(current_menu->cur_index + 1, num_elements);
		if (current_menu->cur_index == 0)
			current_menu->window_start = 0;
	}
}

void menu_go_up() {


	int num_elements = min(MAX_ELEMENTS_PAGE, current_menu->used_slots - current_menu->window_start);
	if (current_menu->window_start) {


		if (current_menu->cur_index > MAX_ELEMENTS_PAGE / 2)
			current_menu->cur_index--;
		else
			current_menu->window_start--;

	}
	else {

		int num_elements = min(MAX_ELEMENTS_PAGE, current_menu->used_slots - current_menu->window_start);
		current_menu->cur_index = modulo(current_menu->cur_index - 1, num_elements);
		if (current_menu->cur_index == (num_elements - 1))
			current_menu->window_start = current_menu->used_slots - num_elements;

	}

}

int sort_warp_entries(const debug_menu_entry* entry1, const debug_menu_entry* entry2) {
	return strcmp(entry1->text, entry2->text);
}


void district_variant_string_generator(debug_menu_entry* entry) {

	int old_variant = (int)entry->data1;
	int current_variant = region_get_district_variant(entry->data);

	if (current_variant == old_variant) {
		return;
	}

	char* region_name = region_get_name(entry->data);

	snprintf(entry->text, MAX_CHARS,"%s: %d", region_name, current_variant);
	entry->data1 = (void*)current_variant;
}




typedef enum {
	MENU_TOGGLE,
	MENU_ACCEPT,
	MENU_BACK,

	MENU_UP,
	MENU_DOWN,
	MENU_LEFT,
	MENU_RIGHT,


	MENU_KEY_MAX
}MenuKey;

uint32_t controllerKeys[MENU_KEY_MAX];

int get_menu_key_value(MenuKey key, int keyboard) {
	if (keyboard) {

		int i = 0;
		switch (key) {
			case MENU_TOGGLE:
				i = DIK_INSERT;
				break;
			case MENU_ACCEPT:
				i = DIK_RETURN;
				break;
			case MENU_BACK:
				i = DIK_ESCAPE;
				break;

			case MENU_UP:
				i = DIK_UPARROW;
				break;
			case MENU_DOWN:
				i = DIK_DOWNARROW;
				break;
			case MENU_LEFT:
				i = DIK_LEFTARROW;
				break;
			case MENU_RIGHT:
				i = DIK_RIGHTARROW;
				break;
		}
		return keys[i];
	}



	return controllerKeys[key];
}


int is_menu_key_pressed(MenuKey key, int keyboard) {
	return (get_menu_key_value(key, keyboard) == 2);
}

int is_menu_key_clicked(MenuKey key, int keyboard) {
	return get_menu_key_value(key, keyboard);
}

void GetDeviceStateHandleKeyboardInput(LPVOID lpvData) {
	BYTE* keysCurrent = lpvData;

	for (int i = 0; i < 256; i++) {

		if (keysCurrent[i]) {
			keys[i]++;
		}
		else {
			keys[i] = 0;
		}
	}

	
}

void read_and_update_controller_key_button(LPDIJOYSTATE2 joy, int index, MenuKey key) {
	int res = 0;
	if (joy->rgbButtons[index]) {
		controllerKeys[key]++;
	}
	else {
		controllerKeys[key] = 0;
	}
}


void read_and_update_controller_key_dpad(LPDIJOYSTATE2 joy, int angle, MenuKey key) {
	
	if (joy->rgdwPOV[0] == 0xFFFFFFFF)
		controllerKeys[key] = 0;
	else
		controllerKeys[key] = (joy->rgdwPOV[0] == angle) ? controllerKeys[key] + 1 : 0;
}


void GetDeviceStateHandleControllerInput(LPVOID lpvData) {
	LPDIJOYSTATE2 joy = lpvData;

	read_and_update_controller_key_button(joy, 1, MENU_ACCEPT);
	read_and_update_controller_key_button(joy, 2, MENU_BACK);
	read_and_update_controller_key_button(joy, 12, MENU_TOGGLE);



	read_and_update_controller_key_dpad(joy, 0, MENU_UP);
	read_and_update_controller_key_dpad(joy, 9000, MENU_RIGHT);
	read_and_update_controller_key_dpad(joy, 18000, MENU_DOWN);
	read_and_update_controller_key_dpad(joy, 27000, MENU_LEFT);

}

DWORD* g_TOD = (void*)0x0091E000;
void time_of_day_name_generator(debug_menu_entry *entry) {

	DWORD lastTOD = (DWORD)entry->data;
	DWORD currentTOD = *g_TOD;
	if (currentTOD == lastTOD) {
		return;
	}

	snprintf(entry->text, MAX_CHARS, "Time of Day: %d", currentTOD);
	lastTOD = currentTOD;
}

void time_of_day_handler(debug_menu_entry *entry, custom_key_type key, menu_handler_function original) {

	DWORD currentTOD = *g_TOD;
	switch (key) {
		case LEFT:
			us_lighting_switch_time_of_day(modulo(currentTOD - 1, 4));
			break;
		case RIGHT:
			us_lighting_switch_time_of_day(modulo(currentTOD + 1, 4));
			break;
	}
}

void menu_setup(int game_state, int keyboard) {

	//debug menu stuff
	if (is_menu_key_pressed(MENU_TOGGLE, keyboard) && (game_state == 6 || game_state == 7)) {


		if (debug_enabled && game_state == 7) {
			game_unpause(g_game_ptr);
			debug_enabled = !debug_enabled;
		}
		else if (!debug_enabled && game_state == 6) {
			game_pause(g_game_ptr);
			debug_enabled = !debug_enabled;
			current_menu = start_debug;
		}

		if (warp_menu->used_slots == 0) {

			debug_menu_entry poi = { "--- WARP TO POI ---", NORMAL, NULL };
			poi.data1 = (void*)1;
			add_debug_menu_entry(warp_menu, &poi);

			for (DWORD i = 0; i < *number_of_allocated_regions; i++) {
				region* cur_region = &(*all_regions)[i];
				char* region_name = region_get_name(cur_region);

				debug_menu_entry warp_entry = { "", NORMAL, cur_region };
				warp_entry.data1 = 0;
				strcpy(warp_entry.text, region_name);
				add_debug_menu_entry(warp_menu, &warp_entry);

				if (cur_region->variants >= 2) {
					debug_menu_entry variant_entry;
					memcpy(&variant_entry, &warp_entry, sizeof(debug_menu_entry));

					variant_entry.data1 = (void*)0xFFFFFFFF;

					variant_entry.entry_type = CUSTOM;
					variant_entry.custom_string_generator = district_variant_string_generator;
					variant_entry.custom_handler = NULL;
					add_debug_menu_entry(district_variants_menu, &variant_entry);
				}
			}
			qsort(warp_menu->entries, *number_of_allocated_regions, sizeof(debug_menu_entry), sort_warp_entries);
			qsort(district_variants_menu->entries, district_variants_menu->used_slots, sizeof(debug_menu_entry), sort_warp_entries);

		}


		if (options_menu->used_slots == 2) {
			BYTE* arr = *(BYTE**)0x96858C;
			debug_menu_entry render_fe = { "Render FE UI ", BOOLEAN_E,  &arr[4 + 0x90] };
			add_debug_menu_entry(options_menu, &render_fe);


			BYTE* flags = *(BYTE**)0x0096858C;
			debug_menu_entry live_in_glass_house = { "Live in Glass House ", BOOLEAN_E,  &flags[4 + 0x7A] };
			add_debug_menu_entry(options_menu, &live_in_glass_house);


			BYTE* god_mode = (void*)0x95A6A8;
			debug_menu_entry god_mode_entry = { "God Mode ", BOOLEAN_E,  &god_mode[0] };
			debug_menu_entry mega_god_mode = { "Mega God Mode ", BOOLEAN_E,  &god_mode[1] };
			debug_menu_entry ultra_god_mode = { "Ultra God Mode ", BOOLEAN_E,  &god_mode[2] };

			add_debug_menu_entry(options_menu, &god_mode_entry);
			add_debug_menu_entry(options_menu, &mega_god_mode);
			add_debug_menu_entry(options_menu, &ultra_god_mode);

			debug_menu_entry time_of_day = {
				.text = "Time of Day",
				.entry_type = CUSTOM,
				.custom_string_generator = time_of_day_name_generator,
				.custom_handler = time_of_day_handler,
				.data = (void*)0xFFFFFFFF
			};
			add_debug_menu_entry(options_menu, &time_of_day);
		}
	}
}

void menu_input_handler(int keyboard, int SCROLL_SPEED) {
	if (is_menu_key_clicked(MENU_DOWN, keyboard)) {


		int key_val = get_menu_key_value(MENU_DOWN, keyboard);
		if (key_val == 1) {
			menu_go_down();
		}
		else if ((key_val >= SCROLL_SPEED) && (key_val % SCROLL_SPEED == 0)) {
			menu_go_down();
		}
	}
	else if (is_menu_key_clicked(MENU_UP, keyboard)) {

		int key_val = get_menu_key_value(MENU_UP, keyboard);
		if (key_val == 1) {
			menu_go_up();
		}
		else if ((key_val >= SCROLL_SPEED) && (key_val % SCROLL_SPEED == 0)) {
			menu_go_up();
		}
	}
	else if (is_menu_key_pressed(MENU_ACCEPT, keyboard)) {
		current_menu->handler(&current_menu->entries[current_menu->window_start + current_menu->cur_index], ENTER);
	}
	else if (is_menu_key_pressed(MENU_BACK, keyboard)) {
		current_menu->go_back();
	}
	else if (is_menu_key_pressed(MENU_LEFT, keyboard) || is_menu_key_pressed(MENU_RIGHT, keyboard)) {

		debug_menu_entry* cur = &current_menu->entries[current_menu->window_start + current_menu->cur_index];
		custom_key_type pressed = (is_menu_key_pressed(MENU_LEFT, keyboard) ? LEFT : RIGHT);

		switch (cur->entry_type) {
			case BOOLEAN_E:
				current_menu->handler(cur, pressed);
				break;
			case CUSTOM:
				if (cur->custom_handler != NULL) {
					cur->custom_handler(cur, pressed, current_menu->handler);
				}
				else {
					current_menu->handler(cur, pressed);
				}
		}
	}
}

HRESULT __stdcall GetDeviceStateHook(IDirectInputDevice8* this, DWORD cbData, LPVOID lpvData) {


	HRESULT res = GetDeviceStateOriginal(this, cbData, lpvData);


	//printf("cbData %d %d %d\n", cbData, sizeof(DIJOYSTATE), sizeof(DIJOYSTATE2));


	
	//keyboard time babyyy
	if (cbData == 256 || cbData == sizeof(DIJOYSTATE2)) {

		
		if (cbData == 256)
			GetDeviceStateHandleKeyboardInput(lpvData);
		else if (cbData == sizeof(DIJOYSTATE2))
			GetDeviceStateHandleControllerInput(lpvData);

		int game_state = 0;
		if (g_game_ptr)
			game_state = game_get_cur_state(g_game_ptr);

		//printf("INSERT %d %d %c\n", keys[DIK_INSERT], game_state, debug_enabled ? 'y' : 'n');

		int keyboard = cbData == 256;
		menu_setup(game_state, keyboard);

		if (debug_enabled) {
			menu_input_handler(keyboard, 5);
		}

	}


	if (debug_enabled) {
		memset(lpvData, 0, cbData);
	}



	//printf("Device State called %08X %d\n", this, cbData);

	return res;
}

typedef HRESULT(__stdcall* GetDeviceData_ptr)(IDirectInputDevice8*, DWORD, LPDIDEVICEOBJECTDATA, LPDWORD, DWORD);
GetDeviceData_ptr GetDeviceDataOriginal = NULL;

HRESULT __stdcall GetDeviceDataHook(IDirectInputDevice8* this, DWORD cbObjectData, LPDIDEVICEOBJECTDATA rgdod, LPDWORD pdwInOut, DWORD dwFlags) {

	HRESULT res = GetDeviceDataOriginal(this, cbObjectData, rgdod, pdwInOut, dwFlags);

	printf("data\n");
	if (res == DI_OK) {

		printf("All gud\n");
		for (DWORD i = 0; i < *pdwInOut; i++) {


			if (LOBYTE(rgdod[i].dwData) > 0) {

				if (rgdod[i].dwOfs == DIK_ESCAPE) {

					printf("Pressed escaped\n");
					__debugbreak();
				}
			}
		}
	}
	//printf("Device Data called %08X\n", this);

	return res;
}



typedef HRESULT(__stdcall* IDirectInput8CreateDevice_ptr)(IDirectInput8W*, const GUID*, LPDIRECTINPUTDEVICE8W*, LPUNKNOWN);
IDirectInput8CreateDevice_ptr createDeviceOriginal = NULL;

HRESULT  __stdcall IDirectInput8CreateDeviceHook(IDirectInput8W* this, const GUID* guid, LPDIRECTINPUTDEVICE8W* device, LPUNKNOWN unk) {

	//printf("CreateDevice %d %d %d %d %d %d %d\n", *guid, GUID_SysMouse, GUID_SysKeyboard, GUID_SysKeyboardEm, GUID_SysKeyboardEm2, GUID_SysMouseEm, GUID_SysMouseEm2);
	printf("Guid = {%08lX-%04hX-%04hX-%02hhX%02hhX-%02hhX%02hhX%02hhX%02hhX%02hhX%02hhX}\n",
		guid->Data1, guid->Data2, guid->Data3,
		guid->Data4[0], guid->Data4[1], guid->Data4[2], guid->Data4[3],
		guid->Data4[4], guid->Data4[5], guid->Data4[6], guid->Data4[7]);

	HRESULT res = createDeviceOriginal(this, guid, device, unk);


	if (IsEqualGUID(&GUID_SysMouse, guid))
		return res; // ignore mouse

	if (IsEqualGUID(&GUID_SysKeyboard, guid))
		puts("Found the keyboard");
	else
		puts("Hooking something different...maybe a controller");

	DWORD* vtbl = (DWORD*)(*device)->lpVtbl;
	if (!GetDeviceStateOriginal) {
		GetDeviceStateOriginal = (void*)vtbl[9];
		vtbl[9] = (DWORD)GetDeviceStateHook;
	}

	if (!GetDeviceDataOriginal) {
		GetDeviceDataOriginal = (void*)vtbl[10];
		vtbl[10] = (DWORD)GetDeviceDataHook;
	}

	return res;
}

typedef HRESULT(__stdcall* IDirectInput8Release_ptr)(IDirectInput8W*);
IDirectInput8Release_ptr releaseDeviceOriginal = NULL;

HRESULT  __stdcall IDirectInput8ReleaseHook(IDirectInput8W* this) {

	printf("Release\n");

	return releaseDeviceOriginal(this);
}


typedef HRESULT(__stdcall* DirectInput8Create_ptr)(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter);
HRESULT __stdcall HookDirectInput8Create(HINSTANCE hinst, DWORD dwVersion, REFIID riidltf, LPVOID* ppvOut, LPUNKNOWN punkOuter)
{
	DirectInput8Create_ptr caller = *(void**)0x00987944;
	HRESULT res = caller(hinst, dwVersion, riidltf, ppvOut, punkOuter);


	IDirectInput8** iDir = (void*)ppvOut;
	printf("it's me mario %08X %08X\n", (DWORD)ppvOut, (DWORD)(*iDir)->lpVtbl);


	DWORD* vtbl = (DWORD*)(*iDir)->lpVtbl;
	if (!createDeviceOriginal) {
		createDeviceOriginal = (void*)vtbl[3];
		vtbl[3] = (DWORD)IDirectInput8CreateDeviceHook;
	}


	return res;
}


DWORD hookDirectInputAddress = (DWORD)HookDirectInput8Create;


typedef int(__fastcall* game_handle_game_states_ptr)(void* this, void* edx, void* a2);
game_handle_game_states_ptr game_handle_game_states_original = (void*)0x0055D510;

int __fastcall game_handle_game_states(void* this, void* edx, void* a2) {

	if (!g_game_ptr) {
		g_game_ptr = this;
	}

	if (changing_model) {


		changing_model--;

		if (!changing_model) {
			mString str;
			mString_constructor(&str, NULL, current_costume);
			world_dynamics_system_add_player(*(DWORD**)g_world_ptr, NULL, &str);
			mString_finalize(&str, NULL, 0);
			game_unpause(g_game_ptr);
		}
	}

	/*
	if (game_get_cur_state(this) == 14)
		__debugbreak();
		*/


		//printf("Current state %d %08X\n", game_get_cur_state(this), g_game_ptr);

	return game_handle_game_states_original(this, edx, a2);
}

typedef void* (__fastcall* sub_41F9D0_ptr)(char* this, void* edx, const char* a2, signed int a3);
sub_41F9D0_ptr sub_41F9D0 = (void*)0x41F9D0;


void* __fastcall sub_41F9D0_hook(char* this, void* edx, const char* a2, signed int a3) {

	//printf("mString:%s\n", a2);


	return sub_41F9D0(this, edx, a2, a3);
}

typedef DWORD(__fastcall* ai_hero_base_state_check_transition_ptr)(DWORD* this, void* edx, DWORD* a2, int a3);
ai_hero_base_state_check_transition_ptr ai_hero_base_state_check_transition = (void*)0x00478D80;

DWORD __fastcall ai_hero_base_state_check_transition_hook(DWORD* this, void* edx, DWORD* a2, int a3) {
	ai_current_player = this;
	return ai_hero_base_state_check_transition(this, edx, a2, a3);
}


typedef DWORD* (__fastcall* get_info_node_ptr)(void* this, void* edx, int a2, char a3);
get_info_node_ptr get_info_node = (void*)0x006A3390;

DWORD* __fastcall get_info_node_hook(void* this, void* edx, int a2, char a3) {

	DWORD* res = get_info_node(this, edx, a2, a3);

	fancy_player_ptr = res;
	return res;
}


typedef int (_fastcall* resource_pack_streamer_load_internal_ptr)(void* this, void* edx, char* str, int a3, int a4, int a5);
resource_pack_streamer_load_internal_ptr resource_pack_streamer_load_internal = (void*)0x0054C580;



uint8_t __fastcall os_developer_options(BYTE *this, void *edx, int flag) {

	char** flag_list = (void*)0x936420;
	char* flag_text = flag_list[flag];
		
	uint8_t res = this[flag + 4];

	if (flag == 0x90) {
		printf("Game wants to know about: %d (%s) -> %d\n", flag, flag_text, res);
		__debugbreak();
	}
	
	
	//this[5 + 4] = 1;
	
	return res;
}

void dump_vtable(const char* name, DWORD* vtable) {
	printf("%s|%08X|%08X\n", name, vtable[0], vtable[1]);
}

void hook_slf_vtable(void* decons, void* action, DWORD* vtable) {
	vtable[0] = (DWORD)decons;
	vtable[1] = (DWORD)action;
}

void hook_slf_vtables() {

	hook_slf_vtable(slf_deconstructor_abs_delay_num, slf_action_abs_delay_num, (void*)0x89a724);
	hook_slf_vtable(slf_deconstructor_acos_num, slf_action_acos_num, (void*)0x89a91c);
	hook_slf_vtable(slf_deconstructor_add_2d_debug_str_vector3d_vector3d_num_str, slf_action_add_2d_debug_str_vector3d_vector3d_num_str, (void*)0x89a860);
	hook_slf_vtable(slf_deconstructor_add_2d_debug_str_vector3d_vector3d_num_str_num, slf_action_add_2d_debug_str_vector3d_vector3d_num_str_num, (void*)0x89a858);
	hook_slf_vtable(slf_deconstructor_add_3d_debug_str_vector3d_vector3d_num_str, slf_action_add_3d_debug_str_vector3d_vector3d_num_str, (void*)0x89a850);
	hook_slf_vtable(slf_deconstructor_add_civilian_info_vector3d_num_num_num, slf_action_add_civilian_info_vector3d_num_num_num, (void*)0x89c5bc);
	hook_slf_vtable(slf_deconstructor_add_civilian_info_entity_entity_num_num_num, slf_action_add_civilian_info_entity_entity_num_num_num, (void*)0x89c5cc);
	hook_slf_vtable(slf_deconstructor_add_debug_cyl_vector3d_vector3d_num, slf_action_add_debug_cyl_vector3d_vector3d_num, (void*)0x89a774);
	hook_slf_vtable(slf_deconstructor_add_debug_cyl_vector3d_vector3d_num_vector3d_num, slf_action_add_debug_cyl_vector3d_vector3d_num_vector3d_num, (void*)0x89a77c);
	hook_slf_vtable(slf_deconstructor_add_debug_line_vector3d_vector3d, slf_action_add_debug_line_vector3d_vector3d, (void*)0x89a764);
	hook_slf_vtable(slf_deconstructor_add_debug_line_vector3d_vector3d_vector3d_num, slf_action_add_debug_line_vector3d_vector3d_vector3d_num, (void*)0x89a76c);
	hook_slf_vtable(slf_deconstructor_add_debug_sphere_vector3d_num, slf_action_add_debug_sphere_vector3d_num, (void*)0x89a754);
	hook_slf_vtable(slf_deconstructor_add_debug_sphere_vector3d_num_vector3d_num, slf_action_add_debug_sphere_vector3d_num_vector3d_num, (void*)0x89a75c);
	hook_slf_vtable(slf_deconstructor_add_glass_house_str, slf_action_add_glass_house_str, (void*)0x89a548);
	hook_slf_vtable(slf_deconstructor_add_glass_house_str_num, slf_action_add_glass_house_str_num, (void*)0x89a550);
	hook_slf_vtable(slf_deconstructor_add_glass_house_str_num_vector3d, slf_action_add_glass_house_str_num_vector3d, (void*)0x89a560);
	hook_slf_vtable(slf_deconstructor_add_glass_house_str_vector3d, slf_action_add_glass_house_str_vector3d, (void*)0x89a558);
	hook_slf_vtable(slf_deconstructor_add_to_console_str, slf_action_add_to_console_str, (void*)0x89a834);
	hook_slf_vtable(slf_deconstructor_add_traffic_model_num_str, slf_action_add_traffic_model_num_str, (void*)0x89c5a4);
	hook_slf_vtable(slf_deconstructor_allow_suspend_thread_num, slf_action_allow_suspend_thread_num, (void*)0x89a594);
	hook_slf_vtable(slf_deconstructor_angle_between_vector3d_vector3d, slf_action_angle_between_vector3d_vector3d, (void*)0x89ba50);
	hook_slf_vtable(slf_deconstructor_apply_donut_damage_vector3d_num_num_num_num_num, slf_action_apply_donut_damage_vector3d_num_num_num_num_num, (void*)0x89a804);
	hook_slf_vtable(slf_deconstructor_apply_radius_damage_vector3d_num_num_num_num, slf_action_apply_radius_damage_vector3d_num_num_num_num, (void*)0x89a7fc);
	hook_slf_vtable(slf_deconstructor_apply_radius_subdue_vector3d_num_num_num_num, slf_action_apply_radius_subdue_vector3d_num_num_num_num, (void*)0x89a80c);
	hook_slf_vtable(slf_deconstructor_assert_num_str, slf_action_assert_num_str, (void*)0x89a518);
	hook_slf_vtable(slf_deconstructor_attach_decal_str_vector3d_num_vector3d_entity, slf_action_attach_decal_str_vector3d_num_vector3d_entity, (void*)0x89a9fc);
	hook_slf_vtable(slf_deconstructor_begin_screen_recording_str_num, slf_action_begin_screen_recording_str_num, (void*)0x89b7b0);
	hook_slf_vtable(slf_deconstructor_blackscreen_off_num, slf_action_blackscreen_off_num, (void*)0x89bcac);
	hook_slf_vtable(slf_deconstructor_blackscreen_on_num, slf_action_blackscreen_on_num, (void*)0x89bca0);
	hook_slf_vtable(slf_deconstructor_bring_up_dialog_box_num_num_elip, slf_action_bring_up_dialog_box_num_num_elip, (void*)0x89bc28);
	hook_slf_vtable(slf_deconstructor_bring_up_dialog_box_debug_str_num_str, slf_action_bring_up_dialog_box_debug_str_num_str, (void*)0x89bc38);
	hook_slf_vtable(slf_deconstructor_bring_up_dialog_box_title_num_num_num_elip, slf_action_bring_up_dialog_box_title_num_num_num_elip, (void*)0x89bc30);
	hook_slf_vtable(slf_deconstructor_bring_up_medal_award_box_num, slf_action_bring_up_medal_award_box_num, (void*)0x89bb10);
	hook_slf_vtable(slf_deconstructor_bring_up_race_announcer, slf_action_bring_up_race_announcer, (void*)0x89bb08);
	hook_slf_vtable(slf_deconstructor_calc_launch_vector_vector3d_vector3d_num_entity, slf_action_calc_launch_vector_vector3d_vector3d_num_entity, (void*)0x89a98c);
	hook_slf_vtable(slf_deconstructor_can_load_pack_str, slf_action_can_load_pack_str, (void*)0x89c3f4);
	hook_slf_vtable(slf_deconstructor_chase_cam, slf_action_chase_cam, (void*)0x89af04);
	hook_slf_vtable(slf_deconstructor_clear_all_grenades, slf_action_clear_all_grenades, (void*)0x89a95c);
	hook_slf_vtable(slf_deconstructor_clear_civilians_within_radius_vector3d_num, slf_action_clear_civilians_within_radius_vector3d_num, (void*)0x89c5e4);
	hook_slf_vtable(slf_deconstructor_clear_controls, slf_action_clear_controls, (void*)0x89bd48);
	hook_slf_vtable(slf_deconstructor_clear_debug_all, slf_action_clear_debug_all, (void*)0x89a79c);
	hook_slf_vtable(slf_deconstructor_clear_debug_cyls, slf_action_clear_debug_cyls, (void*)0x89a794);
	hook_slf_vtable(slf_deconstructor_clear_debug_lines, slf_action_clear_debug_lines, (void*)0x89a78c);
	hook_slf_vtable(slf_deconstructor_clear_debug_spheres, slf_action_clear_debug_spheres, (void*)0x89a784);
	hook_slf_vtable(slf_deconstructor_clear_screen, slf_action_clear_screen, (void*)0x89a944);
	hook_slf_vtable(slf_deconstructor_clear_traffic_within_radius_vector3d_num, slf_action_clear_traffic_within_radius_vector3d_num, (void*)0x89c5dc);
	hook_slf_vtable(slf_deconstructor_col_check_vector3d_vector3d_num, slf_action_col_check_vector3d_vector3d_num, (void*)0x89a868);
	hook_slf_vtable(slf_deconstructor_console_exec_str, slf_action_console_exec_str, (void*)0x89a83c);
	hook_slf_vtable(slf_deconstructor_copy_vector3d_list_vector3d_list_vector3d_list, slf_action_copy_vector3d_list_vector3d_list_vector3d_list, (void*)0x89bed4);
	hook_slf_vtable(slf_deconstructor_cos_num, slf_action_cos_num, (void*)0x89a90c);
	hook_slf_vtable(slf_deconstructor_create_beam, slf_action_create_beam, (void*)0x89abb4);
	hook_slf_vtable(slf_deconstructor_create_credits, slf_action_create_credits, (void*)0x89bae8);
	hook_slf_vtable(slf_deconstructor_create_cut_scene_str, slf_action_create_cut_scene_str, (void*)0x89b7c0);
	//hook_slf_vtable(slf_deconstructor_create_debug_menu_entry_str, slf_action_create_debug_menu_entry_str, (void*)0x89c704);
	//hook_slf_vtable(slf_deconstructor_create_debug_menu_entry_str_str, slf_action_create_debug_menu_entry_str_str, (void*)0x89c70c);
	hook_slf_vtable(slf_deconstructor_create_decal_str_vector3d_num_vector3d, slf_action_create_decal_str_vector3d_num_vector3d, (void*)0x89a9f4);
	hook_slf_vtable(slf_deconstructor_create_entity_str, slf_action_create_entity_str, (void*)0x89af0c);
	hook_slf_vtable(slf_deconstructor_create_entity_str_str, slf_action_create_entity_str_str, (void*)0x89af14);
	hook_slf_vtable(slf_deconstructor_create_entity_in_hero_region_str, slf_action_create_entity_in_hero_region_str, (void*)0x89af2c);
	hook_slf_vtable(slf_deconstructor_create_entity_list, slf_action_create_entity_list, (void*)0x89bfcc);
	hook_slf_vtable(slf_deconstructor_create_entity_tracker_entity, slf_action_create_entity_tracker_entity, (void*)0x89c594);
	hook_slf_vtable(slf_deconstructor_create_item_str, slf_action_create_item_str, (void*)0x89b6b4);
	hook_slf_vtable(slf_deconstructor_create_line_info_vector3d_vector3d, slf_action_create_line_info_vector3d_vector3d, (void*)0x89b708);
	hook_slf_vtable(slf_deconstructor_create_lofi_stereo_sound_inst_str, slf_action_create_lofi_stereo_sound_inst_str, (void*)0x89b818);
	hook_slf_vtable(slf_deconstructor_create_num_list, slf_action_create_num_list, (void*)0x89bf54);
	hook_slf_vtable(slf_deconstructor_create_pfx_str, slf_action_create_pfx_str, (void*)0x89c904);
	hook_slf_vtable(slf_deconstructor_create_pfx_str_vector3d, slf_action_create_pfx_str_vector3d, (void*)0x89c90c);
	hook_slf_vtable(slf_deconstructor_create_polytube, slf_action_create_polytube, (void*)0x89c228);
	hook_slf_vtable(slf_deconstructor_create_polytube_str, slf_action_create_polytube_str, (void*)0x89c230);
	//hook_slf_vtable(slf_deconstructor_create_progression_menu_entry_str_str, slf_action_create_progression_menu_entry_str_str, (void*)0x89c714);
	hook_slf_vtable(slf_deconstructor_create_sound_inst, slf_action_create_sound_inst, (void*)0x89b7f8);
	hook_slf_vtable(slf_deconstructor_create_sound_inst_str, slf_action_create_sound_inst_str, (void*)0x89b800);
	hook_slf_vtable(slf_deconstructor_create_stompable_music_sound_inst_str, slf_action_create_stompable_music_sound_inst_str, (void*)0x89b808);
	hook_slf_vtable(slf_deconstructor_create_str_list, slf_action_create_str_list, (void*)0x89c044);
	hook_slf_vtable(slf_deconstructor_create_taunt_entry_entity_str_num, slf_action_create_taunt_entry_entity_str_num, (void*)0x89c63c);
	hook_slf_vtable(slf_deconstructor_create_taunt_exchange_entity_entity_num_num_num_num_elip, slf_action_create_taunt_exchange_entity_entity_num_num_num_num_elip, (void*)0x89c6b4);
	hook_slf_vtable(slf_deconstructor_create_taunt_exchange_list, slf_action_create_taunt_exchange_list, (void*)0x89c0dc);
	hook_slf_vtable(slf_deconstructor_create_threat_assessment_meter, slf_action_create_threat_assessment_meter, (void*)0x89c6cc);
	hook_slf_vtable(slf_deconstructor_create_time_limited_entity_str_num, slf_action_create_time_limited_entity_str_num, (void*)0x89af3c);
	hook_slf_vtable(slf_deconstructor_create_trigger_entity_num, slf_action_create_trigger_entity_num, (void*)0x89b970);
	hook_slf_vtable(slf_deconstructor_create_trigger_str_vector3d_num, slf_action_create_trigger_str_vector3d_num, (void*)0x89b968);
	hook_slf_vtable(slf_deconstructor_create_trigger_vector3d_num, slf_action_create_trigger_vector3d_num, (void*)0x89b960);
	hook_slf_vtable(slf_deconstructor_create_unstompable_script_cutscene_sound_inst_str, slf_action_create_unstompable_script_cutscene_sound_inst_str, (void*)0x89b810);
	hook_slf_vtable(slf_deconstructor_create_vector3d_list, slf_action_create_vector3d_list, (void*)0x89becc);
	hook_slf_vtable(slf_deconstructor_cross_vector3d_vector3d, slf_action_cross_vector3d_vector3d, (void*)0x89ba38);
	hook_slf_vtable(slf_deconstructor_debug_breakpoint, slf_action_debug_breakpoint, (void*)0x89a510);
	hook_slf_vtable(slf_deconstructor_debug_print_num_str, slf_action_debug_print_num_str, (void*)0x89a528);
	hook_slf_vtable(slf_deconstructor_debug_print_num_vector3d_str, slf_action_debug_print_num_vector3d_str, (void*)0x89a530);
	hook_slf_vtable(slf_deconstructor_debug_print_str, slf_action_debug_print_str, (void*)0x89a520);
	hook_slf_vtable(slf_deconstructor_debug_print_set_background_color_vector3d, slf_action_debug_print_set_background_color_vector3d, (void*)0x89a538);
	hook_slf_vtable(slf_deconstructor_delay_num, slf_action_delay_num, (void*)0x89a71c);
	hook_slf_vtable(slf_deconstructor_destroy_credits, slf_action_destroy_credits, (void*)0x89baf0);
	//hook_slf_vtable(slf_deconstructor_destroy_debug_menu_entry_debug_menu_entry, slf_action_destroy_debug_menu_entry_debug_menu_entry, (void*)0x89c71c);
	hook_slf_vtable(slf_deconstructor_destroy_entity_entity, slf_action_destroy_entity_entity, (void*)0x89af34);
	hook_slf_vtable(slf_deconstructor_destroy_entity_list_entity_list, slf_action_destroy_entity_list_entity_list, (void*)0x89bfd4);
	hook_slf_vtable(slf_deconstructor_destroy_entity_tracker_entity_tracker, slf_action_destroy_entity_tracker_entity_tracker, (void*)0x89c59c);
	hook_slf_vtable(slf_deconstructor_destroy_line_info_line_info, slf_action_destroy_line_info_line_info, (void*)0x89b710);
	hook_slf_vtable(slf_deconstructor_destroy_num_list_num_list, slf_action_destroy_num_list_num_list, (void*)0x89bf5c);
	hook_slf_vtable(slf_deconstructor_destroy_pfx_pfx, slf_action_destroy_pfx_pfx, (void*)0x89c914);
	hook_slf_vtable(slf_deconstructor_destroy_str_list_str_list, slf_action_destroy_str_list_str_list, (void*)0x89c04c);
	hook_slf_vtable(slf_deconstructor_destroy_taunt_entry_taunt_entry, slf_action_destroy_taunt_entry_taunt_entry, (void*)0x89c644);
	hook_slf_vtable(slf_deconstructor_destroy_taunt_exchange_taunt_exchange, slf_action_destroy_taunt_exchange_taunt_exchange, (void*)0x89c6bc);
	hook_slf_vtable(slf_deconstructor_destroy_taunt_exchange_list_taunt_exchange_list, slf_action_destroy_taunt_exchange_list_taunt_exchange_list, (void*)0x89c0e4);
	hook_slf_vtable(slf_deconstructor_destroy_threat_assessment_meter_tam, slf_action_destroy_threat_assessment_meter_tam, (void*)0x89c6d4);
	hook_slf_vtable(slf_deconstructor_destroy_trigger_trigger, slf_action_destroy_trigger_trigger, (void*)0x89b978);
	hook_slf_vtable(slf_deconstructor_destroy_vector3d_list_vector3d_list, slf_action_destroy_vector3d_list_vector3d_list, (void*)0x89bedc);
	hook_slf_vtable(slf_deconstructor_dilated_delay_num, slf_action_dilated_delay_num, (void*)0x89a72c);
	hook_slf_vtable(slf_deconstructor_disable_marky_cam_num, slf_action_disable_marky_cam_num, (void*)0x89a5f4);
	hook_slf_vtable(slf_deconstructor_disable_nearby_occlusion_only_obb_vector3d, slf_action_disable_nearby_occlusion_only_obb_vector3d, (void*)0x89a5e4);
	hook_slf_vtable(slf_deconstructor_disable_player_shadows, slf_action_disable_player_shadows, (void*)0x89a614);
	hook_slf_vtable(slf_deconstructor_disable_subtitles, slf_action_disable_subtitles, (void*)0x89a93c);
	hook_slf_vtable(slf_deconstructor_disable_vibrator, slf_action_disable_vibrator, (void*)0x89a7dc);
	hook_slf_vtable(slf_deconstructor_disable_zoom_map_num, slf_action_disable_zoom_map_num, (void*)0x89bbf0);
	hook_slf_vtable(slf_deconstructor_distance3d_vector3d_vector3d, slf_action_distance3d_vector3d_vector3d, (void*)0x89ba48);
	hook_slf_vtable(slf_deconstructor_distance_chase_widget_set_pos_num, slf_action_distance_chase_widget_set_pos_num, (void*)0x89bb88);
	hook_slf_vtable(slf_deconstructor_distance_chase_widget_turn_off, slf_action_distance_chase_widget_turn_off, (void*)0x89bb80);
	hook_slf_vtable(slf_deconstructor_distance_chase_widget_turn_on_num_num, slf_action_distance_chase_widget_turn_on_num_num, (void*)0x89bb78);
	hook_slf_vtable(slf_deconstructor_distance_race_widget_set_boss_pos_num, slf_action_distance_race_widget_set_boss_pos_num, (void*)0x89bba8);
	hook_slf_vtable(slf_deconstructor_distance_race_widget_set_hero_pos_num, slf_action_distance_race_widget_set_hero_pos_num, (void*)0x89bba0);
	hook_slf_vtable(slf_deconstructor_distance_race_widget_set_types_num_num, slf_action_distance_race_widget_set_types_num_num, (void*)0x89bbb0);
	hook_slf_vtable(slf_deconstructor_distance_race_widget_turn_off, slf_action_distance_race_widget_turn_off, (void*)0x89bb98);
	hook_slf_vtable(slf_deconstructor_distance_race_widget_turn_on, slf_action_distance_race_widget_turn_on, (void*)0x89bb90);
	hook_slf_vtable(slf_deconstructor_district_id_str, slf_action_district_id_str, (void*)0x89c47c);
	hook_slf_vtable(slf_deconstructor_district_name_num, slf_action_district_name_num, (void*)0x89c484);
	hook_slf_vtable(slf_deconstructor_dot_vector3d_vector3d, slf_action_dot_vector3d_vector3d, (void*)0x89ba30);
	hook_slf_vtable(slf_deconstructor_dump_searchable_region_list_str, slf_action_dump_searchable_region_list_str, (void*)0x89a994);
	hook_slf_vtable(slf_deconstructor_enable_ai_num, slf_action_enable_ai_num, (void*)0x89a6cc);
	hook_slf_vtable(slf_deconstructor_enable_civilians_num, slf_action_enable_civilians_num, (void*)0x89c5ec);
	hook_slf_vtable(slf_deconstructor_enable_controls_num, slf_action_enable_controls_num, (void*)0x89bd40);
	hook_slf_vtable(slf_deconstructor_enable_entity_fading_num, slf_action_enable_entity_fading_num, (void*)0x89b05c);
	hook_slf_vtable(slf_deconstructor_enable_interface_num, slf_action_enable_interface_num, (void*)0x89a6c4);
	hook_slf_vtable(slf_deconstructor_enable_marky_cam_num, slf_action_enable_marky_cam_num, (void*)0x89a5bc);
	hook_slf_vtable(slf_deconstructor_enable_mini_map_num, slf_action_enable_mini_map_num, (void*)0x89bbe8);
	hook_slf_vtable(slf_deconstructor_enable_nearby_occlusion_only_obb_vector3d, slf_action_enable_nearby_occlusion_only_obb_vector3d, (void*)0x89a5dc);
	hook_slf_vtable(slf_deconstructor_enable_obb_vector3d_num, slf_action_enable_obb_vector3d_num, (void*)0x89a588);
	hook_slf_vtable(slf_deconstructor_enable_pause_num, slf_action_enable_pause_num, (void*)0x89a6ac);
	hook_slf_vtable(slf_deconstructor_enable_physics_num, slf_action_enable_physics_num, (void*)0x89a6dc);
	hook_slf_vtable(slf_deconstructor_enable_player_shadows, slf_action_enable_player_shadows, (void*)0x89a61c);
	hook_slf_vtable(slf_deconstructor_enable_pois_num, slf_action_enable_pois_num, (void*)0x89a6ec);
	hook_slf_vtable(slf_deconstructor_enable_quad_path_connector_district_num_district_num_num, slf_action_enable_quad_path_connector_district_num_district_num_num, (void*)0x89a578);
	hook_slf_vtable(slf_deconstructor_enable_subtitles, slf_action_enable_subtitles, (void*)0x89a934);
	hook_slf_vtable(slf_deconstructor_enable_tokens_of_type_num_num, slf_action_enable_tokens_of_type_num_num, (void*)0x89b54c);
	hook_slf_vtable(slf_deconstructor_enable_traffic_num, slf_action_enable_traffic_num, (void*)0x89c5fc);
	hook_slf_vtable(slf_deconstructor_enable_user_camera_num, slf_action_enable_user_camera_num, (void*)0x89a5d4);
	hook_slf_vtable(slf_deconstructor_enable_vibrator, slf_action_enable_vibrator, (void*)0x89a7e4);
	hook_slf_vtable(slf_deconstructor_end_current_patrol, slf_action_end_current_patrol, (void*)0x89c4fc);
	hook_slf_vtable(slf_deconstructor_end_cut_scenes, slf_action_end_cut_scenes, (void*)0x89b7c8);
	hook_slf_vtable(slf_deconstructor_end_screen_recording, slf_action_end_screen_recording, (void*)0x89b7b8);
	hook_slf_vtable(slf_deconstructor_entity_col_check_entity_entity, slf_action_entity_col_check_entity_entity, (void*)0x89a88c);
	hook_slf_vtable(slf_deconstructor_entity_exists_str, slf_action_entity_exists_str, (void*)0x89af24);
	hook_slf_vtable(slf_deconstructor_entity_get_entity_tracker_entity, slf_action_entity_get_entity_tracker_entity, (void*)0x89b034);
	hook_slf_vtable(slf_deconstructor_entity_has_entity_tracker_entity, slf_action_entity_has_entity_tracker_entity, (void*)0x89b02c);
	hook_slf_vtable(slf_deconstructor_exit_water_entity, slf_action_exit_water_entity, (void*)0x89a604);
	hook_slf_vtable(slf_deconstructor_find_closest_point_on_a_path_to_point_vector3d, slf_action_find_closest_point_on_a_path_to_point_vector3d, (void*)0x89a570);
	hook_slf_vtable(slf_deconstructor_find_district_for_point_vector3d, slf_action_find_district_for_point_vector3d, (void*)0x89a81c);
	hook_slf_vtable(slf_deconstructor_find_entities_in_radius_entity_list_vector3d_num_num, slf_action_find_entities_in_radius_entity_list_vector3d_num_num, (void*)0x89b46c);
	hook_slf_vtable(slf_deconstructor_find_entity_str, slf_action_find_entity_str, (void*)0x89af1c);
	hook_slf_vtable(slf_deconstructor_find_innermost_district_vector3d, slf_action_find_innermost_district_vector3d, (void*)0x89a824);
	hook_slf_vtable(slf_deconstructor_find_outermost_district_vector3d, slf_action_find_outermost_district_vector3d, (void*)0x89a82c);
	hook_slf_vtable(slf_deconstructor_find_trigger_entity, slf_action_find_trigger_entity, (void*)0x89b950);
	hook_slf_vtable(slf_deconstructor_find_trigger_str, slf_action_find_trigger_str, (void*)0x89b948);
	hook_slf_vtable(slf_deconstructor_find_trigger_in_district_district_str, slf_action_find_trigger_in_district_district_str, (void*)0x89b958);
	hook_slf_vtable(slf_deconstructor_float_random_num, slf_action_float_random_num, (void*)0x89a74c);
	hook_slf_vtable(slf_deconstructor_force_mission_district_str_num, slf_action_force_mission_district_str_num, (void*)0x89c3b4);
	hook_slf_vtable(slf_deconstructor_force_streamer_refresh, slf_action_force_streamer_refresh, (void*)0x89c4ac);
	hook_slf_vtable(slf_deconstructor_format_time_string_num, slf_action_format_time_string_num, (void*)0x89bc74);
	hook_slf_vtable(slf_deconstructor_freeze_hero_num, slf_action_freeze_hero_num, (void*)0x89a5fc);
	hook_slf_vtable(slf_deconstructor_game_ini_get_flag_str, slf_action_game_ini_get_flag_str, (void*)0x89a97c);
	hook_slf_vtable(slf_deconstructor_game_time_advance_num_num, slf_action_game_time_advance_num_num, (void*)0x89c4dc);
	hook_slf_vtable(slf_deconstructor_get_all_execs_thread_count_str, slf_action_get_all_execs_thread_count_str, (void*)0x89a9ec);
	hook_slf_vtable(slf_deconstructor_get_all_instances_thread_count_str, slf_action_get_all_instances_thread_count_str, (void*)0x89a9e4);
	hook_slf_vtable(slf_deconstructor_get_attacker_entity, slf_action_get_attacker_entity, (void*)0x89aa24);
	hook_slf_vtable(slf_deconstructor_get_attacker_member, slf_action_get_attacker_member, (void*)0x89aa2c);
	hook_slf_vtable(slf_deconstructor_get_available_stack_size, slf_action_get_available_stack_size, (void*)0x89c4ec);
	hook_slf_vtable(slf_deconstructor_get_character_packname_list, slf_action_get_character_packname_list, (void*)0x89c354);
	hook_slf_vtable(slf_deconstructor_get_closest_point_on_lane_with_facing_num_vector3d_vector3d_list, slf_action_get_closest_point_on_lane_with_facing_num_vector3d_vector3d_list, (void*)0x89c61c);
	hook_slf_vtable(slf_deconstructor_get_col_hit_ent, slf_action_get_col_hit_ent, (void*)0x89a884);
	hook_slf_vtable(slf_deconstructor_get_col_hit_norm, slf_action_get_col_hit_norm, (void*)0x89a87c);
	hook_slf_vtable(slf_deconstructor_get_col_hit_pos, slf_action_get_col_hit_pos, (void*)0x89a874);
	hook_slf_vtable(slf_deconstructor_get_control_state_num, slf_action_get_control_state_num, (void*)0x89a7f4);
	hook_slf_vtable(slf_deconstructor_get_control_trigger_num, slf_action_get_control_trigger_num, (void*)0x89a7ec);
	hook_slf_vtable(slf_deconstructor_get_current_instance_thread_count_str, slf_action_get_current_instance_thread_count_str, (void*)0x89a9dc);
	hook_slf_vtable(slf_deconstructor_get_current_view_cam_pos, slf_action_get_current_view_cam_pos, (void*)0x89a5b4);
	hook_slf_vtable(slf_deconstructor_get_current_view_cam_x_facing, slf_action_get_current_view_cam_x_facing, (void*)0x89a59c);
	hook_slf_vtable(slf_deconstructor_get_current_view_cam_y_facing, slf_action_get_current_view_cam_y_facing, (void*)0x89a5a4);
	hook_slf_vtable(slf_deconstructor_get_current_view_cam_z_facing, slf_action_get_current_view_cam_z_facing, (void*)0x89a5ac);
	hook_slf_vtable(slf_deconstructor_get_fog_color, slf_action_get_fog_color, (void*)0x89a8f4);
	hook_slf_vtable(slf_deconstructor_get_fog_distance, slf_action_get_fog_distance, (void*)0x89a8fc);
	hook_slf_vtable(slf_deconstructor_get_game_info_num_str, slf_action_get_game_info_num_str, (void*)0x89a8c4);
	hook_slf_vtable(slf_deconstructor_get_game_info_str_str, slf_action_get_game_info_str_str, (void*)0x89a8d4);
	hook_slf_vtable(slf_deconstructor_get_glam_cam_num, slf_action_get_glam_cam_num, (void*)0x89b780);
	hook_slf_vtable(slf_deconstructor_get_global_time_dilation, slf_action_get_global_time_dilation, (void*)0x89a894);
	hook_slf_vtable(slf_deconstructor_get_ini_flag_str, slf_action_get_ini_flag_str, (void*)0x89a94c);
	hook_slf_vtable(slf_deconstructor_get_ini_num_str, slf_action_get_ini_num_str, (void*)0x89a954);
	hook_slf_vtable(slf_deconstructor_get_int_num_num, slf_action_get_int_num_num, (void*)0x89a92c);
	hook_slf_vtable(slf_deconstructor_get_mission_camera_marker_num, slf_action_get_mission_camera_marker_num, (void*)0x89c414);
	hook_slf_vtable(slf_deconstructor_get_mission_camera_transform_marker_num, slf_action_get_mission_camera_transform_marker_num, (void*)0x89c454);
	hook_slf_vtable(slf_deconstructor_get_mission_entity, slf_action_get_mission_entity, (void*)0x89c38c);
	hook_slf_vtable(slf_deconstructor_get_mission_key_posfacing3d, slf_action_get_mission_key_posfacing3d, (void*)0x89c36c);
	hook_slf_vtable(slf_deconstructor_get_mission_key_position, slf_action_get_mission_key_position, (void*)0x89c364);
	hook_slf_vtable(slf_deconstructor_get_mission_marker_num, slf_action_get_mission_marker_num, (void*)0x89c40c);
	hook_slf_vtable(slf_deconstructor_get_mission_nums, slf_action_get_mission_nums, (void*)0x89c3ac);
	hook_slf_vtable(slf_deconstructor_get_mission_patrol_waypoint, slf_action_get_mission_patrol_waypoint, (void*)0x89c384);
	hook_slf_vtable(slf_deconstructor_get_mission_positions, slf_action_get_mission_positions, (void*)0x89c39c);
	hook_slf_vtable(slf_deconstructor_get_mission_strings, slf_action_get_mission_strings, (void*)0x89c3a4);
	hook_slf_vtable(slf_deconstructor_get_mission_transform_marker_num, slf_action_get_mission_transform_marker_num, (void*)0x89c42c);
	hook_slf_vtable(slf_deconstructor_get_mission_trigger, slf_action_get_mission_trigger, (void*)0x89c394);
	hook_slf_vtable(slf_deconstructor_get_missions_key_position_by_index_district_str_num, slf_action_get_missions_key_position_by_index_district_str_num, (void*)0x89c3bc);
	hook_slf_vtable(slf_deconstructor_get_missions_nums_by_index_district_str_num_num_list, slf_action_get_missions_nums_by_index_district_str_num_num_list, (void*)0x89c3cc);
	hook_slf_vtable(slf_deconstructor_get_missions_patrol_waypoint_by_index_district_str_num, slf_action_get_missions_patrol_waypoint_by_index_district_str_num, (void*)0x89c3c4);
	hook_slf_vtable(slf_deconstructor_get_neighborhood_name_num, slf_action_get_neighborhood_name_num, (void*)0x89c54c);
	hook_slf_vtable(slf_deconstructor_get_num_free_slots_str, slf_action_get_num_free_slots_str, (void*)0x89c3e4);
	hook_slf_vtable(slf_deconstructor_get_num_mission_transform_marker, slf_action_get_num_mission_transform_marker, (void*)0x89c434);
	hook_slf_vtable(slf_deconstructor_get_pack_group_str, slf_action_get_pack_group_str, (void*)0x89c3ec);
	hook_slf_vtable(slf_deconstructor_get_pack_size_str, slf_action_get_pack_size_str, (void*)0x89c4e4);
	hook_slf_vtable(slf_deconstructor_get_patrol_difficulty_str, slf_action_get_patrol_difficulty_str, (void*)0x89c534);
	hook_slf_vtable(slf_deconstructor_get_patrol_node_position_by_index_str_num, slf_action_get_patrol_node_position_by_index_str_num, (void*)0x89c52c);
	hook_slf_vtable(slf_deconstructor_get_patrol_start_position_str, slf_action_get_patrol_start_position_str, (void*)0x89c524);
	hook_slf_vtable(slf_deconstructor_get_patrol_unlock_threshold_str, slf_action_get_patrol_unlock_threshold_str, (void*)0x89c53c);
	hook_slf_vtable(slf_deconstructor_get_platform, slf_action_get_platform, (void*)0x89a508);
	hook_slf_vtable(slf_deconstructor_get_render_opt_num_str, slf_action_get_render_opt_num_str, (void*)0x89a8e4);
	hook_slf_vtable(slf_deconstructor_get_spider_reflexes_spiderman_time_dilation, slf_action_get_spider_reflexes_spiderman_time_dilation, (void*)0x89cac4);
	hook_slf_vtable(slf_deconstructor_get_spider_reflexes_world_time_dilation, slf_action_get_spider_reflexes_world_time_dilation, (void*)0x89cad4);
	hook_slf_vtable(slf_deconstructor_get_time_inc, slf_action_get_time_inc, (void*)0x89a7a4);
	hook_slf_vtable(slf_deconstructor_get_time_of_day, slf_action_get_time_of_day, (void*)0x89a974);
	hook_slf_vtable(slf_deconstructor_get_time_of_day_rate, slf_action_get_time_of_day_rate, (void*)0x89a96c);
	hook_slf_vtable(slf_deconstructor_get_token_index_from_id_num_num, slf_action_get_token_index_from_id_num_num, (void*)0x89b554);
	hook_slf_vtable(slf_deconstructor_get_traffic_spawn_point_near_camera_vector3d_list, slf_action_get_traffic_spawn_point_near_camera_vector3d_list, (void*)0x89aa98);
	hook_slf_vtable(slf_deconstructor_greater_than_or_equal_rounded_num_num, slf_action_greater_than_or_equal_rounded_num_num, (void*)0x89bc90);
	hook_slf_vtable(slf_deconstructor_hard_break, slf_action_hard_break, (void*)0x89aa1c);
	hook_slf_vtable(slf_deconstructor_has_substring_str_str, slf_action_has_substring_str_str, (void*)0x89a580);
	hook_slf_vtable(slf_deconstructor_hero, slf_action_hero, (void*)0x89aed4);
	hook_slf_vtable(slf_deconstructor_hero_exists, slf_action_hero_exists, (void*)0x89aedc);
	hook_slf_vtable(slf_deconstructor_hero_type, slf_action_hero_type, (void*)0x89aee4);
	hook_slf_vtable(slf_deconstructor_hide_controller_gauge, slf_action_hide_controller_gauge, (void*)0x89bb20);
	hook_slf_vtable(slf_deconstructor_initialize_encounter_object, slf_action_initialize_encounter_object, (void*)0x89aa0c);
	hook_slf_vtable(slf_deconstructor_initialize_encounter_objects, slf_action_initialize_encounter_objects, (void*)0x89aa04);
	hook_slf_vtable(slf_deconstructor_insert_pack_str, slf_action_insert_pack_str, (void*)0x89c3d4);
	hook_slf_vtable(slf_deconstructor_invoke_pause_menu_unlockables, slf_action_invoke_pause_menu_unlockables, (void*)0x89bc98);
	hook_slf_vtable(slf_deconstructor_is_ai_enabled, slf_action_is_ai_enabled, (void*)0x89a6d4);
	hook_slf_vtable(slf_deconstructor_is_cut_scene_playing, slf_action_is_cut_scene_playing, (void*)0x89b7d0);
	hook_slf_vtable(slf_deconstructor_is_district_loaded_num, slf_action_is_district_loaded_num, (void*)0x89c49c);
	hook_slf_vtable(slf_deconstructor_is_hero_frozen, slf_action_is_hero_frozen, (void*)0x89a60c);
	hook_slf_vtable(slf_deconstructor_is_hero_peter_parker, slf_action_is_hero_peter_parker, (void*)0x89aefc);
	hook_slf_vtable(slf_deconstructor_is_hero_spidey, slf_action_is_hero_spidey, (void*)0x89aeec);
	hook_slf_vtable(slf_deconstructor_is_hero_venom, slf_action_is_hero_venom, (void*)0x89aef4);
	hook_slf_vtable(slf_deconstructor_is_marky_cam_enabled, slf_action_is_marky_cam_enabled, (void*)0x89a5c4);
	hook_slf_vtable(slf_deconstructor_is_mission_active, slf_action_is_mission_active, (void*)0x89c50c);
	hook_slf_vtable(slf_deconstructor_is_mission_loading, slf_action_is_mission_loading, (void*)0x89c514);
	hook_slf_vtable(slf_deconstructor_is_pack_available_str, slf_action_is_pack_available_str, (void*)0x89c404);
	hook_slf_vtable(slf_deconstructor_is_pack_loaded_str, slf_action_is_pack_loaded_str, (void*)0x89c3fc);
	hook_slf_vtable(slf_deconstructor_is_pack_pushed_str, slf_action_is_pack_pushed_str, (void*)0x89c34c);
	hook_slf_vtable(slf_deconstructor_is_path_graph_inside_glass_house_str, slf_action_is_path_graph_inside_glass_house_str, (void*)0x89aaa0);
	hook_slf_vtable(slf_deconstructor_is_patrol_active, slf_action_is_patrol_active, (void*)0x89c504);
	hook_slf_vtable(slf_deconstructor_is_patrol_node_empty_num, slf_action_is_patrol_node_empty_num, (void*)0x89c544);
	hook_slf_vtable(slf_deconstructor_is_paused, slf_action_is_paused, (void*)0x89a6b4);
	hook_slf_vtable(slf_deconstructor_is_physics_enabled, slf_action_is_physics_enabled, (void*)0x89a6e4);
	hook_slf_vtable(slf_deconstructor_is_point_inside_glass_house_vector3d, slf_action_is_point_inside_glass_house_vector3d, (void*)0x89a540);
	hook_slf_vtable(slf_deconstructor_is_point_under_water_vector3d, slf_action_is_point_under_water_vector3d, (void*)0x89aa3c);
	hook_slf_vtable(slf_deconstructor_is_user_camera_enabled, slf_action_is_user_camera_enabled, (void*)0x89a5cc);
	hook_slf_vtable(slf_deconstructor_load_anim_str, slf_action_load_anim_str, (void*)0x89aaf0);
	hook_slf_vtable(slf_deconstructor_load_level_str_vector3d, slf_action_load_level_str_vector3d, (void*)0x89a8ac);
	hook_slf_vtable(slf_deconstructor_lock_all_districts, slf_action_lock_all_districts, (void*)0x89c4c4);
	hook_slf_vtable(slf_deconstructor_lock_district_num, slf_action_lock_district_num, (void*)0x89c494);
	hook_slf_vtable(slf_deconstructor_lock_mission_manager_num, slf_action_lock_mission_manager_num, (void*)0x89c51c);
	hook_slf_vtable(slf_deconstructor_los_check_vector3d_vector3d, slf_action_los_check_vector3d_vector3d, (void*)0x89a814);
	hook_slf_vtable(slf_deconstructor_lower_hotpursuit_indicator_level, slf_action_lower_hotpursuit_indicator_level, (void*)0x89bae0);
	hook_slf_vtable(slf_deconstructor_malor_vector3d_num, slf_action_malor_vector3d_num, (void*)0x89a984);
	hook_slf_vtable(slf_deconstructor_normal_vector3d, slf_action_normal_vector3d, (void*)0x89ba40);
	hook_slf_vtable(slf_deconstructor_pause_game_num, slf_action_pause_game_num, (void*)0x89a6bc);
	hook_slf_vtable(slf_deconstructor_play_credits, slf_action_play_credits, (void*)0x89baf8);
	hook_slf_vtable(slf_deconstructor_play_prerender_str, slf_action_play_prerender_str, (void*)0x89a8b4);
	hook_slf_vtable(slf_deconstructor_pop_pack_str, slf_action_pop_pack_str, (void*)0x89c344);
	hook_slf_vtable(slf_deconstructor_post_message_str_num, slf_action_post_message_str_num, (void*)0x89a73c);
	hook_slf_vtable(slf_deconstructor_pre_roll_all_pfx_num, slf_action_pre_roll_all_pfx_num, (void*)0x89aa34);
	hook_slf_vtable(slf_deconstructor_press_controller_gauge_num, slf_action_press_controller_gauge_num, (void*)0x89bb28);
	hook_slf_vtable(slf_deconstructor_press_controller_gauge_num_num_num, slf_action_press_controller_gauge_num_num_num, (void*)0x89bb30);
	hook_slf_vtable(slf_deconstructor_purge_district_num, slf_action_purge_district_num, (void*)0x89c4bc);
	hook_slf_vtable(slf_deconstructor_push_pack_str, slf_action_push_pack_str, (void*)0x89c334);
	hook_slf_vtable(slf_deconstructor_push_pack_into_district_slot_str, slf_action_push_pack_into_district_slot_str, (void*)0x89c33c);
	hook_slf_vtable(slf_deconstructor_raise_hotpursuit_indicator_level, slf_action_raise_hotpursuit_indicator_level, (void*)0x89bad8);
	hook_slf_vtable(slf_deconstructor_random_num, slf_action_random_num, (void*)0x89a744);
	hook_slf_vtable(slf_deconstructor_remove_civilian_info_num, slf_action_remove_civilian_info_num, (void*)0x89c5c4);
	hook_slf_vtable(slf_deconstructor_remove_civilian_info_entity_entity_num, slf_action_remove_civilian_info_entity_entity_num, (void*)0x89c5d4);
	hook_slf_vtable(slf_deconstructor_remove_glass_house_str, slf_action_remove_glass_house_str, (void*)0x89a568);
	hook_slf_vtable(slf_deconstructor_remove_item_entity_from_world_entity, slf_action_remove_item_entity_from_world_entity, (void*)0x89affc);
	hook_slf_vtable(slf_deconstructor_remove_pack_str, slf_action_remove_pack_str, (void*)0x89c3dc);
	hook_slf_vtable(slf_deconstructor_remove_traffic_model_num, slf_action_remove_traffic_model_num, (void*)0x89c5ac);
	hook_slf_vtable(slf_deconstructor_reset_externed_alses, slf_action_reset_externed_alses, (void*)0x89b064);
	hook_slf_vtable(slf_deconstructor_set_all_anchors_activated_num, slf_action_set_all_anchors_activated_num, (void*)0x89caec);
	hook_slf_vtable(slf_deconstructor_set_blur_num, slf_action_set_blur_num, (void*)0x89a63c);
	hook_slf_vtable(slf_deconstructor_set_blur_blend_mode_num, slf_action_set_blur_blend_mode_num, (void*)0x89a664);
	hook_slf_vtable(slf_deconstructor_set_blur_color_vector3d, slf_action_set_blur_color_vector3d, (void*)0x89a644);
	hook_slf_vtable(slf_deconstructor_set_blur_offset_num_num, slf_action_set_blur_offset_num_num, (void*)0x89a654);
	hook_slf_vtable(slf_deconstructor_set_blur_rot_num, slf_action_set_blur_rot_num, (void*)0x89a65c);
	hook_slf_vtable(slf_deconstructor_set_blur_scale_num_num, slf_action_set_blur_scale_num_num, (void*)0x89a64c);
	hook_slf_vtable(slf_deconstructor_set_clear_color_vector3d, slf_action_set_clear_color_vector3d, (void*)0x89a6f4);
	hook_slf_vtable(slf_deconstructor_set_current_mission_objective_caption_num, slf_action_set_current_mission_objective_caption_num, (void*)0x89cadc);
	hook_slf_vtable(slf_deconstructor_set_default_traffic_hitpoints_num, slf_action_set_default_traffic_hitpoints_num, (void*)0x89c614);
	hook_slf_vtable(slf_deconstructor_set_dialog_box_flavor_num, slf_action_set_dialog_box_flavor_num, (void*)0x89bc5c);
	hook_slf_vtable(slf_deconstructor_set_dialog_box_lockout_time_num, slf_action_set_dialog_box_lockout_time_num, (void*)0x89bc6c);
	hook_slf_vtable(slf_deconstructor_set_engine_property_str_num, slf_action_set_engine_property_str_num, (void*)0x89a99c);
	hook_slf_vtable(slf_deconstructor_set_fov_num, slf_action_set_fov_num, (void*)0x89a62c);
	hook_slf_vtable(slf_deconstructor_set_game_info_num_str_num, slf_action_set_game_info_num_str_num, (void*)0x89a8bc);
	hook_slf_vtable(slf_deconstructor_set_game_info_str_str_str, slf_action_set_game_info_str_str_str, (void*)0x89a8cc);
	hook_slf_vtable(slf_deconstructor_set_global_time_dilation_num, slf_action_set_global_time_dilation_num, (void*)0x89a89c);
	hook_slf_vtable(slf_deconstructor_set_marky_cam_lookat_vector3d, slf_action_set_marky_cam_lookat_vector3d, (void*)0x89a5ec);
	hook_slf_vtable(slf_deconstructor_set_max_streaming_distance_num, slf_action_set_max_streaming_distance_num, (void*)0x89c4b4);
	hook_slf_vtable(slf_deconstructor_set_mission_key_pos_facing_vector3d_vector3d, slf_action_set_mission_key_pos_facing_vector3d_vector3d, (void*)0x89c37c);
	hook_slf_vtable(slf_deconstructor_set_mission_key_position_vector3d, slf_action_set_mission_key_position_vector3d, (void*)0x89c374);
	hook_slf_vtable(slf_deconstructor_set_mission_text_num_elip, slf_action_set_mission_text_num_elip, (void*)0x89bbf8);
	hook_slf_vtable(slf_deconstructor_set_mission_text_box_flavor_num, slf_action_set_mission_text_box_flavor_num, (void*)0x89bc64);
	hook_slf_vtable(slf_deconstructor_set_mission_text_debug_str, slf_action_set_mission_text_debug_str, (void*)0x89bc00);
	hook_slf_vtable(slf_deconstructor_set_parking_density_num, slf_action_set_parking_density_num, (void*)0x89c60c);
	hook_slf_vtable(slf_deconstructor_set_pedestrian_density_num, slf_action_set_pedestrian_density_num, (void*)0x89c5f4);
	hook_slf_vtable(slf_deconstructor_set_render_opt_num_str_num, slf_action_set_render_opt_num_str_num, (void*)0x89a8dc);
	hook_slf_vtable(slf_deconstructor_set_score_widget_score_num, slf_action_set_score_widget_score_num, (void*)0x89bac8);
	hook_slf_vtable(slf_deconstructor_set_sound_category_volume_num_num_num, slf_action_set_sound_category_volume_num_num_num, (void*)0x89a9d4);
	hook_slf_vtable(slf_deconstructor_set_spider_reflexes_blur_num, slf_action_set_spider_reflexes_blur_num, (void*)0x89a674);
	hook_slf_vtable(slf_deconstructor_set_spider_reflexes_blur_blend_mode_num, slf_action_set_spider_reflexes_blur_blend_mode_num, (void*)0x89a69c);
	hook_slf_vtable(slf_deconstructor_set_spider_reflexes_blur_color_vector3d, slf_action_set_spider_reflexes_blur_color_vector3d, (void*)0x89a67c);
	hook_slf_vtable(slf_deconstructor_set_spider_reflexes_blur_offset_num_num, slf_action_set_spider_reflexes_blur_offset_num_num, (void*)0x89a68c);
	hook_slf_vtable(slf_deconstructor_set_spider_reflexes_blur_rot_num, slf_action_set_spider_reflexes_blur_rot_num, (void*)0x89a694);
	hook_slf_vtable(slf_deconstructor_set_spider_reflexes_blur_scale_num_num, slf_action_set_spider_reflexes_blur_scale_num_num, (void*)0x89a684);
	hook_slf_vtable(slf_deconstructor_set_spider_reflexes_hero_meter_depletion_rate_num, slf_action_set_spider_reflexes_hero_meter_depletion_rate_num, (void*)0x89cab4);
	hook_slf_vtable(slf_deconstructor_set_spider_reflexes_spiderman_time_dilation_num, slf_action_set_spider_reflexes_spiderman_time_dilation_num, (void*)0x89cabc);
	hook_slf_vtable(slf_deconstructor_set_spider_reflexes_world_time_dilation_num, slf_action_set_spider_reflexes_world_time_dilation_num, (void*)0x89cacc);
	hook_slf_vtable(slf_deconstructor_set_state_of_the_story_caption_num, slf_action_set_state_of_the_story_caption_num, (void*)0x89cae4);
	hook_slf_vtable(slf_deconstructor_set_target_info_entity_vector3d_vector3d, slf_action_set_target_info_entity_vector3d_vector3d, (void*)0x89b6c4);
	hook_slf_vtable(slf_deconstructor_set_time_of_day_num, slf_action_set_time_of_day_num, (void*)0x89a964);
	hook_slf_vtable(slf_deconstructor_set_traffic_density_num, slf_action_set_traffic_density_num, (void*)0x89c604);
	hook_slf_vtable(slf_deconstructor_set_traffic_model_usage_num_num, slf_action_set_traffic_model_usage_num_num, (void*)0x89c5b4);
	hook_slf_vtable(slf_deconstructor_set_vibration_resume_num, slf_action_set_vibration_resume_num, (void*)0x89a7d4);
	hook_slf_vtable(slf_deconstructor_set_whoosh_interp_rate_num, slf_action_set_whoosh_interp_rate_num, (void*)0x89b504);
	hook_slf_vtable(slf_deconstructor_set_whoosh_pitch_range_num_num, slf_action_set_whoosh_pitch_range_num_num, (void*)0x89b4fc);
	hook_slf_vtable(slf_deconstructor_set_whoosh_speed_range_num_num, slf_action_set_whoosh_speed_range_num_num, (void*)0x89b4ec);
	hook_slf_vtable(slf_deconstructor_set_whoosh_volume_range_num_num, slf_action_set_whoosh_volume_range_num_num, (void*)0x89b4f4);
	hook_slf_vtable(slf_deconstructor_set_zoom_num, slf_action_set_zoom_num, (void*)0x89a624);
	hook_slf_vtable(slf_deconstructor_show_controller_gauge, slf_action_show_controller_gauge, (void*)0x89bb18);
	hook_slf_vtable(slf_deconstructor_show_hotpursuit_indicator_num, slf_action_show_hotpursuit_indicator_num, (void*)0x89bad0);
	hook_slf_vtable(slf_deconstructor_show_score_widget_num, slf_action_show_score_widget_num, (void*)0x89bac0);
	hook_slf_vtable(slf_deconstructor_shut_up_all_ai_voice_boxes, slf_action_shut_up_all_ai_voice_boxes, (void*)0x89b50c);
	hook_slf_vtable(slf_deconstructor_sin_num, slf_action_sin_num, (void*)0x89a904);
	hook_slf_vtable(slf_deconstructor_sin_cos_num, slf_action_sin_cos_num, (void*)0x89a924);
	hook_slf_vtable(slf_deconstructor_soft_load_num, slf_action_soft_load_num, (void*)0x89bcbc);
	hook_slf_vtable(slf_deconstructor_soft_save_num, slf_action_soft_save_num, (void*)0x89bcb4);
	hook_slf_vtable(slf_deconstructor_spiderman_add_hero_points_num, slf_action_spiderman_add_hero_points_num, (void*)0x89caa4);
	hook_slf_vtable(slf_deconstructor_spiderman_bank_stylepoints, slf_action_spiderman_bank_stylepoints, (void*)0x89c91c);
	hook_slf_vtable(slf_deconstructor_spiderman_break_web, slf_action_spiderman_break_web, (void*)0x89c9e4);
	hook_slf_vtable(slf_deconstructor_spiderman_camera_add_shake_num_num_num, slf_action_spiderman_camera_add_shake_num_num_num, (void*)0x89cb34);
	hook_slf_vtable(slf_deconstructor_spiderman_camera_autocorrect_num, slf_action_spiderman_camera_autocorrect_num, (void*)0x89c924);
	hook_slf_vtable(slf_deconstructor_spiderman_camera_clear_fixedstatic, slf_action_spiderman_camera_clear_fixedstatic, (void*)0x89cafc);
	hook_slf_vtable(slf_deconstructor_spiderman_camera_enable_combat_num, slf_action_spiderman_camera_enable_combat_num, (void*)0x89cb24);
	hook_slf_vtable(slf_deconstructor_spiderman_camera_enable_lookaround_num, slf_action_spiderman_camera_enable_lookaround_num, (void*)0x89cb1c);
	hook_slf_vtable(slf_deconstructor_spiderman_camera_set_fixedstatic_vector3d_vector3d, slf_action_spiderman_camera_set_fixedstatic_vector3d_vector3d, (void*)0x89caf4);
	hook_slf_vtable(slf_deconstructor_spiderman_camera_set_follow_entity, slf_action_spiderman_camera_set_follow_entity, (void*)0x89cb2c);
	hook_slf_vtable(slf_deconstructor_spiderman_camera_set_hero_underwater_num, slf_action_spiderman_camera_set_hero_underwater_num, (void*)0x89cb3c);
	hook_slf_vtable(slf_deconstructor_spiderman_camera_set_interpolation_time_num, slf_action_spiderman_camera_set_interpolation_time_num, (void*)0x89cb14);
	hook_slf_vtable(slf_deconstructor_spiderman_camera_set_lockon_min_distance_num, slf_action_spiderman_camera_set_lockon_min_distance_num, (void*)0x89cb04);
	hook_slf_vtable(slf_deconstructor_spiderman_camera_set_lockon_y_offset_num, slf_action_spiderman_camera_set_lockon_y_offset_num, (void*)0x89cb0c);
	hook_slf_vtable(slf_deconstructor_spiderman_charged_jump, slf_action_spiderman_charged_jump, (void*)0x89c98c);
	hook_slf_vtable(slf_deconstructor_spiderman_enable_control_button_num_num, slf_action_spiderman_enable_control_button_num_num, (void*)0x89ca94);
	hook_slf_vtable(slf_deconstructor_spiderman_enable_lockon_num, slf_action_spiderman_enable_lockon_num, (void*)0x89c9ac);
	hook_slf_vtable(slf_deconstructor_spiderman_engage_lockon_num, slf_action_spiderman_engage_lockon_num, (void*)0x89c9b4);
	hook_slf_vtable(slf_deconstructor_spiderman_engage_lockon_num_entity, slf_action_spiderman_engage_lockon_num_entity, (void*)0x89c9bc);
	hook_slf_vtable(slf_deconstructor_spiderman_get_hero_points, slf_action_spiderman_get_hero_points, (void*)0x89ca9c);
	hook_slf_vtable(slf_deconstructor_spiderman_get_max_zip_length, slf_action_spiderman_get_max_zip_length, (void*)0x89c9dc);
	hook_slf_vtable(slf_deconstructor_spiderman_get_spidey_sense_level, slf_action_spiderman_get_spidey_sense_level, (void*)0x89c99c);
	hook_slf_vtable(slf_deconstructor_spiderman_is_crawling, slf_action_spiderman_is_crawling, (void*)0x89c934);
	hook_slf_vtable(slf_deconstructor_spiderman_is_falling, slf_action_spiderman_is_falling, (void*)0x89c964);
	hook_slf_vtable(slf_deconstructor_spiderman_is_jumping, slf_action_spiderman_is_jumping, (void*)0x89c96c);
	hook_slf_vtable(slf_deconstructor_spiderman_is_on_ceiling, slf_action_spiderman_is_on_ceiling, (void*)0x89c944);
	hook_slf_vtable(slf_deconstructor_spiderman_is_on_ground, slf_action_spiderman_is_on_ground, (void*)0x89c94c);
	hook_slf_vtable(slf_deconstructor_spiderman_is_on_wall, slf_action_spiderman_is_on_wall, (void*)0x89c93c);
	hook_slf_vtable(slf_deconstructor_spiderman_is_running, slf_action_spiderman_is_running, (void*)0x89c95c);
	hook_slf_vtable(slf_deconstructor_spiderman_is_sprint_crawling, slf_action_spiderman_is_sprint_crawling, (void*)0x89c984);
	hook_slf_vtable(slf_deconstructor_spiderman_is_sprinting, slf_action_spiderman_is_sprinting, (void*)0x89c974);
	hook_slf_vtable(slf_deconstructor_spiderman_is_swinging, slf_action_spiderman_is_swinging, (void*)0x89c954);
	hook_slf_vtable(slf_deconstructor_spiderman_is_wallsprinting, slf_action_spiderman_is_wallsprinting, (void*)0x89c97c);
	hook_slf_vtable(slf_deconstructor_spiderman_lock_spider_reflexes_off, slf_action_spiderman_lock_spider_reflexes_off, (void*)0x89ca24);
	hook_slf_vtable(slf_deconstructor_spiderman_lock_spider_reflexes_on, slf_action_spiderman_lock_spider_reflexes_on, (void*)0x89ca1c);
	hook_slf_vtable(slf_deconstructor_spiderman_lockon_camera_engaged, slf_action_spiderman_lockon_camera_engaged, (void*)0x89ca0c);
	hook_slf_vtable(slf_deconstructor_spiderman_lockon_mode_engaged, slf_action_spiderman_lockon_mode_engaged, (void*)0x89ca04);
	hook_slf_vtable(slf_deconstructor_spiderman_set_camera_target_entity, slf_action_spiderman_set_camera_target_entity, (void*)0x89ca14);
	hook_slf_vtable(slf_deconstructor_spiderman_set_desired_mode_num_vector3d_vector3d, slf_action_spiderman_set_desired_mode_num_vector3d_vector3d, (void*)0x89c9ec);
	hook_slf_vtable(slf_deconstructor_spiderman_set_health_beep_min_max_cooldown_time_num_num, slf_action_spiderman_set_health_beep_min_max_cooldown_time_num_num, (void*)0x89c9f4);
	hook_slf_vtable(slf_deconstructor_spiderman_set_health_beep_threshold_num, slf_action_spiderman_set_health_beep_threshold_num, (void*)0x89c9fc);
	hook_slf_vtable(slf_deconstructor_spiderman_set_hero_meter_empty_rate_num, slf_action_spiderman_set_hero_meter_empty_rate_num, (void*)0x89cb44);
	hook_slf_vtable(slf_deconstructor_spiderman_set_max_height_num, slf_action_spiderman_set_max_height_num, (void*)0x89c9cc);
	hook_slf_vtable(slf_deconstructor_spiderman_set_max_zip_length_num, slf_action_spiderman_set_max_zip_length_num, (void*)0x89c9d4);
	hook_slf_vtable(slf_deconstructor_spiderman_set_min_height_num, slf_action_spiderman_set_min_height_num, (void*)0x89c9c4);
	hook_slf_vtable(slf_deconstructor_spiderman_set_spidey_sense_level_num, slf_action_spiderman_set_spidey_sense_level_num, (void*)0x89c994);
	hook_slf_vtable(slf_deconstructor_spiderman_set_swing_anchor_max_sticky_time_num, slf_action_spiderman_set_swing_anchor_max_sticky_time_num, (void*)0x89c9a4);
	hook_slf_vtable(slf_deconstructor_spiderman_subtract_hero_points_num, slf_action_spiderman_subtract_hero_points_num, (void*)0x89caac);
	hook_slf_vtable(slf_deconstructor_spiderman_td_set_alternating_wall_run_occurrence_threshold_num, slf_action_spiderman_td_set_alternating_wall_run_occurrence_threshold_num, (void*)0x89ca74);
	hook_slf_vtable(slf_deconstructor_spiderman_td_set_alternating_wall_run_time_threshold_num, slf_action_spiderman_td_set_alternating_wall_run_time_threshold_num, (void*)0x89ca6c);
	hook_slf_vtable(slf_deconstructor_spiderman_td_set_big_air_height_threshold_num, slf_action_spiderman_td_set_big_air_height_threshold_num, (void*)0x89ca34);
	hook_slf_vtable(slf_deconstructor_spiderman_td_set_continuous_air_swings_threshold_num, slf_action_spiderman_td_set_continuous_air_swings_threshold_num, (void*)0x89ca4c);
	hook_slf_vtable(slf_deconstructor_spiderman_td_set_gain_altitude_height_threshold_num, slf_action_spiderman_td_set_gain_altitude_height_threshold_num, (void*)0x89ca54);
	hook_slf_vtable(slf_deconstructor_spiderman_td_set_near_miss_trigger_radius_num, slf_action_spiderman_td_set_near_miss_trigger_radius_num, (void*)0x89ca84);
	hook_slf_vtable(slf_deconstructor_spiderman_td_set_near_miss_velocity_threshold_num, slf_action_spiderman_td_set_near_miss_velocity_threshold_num, (void*)0x89ca8c);
	hook_slf_vtable(slf_deconstructor_spiderman_td_set_orbit_min_radius_threshold_num, slf_action_spiderman_td_set_orbit_min_radius_threshold_num, (void*)0x89ca3c);
	hook_slf_vtable(slf_deconstructor_spiderman_td_set_soft_landing_velocity_threshold_num, slf_action_spiderman_td_set_soft_landing_velocity_threshold_num, (void*)0x89ca5c);
	hook_slf_vtable(slf_deconstructor_spiderman_td_set_super_speed_speed_threshold_num, slf_action_spiderman_td_set_super_speed_speed_threshold_num, (void*)0x89ca7c);
	hook_slf_vtable(slf_deconstructor_spiderman_td_set_swinging_wall_run_time_threshold_num, slf_action_spiderman_td_set_swinging_wall_run_time_threshold_num, (void*)0x89ca64);
	hook_slf_vtable(slf_deconstructor_spiderman_td_set_wall_sprint_time_threshold_num, slf_action_spiderman_td_set_wall_sprint_time_threshold_num, (void*)0x89ca44);
	hook_slf_vtable(slf_deconstructor_spiderman_unlock_spider_reflexes, slf_action_spiderman_unlock_spider_reflexes, (void*)0x89ca2c);
	hook_slf_vtable(slf_deconstructor_spiderman_wait_add_threat_entity_str_num_num, slf_action_spiderman_wait_add_threat_entity_str_num_num, (void*)0x89cb4c);
	hook_slf_vtable(slf_deconstructor_spidey_can_see_vector3d, slf_action_spidey_can_see_vector3d, (void*)0x89c92c);
	hook_slf_vtable(slf_deconstructor_sqrt_num, slf_action_sqrt_num, (void*)0x89a914);
	hook_slf_vtable(slf_deconstructor_start_patrol_str, slf_action_start_patrol_str, (void*)0x89c4f4);
	hook_slf_vtable(slf_deconstructor_stop_all_sounds, slf_action_stop_all_sounds, (void*)0x89b514);
	hook_slf_vtable(slf_deconstructor_stop_credits, slf_action_stop_credits, (void*)0x89bb00);
	hook_slf_vtable(slf_deconstructor_stop_vibration, slf_action_stop_vibration, (void*)0x89a7cc);
	hook_slf_vtable(slf_deconstructor_subtitle_num_num_num_num_num_num, slf_action_subtitle_num_num_num_num_num_num, (void*)0x89bcc4);
	hook_slf_vtable(slf_deconstructor_swap_hero_costume_str, slf_action_swap_hero_costume_str, (void*)0x89c4d4);
	hook_slf_vtable(slf_deconstructor_text_width_str, slf_action_text_width_str, (void*)0x89a7ac);
	hook_slf_vtable(slf_deconstructor_timer_widget_get_count_up, slf_action_timer_widget_get_count_up, (void*)0x89bb70);
	hook_slf_vtable(slf_deconstructor_timer_widget_get_time, slf_action_timer_widget_get_time, (void*)0x89bb60);
	hook_slf_vtable(slf_deconstructor_timer_widget_set_count_up_num, slf_action_timer_widget_set_count_up_num, (void*)0x89bb68);
	hook_slf_vtable(slf_deconstructor_timer_widget_set_time_num, slf_action_timer_widget_set_time_num, (void*)0x89bb58);
	hook_slf_vtable(slf_deconstructor_timer_widget_start, slf_action_timer_widget_start, (void*)0x89bb48);
	hook_slf_vtable(slf_deconstructor_timer_widget_stop, slf_action_timer_widget_stop, (void*)0x89bb50);
	hook_slf_vtable(slf_deconstructor_timer_widget_turn_off, slf_action_timer_widget_turn_off, (void*)0x89bb40);
	hook_slf_vtable(slf_deconstructor_timer_widget_turn_on, slf_action_timer_widget_turn_on, (void*)0x89bb38);
	hook_slf_vtable(slf_deconstructor_to_beam_entity, slf_action_to_beam_entity, (void*)0x89abbc);
	hook_slf_vtable(slf_deconstructor_to_gun_entity, slf_action_to_gun_entity, (void*)0x89b5a0);
	hook_slf_vtable(slf_deconstructor_to_item_entity, slf_action_to_item_entity, (void*)0x89b6bc);
	hook_slf_vtable(slf_deconstructor_to_polytube_entity, slf_action_to_polytube_entity, (void*)0x89c238);
	hook_slf_vtable(slf_deconstructor_to_switch_entity, slf_action_to_switch_entity, (void*)0x89b8e4);
	hook_slf_vtable(slf_deconstructor_trace_str, slf_action_trace_str, (void*)0x89aa14);
	hook_slf_vtable(slf_deconstructor_trigger_is_valid_trigger, slf_action_trigger_is_valid_trigger, (void*)0x89b9b8);
	hook_slf_vtable(slf_deconstructor_turn_off_boss_health, slf_action_turn_off_boss_health, (void*)0x89bbd0);
	hook_slf_vtable(slf_deconstructor_turn_off_hero_health, slf_action_turn_off_hero_health, (void*)0x89bbd8);
	hook_slf_vtable(slf_deconstructor_turn_off_mission_text, slf_action_turn_off_mission_text, (void*)0x89bc20);
	hook_slf_vtable(slf_deconstructor_turn_off_third_party_health, slf_action_turn_off_third_party_health, (void*)0x89bbe0);
	hook_slf_vtable(slf_deconstructor_turn_on_boss_health_num_entity, slf_action_turn_on_boss_health_num_entity, (void*)0x89bbb8);
	hook_slf_vtable(slf_deconstructor_turn_on_hero_health_num_entity, slf_action_turn_on_hero_health_num_entity, (void*)0x89bbc0);
	hook_slf_vtable(slf_deconstructor_turn_on_third_party_health_num_entity, slf_action_turn_on_third_party_health_num_entity, (void*)0x89bbc8);
	hook_slf_vtable(slf_deconstructor_unload_script, slf_action_unload_script, (void*)0x89c35c);
	hook_slf_vtable(slf_deconstructor_unlock_all_exterior_districts, slf_action_unlock_all_exterior_districts, (void*)0x89c4cc);
	hook_slf_vtable(slf_deconstructor_unlock_district_num, slf_action_unlock_district_num, (void*)0x89c48c);
	hook_slf_vtable(slf_deconstructor_vibrate_controller_num, slf_action_vibrate_controller_num, (void*)0x89a7c4);
	hook_slf_vtable(slf_deconstructor_vibrate_controller_num_num, slf_action_vibrate_controller_num_num, (void*)0x89a7bc);
	hook_slf_vtable(slf_deconstructor_vibrate_controller_num_num_num_num_num_num, slf_action_vibrate_controller_num_num_num_num_num_num, (void*)0x89a7b4);
	hook_slf_vtable(slf_deconstructor_vo_delay_num_num_num_num, slf_action_vo_delay_num_num_num_num, (void*)0x89a734);
	hook_slf_vtable(slf_deconstructor_wait_animate_fog_color_vector3d_num, slf_action_wait_animate_fog_color_vector3d_num, (void*)0x89a6fc);
	hook_slf_vtable(slf_deconstructor_wait_animate_fog_distance_num_num, slf_action_wait_animate_fog_distance_num_num, (void*)0x89a704);
	hook_slf_vtable(slf_deconstructor_wait_animate_fog_distances_num_num_num, slf_action_wait_animate_fog_distances_num_num_num, (void*)0x89a70c);
	hook_slf_vtable(slf_deconstructor_wait_change_blur_num_vector3d_num_num_num_num_num_num, slf_action_wait_change_blur_num_vector3d_num_num_num_num_num_num, (void*)0x89a66c);
	hook_slf_vtable(slf_deconstructor_wait_change_spider_reflexes_blur_num_vector3d_num_num_num_num_num_num, slf_action_wait_change_spider_reflexes_blur_num_vector3d_num_num_num_num_num_num, (void*)0x89a6a4);
	hook_slf_vtable(slf_deconstructor_wait_for_streamer_to_reach_equilibrium, slf_action_wait_for_streamer_to_reach_equilibrium, (void*)0x89c4a4);
	hook_slf_vtable(slf_deconstructor_wait_fps_test_num_num_vector3d_vector3d, slf_action_wait_fps_test_num_num_vector3d_vector3d, (void*)0x89a8ec);
	hook_slf_vtable(slf_deconstructor_wait_frame, slf_action_wait_frame, (void*)0x89a714);
	hook_slf_vtable(slf_deconstructor_wait_set_global_time_dilation_num_num, slf_action_wait_set_global_time_dilation_num_num, (void*)0x89a8a4);
	hook_slf_vtable(slf_deconstructor_wait_set_zoom_num_num, slf_action_wait_set_zoom_num_num, (void*)0x89a634);
	hook_slf_vtable(slf_deconstructor_write_to_file_str_str, slf_action_write_to_file_str_str, (void*)0x89a844);


}

void install_patches() {

	HookFunc(0x004EACF0, aeps_RenderAll, 0, "Patching call to aeps::RenderAll");

	HookFunc(0x0052B5D7, myDebugMenu, 0, "Hooking nglListEndScene to inject debug menu");
	//save orig ptr
	nflSystemOpenFile_orig = *nflSystemOpenFile_data;
	*nflSystemOpenFile_data = &nflSystemOpenFile;
	printf("Replaced nflSystemOpenFile %08X -> %08X\n", (DWORD)nflSystemOpenFile_orig, (DWORD)&nflSystemOpenFile);


	ReadOrWrite_orig = *ReadOrWrite_data;
	*ReadOrWrite_data = &ReadOrWrite;
	printf("Replaced ReadOrWrite %08X -> %08X\n", (DWORD)ReadOrWrite_orig, (DWORD)&ReadOrWrite);


	*(DWORD**)0x008218B2 = &hookDirectInputAddress;
	printf("Patching the DirectInput8Create call\n");


	HookFunc(0x0055D742, game_handle_game_states, 0, "Hooking handle_game_states");

	HookFunc(0x00421128, sub_41F9D0_hook, 0, "Hooking sub_41F9D0");


	/*
	WriteDWORD(0x00877524, ai_hero_base_state_check_transition_hook, "Hooking check_transition for peter hooded");
	WriteDWORD(0x00877560, ai_hero_base_state_check_transition_hook, "Hooking check_transition for spider-man");
	WriteDWORD(0x0087759C, ai_hero_base_state_check_transition_hook, "Hooking check_transition for venom");
	*/

	HookFunc(0x00478DBF, get_info_node_hook, 0, "Hook get_info_node to get player ptr");


	WriteDWORD(0x0089C710, slf__create_progression_menu_entry, "Hooking first ocurrence of create_progession_menu_entry");
	WriteDWORD(0x0089C718, slf__create_progression_menu_entry, "Hooking second  ocurrence of create_progession_menu_entry");


	WriteDWORD(0x0089AF70, slf__create_debug_menu_entry, "Hooking first ocurrence of create_debug_menu_entry");
	WriteDWORD(0x0089C708, slf__create_debug_menu_entry, "Hooking second  ocurrence of create_debug_menu_entry");


	HookFunc(0x005AD77D, construct_client_script_libs_hook, 0, "Hooking construct_client_script_libs to inject my vm");

	WriteDWORD(0x0089C720, slf__destroy_debug_menu_entry__debug_menu_entry, "Hooking destroy_debug_menu_entry");
	WriteDWORD(0x0089C750, slf__debug_menu_entry__set_handler__str, "Hooking set_handler");

	//HookFunc(0x0054C89C, resource_pack_streamer_load_internal_hook, 0, "Hooking resource_pack_streamer::load_internal to inject interior loading");

	//HookFunc(0x005B87E0, os_developer_options, 1, "Hooking os_developer_options::get_flag");

	/*

	DWORD* windowHandler = 0x005AC48B;
	*windowHandler = WindowHandler;

	DWORD* otherHandler = 0x0076D6D1;
	*otherHandler = 0;

	*/


#ifdef _DEBUG
	hook_slf_vtables();
#endif

}

void close_debug() {
	debug_enabled = 0;
	game_unpause(g_game_ptr);
}

void handle_debug_entry(debug_menu_entry* entry) {
	current_menu = entry->data;
}

typedef char (__fastcall *entity_tracker_manager_get_the_arrow_target_pos_ptr)(DWORD* this, void* edx, DWORD* a2);
entity_tracker_manager_get_the_arrow_target_pos_ptr entity_tracker_manager_get_the_arrow_target_pos = (void*)0x0062EE10;

void handle_warp_entry(debug_menu_entry* entry) {
	
	float position[] = {
		0, -0, 1, 0,
		1, -0, -0, 0,
		0, 1, 0, 0,
		-203, 20, 430, 1
	};

	/*
	DWORD arg1 = *(DWORD*)0x96C158;
	DWORD* some_ptr = ai_ai_core_get_info_node(ai_current_player[5], NULL, arg1, 1);
	printf("WHYYYY %08X %08X\n", fancy_player_ptr, some_ptr);
	*/


	float final_pos[3] = { -203, 20, 430 };
	if (entry->data1 == 0) {
		region* cur_region = entry->data;
		final_pos[0] = cur_region->x;
		final_pos[1] = cur_region->y;
		final_pos[2] = cur_region->z;
		unlock_region(cur_region);
	}
	else {
		int res = entity_tracker_manager_get_the_arrow_target_pos( *(*(DWORD***)0x937B18 + 21), NULL, (void*)final_pos);
		if (!res)
			return;
	}

	position[12] = final_pos[0];
	position[13] = final_pos[1];
	position[14] = final_pos[2];

	close_debug();
	entity_teleport_abs_po(fancy_player_ptr[3], position, 1);
}

void handle_char_select_entry(debug_menu_entry* entry) {

	DWORD* some_number = (*(DWORD**)g_world_ptr) + 142;

	while (*some_number) {
		//printf("some_number %d\n", *some_number);
		world_dynamics_system_remove_player(*(DWORD**)g_world_ptr, NULL, *some_number - 1);
	}

	debug_enabled = 0;
	changing_model = 2;
	current_costume = entry->text;

}


void handle_options_select_entry(debug_menu_entry* entry) {

	BYTE* val = entry->data;
	*val = !*val;
}

typedef void* (__fastcall* script_instance_add_thread_ptr)(script_instance* this, void* edx, vm_executable* a1, void* a2);
script_instance_add_thread_ptr script_instance_add_thread = (void*)0x005AAD00;

void handle_progression_select_entry(debug_menu_entry* entry) {

	script_instance* instance = entry->data;
	int functionid = (int)entry->data1;

	DWORD addr = (DWORD)entry;

	script_instance_add_thread(instance, NULL, instance->object->vmexecutable[functionid], &addr);



	close_debug();
}

void handle_script_select_entry(debug_menu_entry* entry) {
	handle_progression_select_entry(entry);
}


void handle_distriction_variants_select_entry(debug_menu_entry* entry, custom_key_type key_type) {

	region* reg = entry->data;
	void* terrain_ptr = *(*(DWORD***)g_world_ptr + 0x6B);
	int variants = reg->variants;
	int current_variant = region_get_district_variant(reg);
	DWORD district_id = reg->district_id;

	switch (key_type) {

	case LEFT:
		terrain_set_district_variant(terrain_ptr, NULL, district_id, modulo(current_variant-1, variants), 1);
		break;
	case RIGHT:
		terrain_set_district_variant(terrain_ptr, NULL, district_id, modulo(current_variant+1, variants), 1);
		break;
	default:
		return;
	}
}

void setup_debug_menu() {

	start_debug = create_menu("Debug Menu", close_debug, (menu_handler_function)handle_debug_entry, 2);
	warp_menu = create_menu("Warp", goto_start_debug, (menu_handler_function)handle_warp_entry, 300);
	char_select_menu = create_menu("Char Select", goto_start_debug, (menu_handler_function)handle_char_select_entry, 5);
	options_menu = create_menu("Options", goto_start_debug, (menu_handler_function)handle_options_select_entry, 2);
	script_menu = create_menu("Script", goto_start_debug, (menu_handler_function)handle_script_select_entry, 50);
	progression_menu = create_menu("Progression", goto_start_debug, (menu_handler_function)handle_progression_select_entry, 10);
	district_variants_menu = create_menu("District variants", goto_start_debug, (menu_handler_function)handle_distriction_variants_select_entry, 15);


	debug_menu_entry warp_entry = { "Warp", NORMAL, warp_menu };
	debug_menu_entry char_select = { "Char Select", NORMAL, char_select_menu };
	debug_menu_entry options_entry = { "Options", NORMAL, options_menu };
	debug_menu_entry script_entry = { "Script", NORMAL, script_menu };
	debug_menu_entry progression_entry = { "Progression", NORMAL, progression_menu };
	debug_menu_entry district_entry = { "District variants", NORMAL, district_variants_menu };

	add_debug_menu_entry(start_debug, &warp_entry);
	add_debug_menu_entry(start_debug, &district_entry);
	add_debug_menu_entry(start_debug, &char_select);
	add_debug_menu_entry(start_debug, &options_entry);
	add_debug_menu_entry(start_debug, &script_entry);
	add_debug_menu_entry(start_debug, &progression_entry);

	char* costumes[] = {
		"ultimate_spiderman",
		"arachno_man_costume",
		"usm_wrestling_costume",
		"usm_blacksuit_costume",
		"peter_parker",
		"peter_parker_costume",
		"peter_hooded",
		"peter_hooded_costume",
		"venom",
		"venom_spider"
	};


	for (int i = 0; i < sizeof(costumes) / sizeof(char*); i++) {
		debug_menu_entry char_entry;
		char_entry.entry_type = NORMAL;
		strcpy(char_entry.text, costumes[i]);

		add_debug_menu_entry(char_select_menu, &char_entry);
	}


	debug_menu_entry show_fps = { "Show FPS", BOOLEAN_E, (void*)0x975848 };
	debug_menu_entry memory_info = { "Memory Info", BOOLEAN_E, (void*)0x975849 };
	

	add_debug_menu_entry(options_menu, &show_fps);
	add_debug_menu_entry(options_menu, &memory_info);


	/*




	for (int i = 0; i < 5; i++) {

		debug_menu_entry asdf;
		sprintf(asdf.text, "entry %d", i);
		printf("AQUI %s\n", asdf.text);

		add_debug_menu_entry(start_debug, &asdf);
	}


	add_debug_menu_entry(start_debug, &teste);
	*/
}


BOOL WINAPI DllMain(HINSTANCE hInstDll, DWORD fdwReason, LPVOID reserverd) {



	if (sizeof(region) != 0x134) {
		__debugbreak();

	}

	memset(keys, 0, sizeof(keys));
	if (fdwReason == DLL_PROCESS_ATTACH) {
		AllocConsole();



		if (!freopen("CONOUT$", "w", stdout)) {
			MessageBoxA(NULL, "Error", "Couldn't allocate console...Closing", 0);
			return FALSE;
		}

		setup_debug_menu();
		set_text_writeable();
		set_rdata_writeable();
		install_patches();

	}
	else if (fdwReason == DLL_PROCESS_DETACH)
		FreeConsole();

	return TRUE;
}

int main() {
	return 0;
}