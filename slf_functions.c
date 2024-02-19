#include <stdio.h>
#include "slf.h"
/*
int __fastcall slf_deconstructor(void* this, void* edx, void *arg) {

	printf("Calling deconstructor of #name\n");

	typedef int (__fastcall *original_ptr)(void*, void*, void*);
	original_ptr original = (void*)address;
	return original(this, edx, arg);
}

int __fastcall slf_call(void* this, void* edx, void *arg, void* arg1) {

	printf("Calling action of #name\n");

	typedef int (__fastcall *original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)address;
	return original(this, edx, arg, arg1);
}
*/



int __fastcall slf_deconstructor_abs_delay_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of abs_delay_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_abs_delay_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of abs_delay_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663170;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_acos_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of acos_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_acos_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of acos_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663F80;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_2d_debug_str_vector3d_vector3d_num_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_2d_debug_str_vector3d_vector3d_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_2d_debug_str_vector3d_vector3d_num_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_2d_debug_str_vector3d_vector3d_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663360;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_2d_debug_str_vector3d_vector3d_num_str_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_2d_debug_str_vector3d_vector3d_num_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

typedef struct vec3 {
	DWORD x, y, z;
}vec3;


#pragma pack(push, 1)
typedef struct add_2d_debug_str {
	vec3 unk[2];
	DWORD unk1;
	const char* name;
	DWORD unk2;
}add_2d_debug_str;
#pragma pack(pop)


int __fastcall slf_action_add_2d_debug_str_vector3d_vector3d_num_str_num(void* this, void* edx, void* arg, void* arg1) {

	slf* function = arg;
	vm_stack_pop(function, 36);
	const add_2d_debug_str* args = (void*)function->stack_ptr;
	vm_stack_add_offset(function, 36);

	printf("Calling action of add_2d_debug_str_vector3d_vector3d_num_str_num %s\n", args->name);

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663760;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_3d_debug_str_vector3d_vector3d_num_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_3d_debug_str_vector3d_vector3d_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_3d_debug_str_vector3d_vector3d_num_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_3d_debug_str_vector3d_vector3d_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663360;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_civilian_info_vector3d_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_civilian_info_vector3d_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_civilian_info_vector3d_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_civilian_info_vector3d_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00680FE0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_civilian_info_entity_entity_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_civilian_info_entity_entity_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_civilian_info_entity_entity_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_civilian_info_entity_entity_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006810F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_debug_cyl_vector3d_vector3d_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_debug_cyl_vector3d_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_debug_cyl_vector3d_vector3d_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_debug_cyl_vector3d_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663390;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_debug_cyl_vector3d_vector3d_num_vector3d_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_debug_cyl_vector3d_vector3d_num_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_debug_cyl_vector3d_vector3d_num_vector3d_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_debug_cyl_vector3d_vector3d_num_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006633A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_debug_line_vector3d_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_debug_line_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_debug_line_vector3d_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_debug_line_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663370;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_debug_line_vector3d_vector3d_vector3d_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_debug_line_vector3d_vector3d_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_debug_line_vector3d_vector3d_vector3d_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_debug_line_vector3d_vector3d_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663380;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_debug_sphere_vector3d_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_debug_sphere_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_debug_sphere_vector3d_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_debug_sphere_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677930;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_debug_sphere_vector3d_num_vector3d_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_debug_sphere_vector3d_num_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_debug_sphere_vector3d_num_vector3d_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_debug_sphere_vector3d_num_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663360;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_glass_house_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_glass_house_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_glass_house_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_glass_house_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006798A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_glass_house_str_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_glass_house_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_glass_house_str_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_glass_house_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00661FC0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_glass_house_str_num_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_glass_house_str_num_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_glass_house_str_num_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_glass_house_str_num_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662240;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_glass_house_str_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_glass_house_str_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_glass_house_str_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_glass_house_str_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662100;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_to_console_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_to_console_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_to_console_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_to_console_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_add_traffic_model_num_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of add_traffic_model_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_add_traffic_model_num_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of add_traffic_model_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677770;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_allow_suspend_thread_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of allow_suspend_thread_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_allow_suspend_thread_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of allow_suspend_thread_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006627C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_angle_between_vector3d_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of angle_between_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_angle_between_vector3d_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of angle_between_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672070;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_apply_donut_damage_vector3d_num_num_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of apply_donut_damage_vector3d_num_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_apply_donut_damage_vector3d_num_num_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of apply_donut_damage_vector3d_num_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663460;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_apply_radius_damage_vector3d_num_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of apply_radius_damage_vector3d_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_apply_radius_damage_vector3d_num_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of apply_radius_damage_vector3d_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006633E0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_apply_radius_subdue_vector3d_num_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of apply_radius_subdue_vector3d_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_apply_radius_subdue_vector3d_num_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of apply_radius_subdue_vector3d_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006634E0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_assert_num_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of assert_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_assert_num_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of assert_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_attach_decal_str_vector3d_num_vector3d_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of attach_decal_str_vector3d_num_vector3d_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_attach_decal_str_vector3d_num_vector3d_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of attach_decal_str_vector3d_num_vector3d_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006643B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_begin_screen_recording_str_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of begin_screen_recording_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_begin_screen_recording_str_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of begin_screen_recording_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067E740;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_blackscreen_off_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of blackscreen_off_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_blackscreen_off_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of blackscreen_off_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673850;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_blackscreen_on_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of blackscreen_on_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_blackscreen_on_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of blackscreen_on_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673800;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_bring_up_dialog_box_num_num_elip(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of bring_up_dialog_box_num_num_elip\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_bring_up_dialog_box_num_num_elip(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of bring_up_dialog_box_num_num_elip\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673080;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_bring_up_dialog_box_debug_str_num_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of bring_up_dialog_box_debug_str_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_bring_up_dialog_box_debug_str_num_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of bring_up_dialog_box_debug_str_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673490;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_bring_up_dialog_box_title_num_num_num_elip(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of bring_up_dialog_box_title_num_num_num_elip\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_bring_up_dialog_box_title_num_num_num_elip(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of bring_up_dialog_box_title_num_num_num_elip\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673240;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_bring_up_medal_award_box_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of bring_up_medal_award_box_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_bring_up_medal_award_box_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of bring_up_medal_award_box_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006726E0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_bring_up_race_announcer(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of bring_up_race_announcer\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_bring_up_race_announcer(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of bring_up_race_announcer\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006726B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_calc_launch_vector_vector3d_vector3d_num_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of calc_launch_vector_vector3d_vector3d_num_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_calc_launch_vector_vector3d_vector3d_num_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of calc_launch_vector_vector3d_vector3d_num_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006641D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_can_load_pack_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of can_load_pack_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_can_load_pack_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of can_load_pack_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00680C60;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_chase_cam(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of chase_cam\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_chase_cam(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of chase_cam\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067BBD0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_clear_all_grenades(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of clear_all_grenades\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_clear_all_grenades(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of clear_all_grenades\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006640D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_clear_civilians_within_radius_vector3d_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of clear_civilians_within_radius_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_clear_civilians_within_radius_vector3d_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of clear_civilians_within_radius_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677930;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_clear_controls(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of clear_controls\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_clear_controls(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of clear_controls\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673B70;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_clear_debug_all(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of clear_debug_all\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_clear_debug_all(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of clear_debug_all\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_clear_debug_cyls(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of clear_debug_cyls\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_clear_debug_cyls(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of clear_debug_cyls\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_clear_debug_lines(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of clear_debug_lines\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_clear_debug_lines(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of clear_debug_lines\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_clear_debug_spheres(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of clear_debug_spheres\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_clear_debug_spheres(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of clear_debug_spheres\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_clear_screen(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of clear_screen\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_clear_screen(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of clear_screen\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006640C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_clear_traffic_within_radius_vector3d_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of clear_traffic_within_radius_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_clear_traffic_within_radius_vector3d_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of clear_traffic_within_radius_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006778F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_col_check_vector3d_vector3d_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of col_check_vector3d_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_col_check_vector3d_vector3d_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of col_check_vector3d_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663770;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_console_exec_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of console_exec_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_console_exec_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of console_exec_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_copy_vector3d_list_vector3d_list_vector3d_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of copy_vector3d_list_vector3d_list_vector3d_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_copy_vector3d_list_vector3d_list_vector3d_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of copy_vector3d_list_vector3d_list_vector3d_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00686E00;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_cos_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of cos_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_cos_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of cos_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663F20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_beam(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_beam\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_beam(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_beam\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067AD20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_credits(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_credits\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_credits(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_credits\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672630;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_cut_scene_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_cut_scene_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_cut_scene_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_cut_scene_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00670AF0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_debug_menu_entry_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_debug_menu_entry_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_debug_menu_entry_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_debug_menu_entry_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067C1E0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_debug_menu_entry_str_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_debug_menu_entry_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_debug_menu_entry_str_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_debug_menu_entry_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00678210;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_decal_str_vector3d_num_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_decal_str_vector3d_num_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_decal_str_vector3d_num_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_decal_str_vector3d_num_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00664340;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_entity_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_entity_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_entity_str(void* this, void* edx, void* arg, void* arg1) {

	slf* function = arg;
	vm_stack_pop(function, 4);
	const char* name = *(const char**)function->stack_ptr;
	vm_stack_add_offset(function, 4);

	printf("Calling action of create_entity_str %s\n", name);

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067BC10;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_entity_str_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_entity_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_entity_str_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_entity_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067BD40;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_entity_in_hero_region_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_entity_in_hero_region_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_entity_in_hero_region_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_entity_in_hero_region_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067BEC0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_entity_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_entity_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_entity_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_entity_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006860D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_entity_tracker_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_entity_tracker_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_entity_tracker_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_entity_tracker_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677650;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_item_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_item_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_item_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_item_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067E190;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_line_info_vector3d_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_line_info_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_line_info_vector3d_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_line_info_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067E440;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_lofi_stereo_sound_inst_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_lofi_stereo_sound_inst_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_lofi_stereo_sound_inst_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_lofi_stereo_sound_inst_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067EBF0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_num_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_num_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_num_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_num_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00685FD0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_pfx_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_pfx_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_pfx_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_pfx_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00678E20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_pfx_str_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_pfx_str_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_pfx_str_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_pfx_str_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00678F30;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_polytube(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_polytube\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_polytube(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_polytube\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00680510;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_polytube_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_polytube_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_polytube_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_polytube_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006805E0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_progression_menu_entry_str_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_progression_menu_entry_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_progression_menu_entry_str_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_progression_menu_entry_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00678210;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_sound_inst(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_sound_inst\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_sound_inst(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_sound_inst\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067E840;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_sound_inst_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_sound_inst_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_sound_inst_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_sound_inst_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067E920;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_stompable_music_sound_inst_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_stompable_music_sound_inst_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_stompable_music_sound_inst_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_stompable_music_sound_inst_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067EA10;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_str_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_str_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_str_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_str_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00686180;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_taunt_entry_entity_str_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_taunt_entry_entity_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_taunt_entry_entity_str_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_taunt_entry_entity_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677B80;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_taunt_exchange_entity_entity_num_num_num_num_elip(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_taunt_exchange_entity_entity_num_num_num_num_elip\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_taunt_exchange_entity_entity_num_num_num_num_elip(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_taunt_exchange_entity_entity_num_num_num_num_elip\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00686330;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_taunt_exchange_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_taunt_exchange_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_taunt_exchange_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_taunt_exchange_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00686260;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_threat_assessment_meter(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_threat_assessment_meter\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_threat_assessment_meter(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_threat_assessment_meter\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00678030;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_time_limited_entity_str_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_time_limited_entity_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_time_limited_entity_str_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_time_limited_entity_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00668C60;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_trigger_entity_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_trigger_entity_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_trigger_entity_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_trigger_entity_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067FC50;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_trigger_str_vector3d_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_trigger_str_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_trigger_str_vector3d_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_trigger_str_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067FB60;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_trigger_vector3d_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_trigger_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_trigger_vector3d_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_trigger_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067FA80;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_unstompable_script_cutscene_sound_inst_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_unstompable_script_cutscene_sound_inst_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_unstompable_script_cutscene_sound_inst_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_unstompable_script_cutscene_sound_inst_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067EB00;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_create_vector3d_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of create_vector3d_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_create_vector3d_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of create_vector3d_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00685F20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_cross_vector3d_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of cross_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_cross_vector3d_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of cross_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00671F70;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_debug_breakpoint(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of debug_breakpoint\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_debug_breakpoint(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of debug_breakpoint\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_debug_print_num_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of debug_print_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_debug_print_num_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of debug_print_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_debug_print_num_vector3d_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of debug_print_num_vector3d_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_debug_print_num_vector3d_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of debug_print_num_vector3d_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00661F50;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_debug_print_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of debug_print_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_debug_print_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of debug_print_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_debug_print_set_background_color_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of debug_print_set_background_color_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_debug_print_set_background_color_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of debug_print_set_background_color_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00661F60;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_delay_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of delay_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_delay_num(void* this, void* edx, void* arg, void* arg1) {

	//printf("Calling action of delay_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663120;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_credits(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_credits\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_credits(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_credits\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672650;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_debug_menu_entry_debug_menu_entry(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_debug_menu_entry_debug_menu_entry\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_debug_menu_entry_debug_menu_entry(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_debug_menu_entry_debug_menu_entry\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_entity_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_entity_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_entity_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_entity_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067C010;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_entity_list_entity_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_entity_list_entity_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_entity_list_entity_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_entity_list_entity_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00686F10;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_entity_tracker_entity_tracker(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_entity_tracker_entity_tracker\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_entity_tracker_entity_tracker(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_entity_tracker_entity_tracker\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677720;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_line_info_line_info(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_line_info_line_info\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_line_info_line_info(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_line_info_line_info\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006705C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_num_list_num_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_num_list_num_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_num_list_num_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_num_list_num_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00686080;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_pfx_pfx(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_pfx_pfx\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_pfx_pfx(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_pfx_pfx\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00687870;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_str_list_str_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_str_list_str_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_str_list_str_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_str_list_str_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006878B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_taunt_entry_taunt_entry(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_taunt_entry_taunt_entry\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_taunt_entry_taunt_entry(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_taunt_entry_taunt_entry\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677C70;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_taunt_exchange_taunt_exchange(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_taunt_exchange_taunt_exchange\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_taunt_exchange_taunt_exchange(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_taunt_exchange_taunt_exchange\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00686B90;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_taunt_exchange_list_taunt_exchange_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_taunt_exchange_list_taunt_exchange_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_taunt_exchange_list_taunt_exchange_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_taunt_exchange_list_taunt_exchange_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00686B00;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_threat_assessment_meter_tam(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_threat_assessment_meter_tam\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_threat_assessment_meter_tam(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_threat_assessment_meter_tam\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00678060;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_trigger_trigger(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_trigger_trigger\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_trigger_trigger(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_trigger_trigger\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067FD20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_destroy_vector3d_list_vector3d_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of destroy_vector3d_list_vector3d_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_destroy_vector3d_list_vector3d_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of destroy_vector3d_list_vector3d_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00686E30;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_dilated_delay_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of dilated_delay_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_dilated_delay_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of dilated_delay_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006631D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_disable_marky_cam_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of disable_marky_cam_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_disable_marky_cam_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of disable_marky_cam_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679A00;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_disable_nearby_occlusion_only_obb_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of disable_nearby_occlusion_only_obb_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_disable_nearby_occlusion_only_obb_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of disable_nearby_occlusion_only_obb_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662AA0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_disable_player_shadows(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of disable_player_shadows\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_disable_player_shadows(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of disable_player_shadows\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662B10;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_disable_subtitles(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of disable_subtitles\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_disable_subtitles(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of disable_subtitles\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006640B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_disable_vibrator(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of disable_vibrator\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_disable_vibrator(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of disable_vibrator\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A600;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_disable_zoom_map_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of disable_zoom_map_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_disable_zoom_map_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of disable_zoom_map_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672BB0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_distance3d_vector3d_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of distance3d_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_distance3d_vector3d_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of distance3d_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672010;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_distance_chase_widget_set_pos_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of distance_chase_widget_set_pos_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_distance_chase_widget_set_pos_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of distance_chase_widget_set_pos_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006729F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_distance_chase_widget_turn_off(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of distance_chase_widget_turn_off\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_distance_chase_widget_turn_off(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of distance_chase_widget_turn_off\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006729D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_distance_chase_widget_turn_on_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of distance_chase_widget_turn_on_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_distance_chase_widget_turn_on_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of distance_chase_widget_turn_on_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672980;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_distance_race_widget_set_boss_pos_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of distance_race_widget_set_boss_pos_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_distance_race_widget_set_boss_pos_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of distance_race_widget_set_boss_pos_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672A90;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_distance_race_widget_set_hero_pos_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of distance_race_widget_set_hero_pos_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_distance_race_widget_set_hero_pos_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of distance_race_widget_set_hero_pos_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672A60;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_distance_race_widget_set_types_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of distance_race_widget_set_types_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_distance_race_widget_set_types_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of distance_race_widget_set_types_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672AC0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_distance_race_widget_turn_off(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of distance_race_widget_turn_off\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_distance_race_widget_turn_off(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of distance_race_widget_turn_off\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672A40;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_distance_race_widget_turn_on(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of distance_race_widget_turn_on\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_distance_race_widget_turn_on(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of distance_race_widget_turn_on\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672A20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_district_id_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of district_id_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_district_id_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of district_id_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006769B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_district_name_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of district_name_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_district_name_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of district_name_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00680F70;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_dot_vector3d_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of dot_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_dot_vector3d_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of dot_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00671F30;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_dump_searchable_region_list_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of dump_searchable_region_list_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_dump_searchable_region_list_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of dump_searchable_region_list_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_ai_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_ai_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_ai_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_ai_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662F90;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_civilians_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_civilians_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_civilians_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_civilians_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677940;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_controls_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_controls_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_controls_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_controls_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673AF0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_entity_fading_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_entity_fading_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_entity_fading_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_entity_fading_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00669AC0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_interface_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_interface_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_interface_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_interface_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662F40;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_marky_cam_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_marky_cam_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_marky_cam_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_marky_cam_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006799B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_mini_map_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_mini_map_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_mini_map_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_mini_map_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672B60;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_nearby_occlusion_only_obb_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_nearby_occlusion_only_obb_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_nearby_occlusion_only_obb_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_nearby_occlusion_only_obb_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662A70;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_obb_vector3d_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_obb_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_obb_vector3d_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_obb_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662690;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_pause_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_pause_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_pause_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_pause_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662E50;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_physics_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_physics_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_physics_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_physics_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663020;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_player_shadows(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_player_shadows\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_player_shadows(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_player_shadows\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662B20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_pois_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_pois_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_pois_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_pois_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_quad_path_connector_district_num_district_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_quad_path_connector_district_num_district_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_quad_path_connector_district_num_district_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_quad_path_connector_district_num_district_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662510;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_subtitles(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_subtitles\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_subtitles(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_subtitles\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006640A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_tokens_of_type_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_tokens_of_type_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_tokens_of_type_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_tokens_of_type_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0066F420;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_traffic_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_traffic_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_traffic_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_traffic_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006779C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_user_camera_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_user_camera_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_user_camera_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_user_camera_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662A10;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_enable_vibrator(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of enable_vibrator\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_enable_vibrator(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of enable_vibrator\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A620;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_end_current_patrol(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of end_current_patrol\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_end_current_patrol(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of end_current_patrol\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676EC0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_end_cut_scenes(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of end_cut_scenes\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_end_cut_scenes(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of end_cut_scenes\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00670C80;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_end_screen_recording(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of end_screen_recording\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_end_screen_recording(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of end_screen_recording\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067E7E0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_entity_col_check_entity_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of entity_col_check_entity_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_entity_col_check_entity_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of entity_col_check_entity_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006639D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_entity_exists_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of entity_exists_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_entity_exists_str(void* this, void* edx, void* arg, void* arg1) {

	slf* function = arg;
	vm_stack_pop(function, 4);
	const char* name = *(const char**)function->stack_ptr;
	vm_stack_add_offset(function, 4);


	printf("Calling action of entity_exists_str %s\n", name);

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00668BF0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_entity_get_entity_tracker_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of entity_get_entity_tracker_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_entity_get_entity_tracker_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of entity_get_entity_tracker_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006697F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_entity_has_entity_tracker_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of entity_has_entity_tracker_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_entity_has_entity_tracker_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of entity_has_entity_tracker_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00669790;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_exit_water_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of exit_water_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_exit_water_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of exit_water_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00682380;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_find_closest_point_on_a_path_to_point_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of find_closest_point_on_a_path_to_point_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_find_closest_point_on_a_path_to_point_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of find_closest_point_on_a_path_to_point_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006624B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_find_district_for_point_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of find_district_for_point_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_find_district_for_point_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of find_district_for_point_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663560;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_find_entities_in_radius_entity_list_vector3d_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of find_entities_in_radius_entity_list_vector3d_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_find_entities_in_radius_entity_list_vector3d_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of find_entities_in_radius_entity_list_vector3d_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00686C60;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_find_entity_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of find_entity_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_find_entity_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of find_entity_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00668B90;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_find_innermost_district_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of find_innermost_district_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_find_innermost_district_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of find_innermost_district_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006635A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_find_outermost_district_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of find_outermost_district_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_find_outermost_district_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of find_outermost_district_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006635E0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_find_trigger_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of find_trigger_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_find_trigger_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of find_trigger_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067F9B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_find_trigger_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of find_trigger_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_find_trigger_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of find_trigger_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067F900;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_find_trigger_in_district_district_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of find_trigger_in_district_district_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_find_trigger_in_district_district_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of find_trigger_in_district_district_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067FA00;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_float_random_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of float_random_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_float_random_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of float_random_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663300;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_force_mission_district_str_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of force_mission_district_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_force_mission_district_str_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of force_mission_district_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006765D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_force_streamer_refresh(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of force_streamer_refresh\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_force_streamer_refresh(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of force_streamer_refresh\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676B70;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_format_time_string_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of format_time_string_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_format_time_string_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of format_time_string_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006736A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_freeze_hero_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of freeze_hero_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_freeze_hero_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of freeze_hero_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679A50;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_game_ini_get_flag_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of game_ini_get_flag_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_game_ini_get_flag_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of game_ini_get_flag_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067AC20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_game_time_advance_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of game_time_advance_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_game_time_advance_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of game_time_advance_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676D30;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_all_execs_thread_count_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_all_execs_thread_count_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_all_execs_thread_count_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_all_execs_thread_count_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006824D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_all_instances_thread_count_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_all_instances_thread_count_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_all_instances_thread_count_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_all_instances_thread_count_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00681500;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_attacker_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_attacker_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_attacker_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_attacker_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006644F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_attacker_member(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_attacker_member\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_attacker_member(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_attacker_member\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006644F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_available_stack_size(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_available_stack_size\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_available_stack_size(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_available_stack_size\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676E30;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_character_packname_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_character_packname_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_character_packname_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_character_packname_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676270;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_closest_point_on_lane_with_facing_num_vector3d_vector3d_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_closest_point_on_lane_with_facing_num_vector3d_vector3d_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_closest_point_on_lane_with_facing_num_vector3d_vector3d_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_closest_point_on_lane_with_facing_num_vector3d_vector3d_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00687180;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_col_hit_ent(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_col_hit_ent\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_col_hit_ent(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_col_hit_ent\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A6E0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_col_hit_norm(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_col_hit_norm\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_col_hit_norm(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_col_hit_norm\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663990;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_col_hit_pos(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_col_hit_pos\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_col_hit_pos(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_col_hit_pos\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663950;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_control_state_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_control_state_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_control_state_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_control_state_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A690;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_control_trigger_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_control_trigger_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_control_trigger_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_control_trigger_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A640;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_current_instance_thread_count_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_current_instance_thread_count_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_current_instance_thread_count_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_current_instance_thread_count_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00681490;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_current_view_cam_pos(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_current_view_cam_pos\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_current_view_cam_pos(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_current_view_cam_pos\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662930;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_current_view_cam_x_facing(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_current_view_cam_x_facing\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_current_view_cam_x_facing(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_current_view_cam_x_facing\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662810;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_current_view_cam_y_facing(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_current_view_cam_y_facing\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_current_view_cam_y_facing(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_current_view_cam_y_facing\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662870;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_current_view_cam_z_facing(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_current_view_cam_z_facing\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_current_view_cam_z_facing(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_current_view_cam_z_facing\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006628D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_fog_color(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_fog_color\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_fog_color(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_fog_color\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663E60;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_fog_distance(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_fog_distance\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_fog_distance(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_fog_distance\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663EC0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_game_info_num_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_game_info_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_game_info_num_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_game_info_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663C00;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_game_info_str_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_game_info_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_game_info_str_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_game_info_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A7F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_glam_cam_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_glam_cam_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_glam_cam_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_glam_cam_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00670930;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_global_time_dilation(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_global_time_dilation\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_global_time_dilation(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_global_time_dilation\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663A60;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_ini_flag_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_ini_flag_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_ini_flag_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_ini_flag_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067AC20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_ini_num_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_ini_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_ini_num_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_ini_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067AB70;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_int_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_int_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_int_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_int_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00664060;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_mission_camera_marker_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_mission_camera_marker_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_mission_camera_marker_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_mission_camera_marker_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00682F80;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_mission_camera_transform_marker_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_mission_camera_transform_marker_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_mission_camera_transform_marker_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_mission_camera_transform_marker_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00683040;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_mission_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_mission_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_mission_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_mission_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006764E0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_mission_key_posfacing3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_mission_key_posfacing3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_mission_key_posfacing3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_mission_key_posfacing3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676330;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_mission_key_position(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_mission_key_position\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_mission_key_position(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_mission_key_position\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006762E0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_mission_marker_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_mission_marker_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_mission_marker_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_mission_marker_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00682F10;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_mission_nums(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_mission_nums\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_mission_nums(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_mission_nums\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006765A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_mission_patrol_waypoint(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_mission_patrol_waypoint\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_mission_patrol_waypoint(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_mission_patrol_waypoint\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006764A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_mission_positions(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_mission_positions\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_mission_positions(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_mission_positions\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676540;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_mission_strings(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_mission_strings\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_mission_strings(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_mission_strings\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676570;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_mission_transform_marker_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_mission_transform_marker_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_mission_transform_marker_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_mission_transform_marker_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00682FE0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_mission_trigger(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_mission_trigger\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_mission_trigger(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_mission_trigger\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676510;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_missions_key_position_by_index_district_str_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_missions_key_position_by_index_district_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_missions_key_position_by_index_district_str_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_missions_key_position_by_index_district_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676620;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_missions_nums_by_index_district_str_num_num_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_missions_nums_by_index_district_str_num_num_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_missions_nums_by_index_district_str_num_num_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_missions_nums_by_index_district_str_num_num_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00682EB0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_missions_patrol_waypoint_by_index_district_str_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_missions_patrol_waypoint_by_index_district_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_missions_patrol_waypoint_by_index_district_str_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_missions_patrol_waypoint_by_index_district_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006766A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_neighborhood_name_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_neighborhood_name_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_neighborhood_name_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_neighborhood_name_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677220;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_num_free_slots_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_num_free_slots_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_num_free_slots_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_num_free_slots_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676720;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_num_mission_transform_marker(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_num_mission_transform_marker\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_num_mission_transform_marker(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_num_mission_transform_marker\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00680F10;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_pack_group_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_pack_group_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_pack_group_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_pack_group_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00680B80;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_pack_size_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_pack_size_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_pack_size_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_pack_size_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676D70;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_patrol_difficulty_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_patrol_difficulty_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_patrol_difficulty_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_patrol_difficulty_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677100;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_patrol_node_position_by_index_str_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_patrol_node_position_by_index_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_patrol_node_position_by_index_str_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_patrol_node_position_by_index_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677080;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_patrol_start_position_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_patrol_start_position_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_patrol_start_position_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_patrol_start_position_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677010;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_patrol_unlock_threshold_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_patrol_unlock_threshold_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_patrol_unlock_threshold_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_patrol_unlock_threshold_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677160;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_platform(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_platform\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_platform(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_platform\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00661F20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_render_opt_num_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_render_opt_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_render_opt_num_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_render_opt_num_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663DD0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_spider_reflexes_spiderman_time_dilation(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_spider_reflexes_spiderman_time_dilation\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_spider_reflexes_spiderman_time_dilation(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_spider_reflexes_spiderman_time_dilation\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679390;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_spider_reflexes_world_time_dilation(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_spider_reflexes_world_time_dilation\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_spider_reflexes_world_time_dilation(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_spider_reflexes_world_time_dilation\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679390;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_time_inc(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_time_inc\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_time_inc(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_time_inc\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006633B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_time_of_day(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_time_of_day\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_time_of_day(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_time_of_day\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00664150;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_time_of_day_rate(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_time_of_day_rate\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_time_of_day_rate(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_time_of_day_rate\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00664110;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_token_index_from_id_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_token_index_from_id_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_token_index_from_id_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_token_index_from_id_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0066F470;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_get_traffic_spawn_point_near_camera_vector3d_list(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of get_traffic_spawn_point_near_camera_vector3d_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_get_traffic_spawn_point_near_camera_vector3d_list(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of get_traffic_spawn_point_near_camera_vector3d_list\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00686BE0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_greater_than_or_equal_rounded_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of greater_than_or_equal_rounded_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_greater_than_or_equal_rounded_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of greater_than_or_equal_rounded_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673750;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_hard_break(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of hard_break\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_hard_break(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of hard_break\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_has_substring_str_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of has_substring_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_has_substring_str_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of has_substring_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006625D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_hero(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of hero\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_hero(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of hero\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067BBA0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_hero_exists(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of hero_exists\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_hero_exists(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of hero_exists\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00668A10;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_hero_type(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of hero_type\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_hero_type(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of hero_type\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00668A50;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_hide_controller_gauge(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of hide_controller_gauge\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_hide_controller_gauge(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of hide_controller_gauge\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672750;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_initialize_encounter_object(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of initialize_encounter_object\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_initialize_encounter_object(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of initialize_encounter_object\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00664490;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_initialize_encounter_objects(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of initialize_encounter_objects\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_initialize_encounter_objects(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of initialize_encounter_objects\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00664430;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_insert_pack_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of insert_pack_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_insert_pack_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of insert_pack_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006809A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_invoke_pause_menu_unlockables(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of invoke_pause_menu_unlockables\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_invoke_pause_menu_unlockables(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of invoke_pause_menu_unlockables\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006737C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_ai_enabled(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_ai_enabled\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_ai_enabled(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_ai_enabled\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662FE0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_cut_scene_playing(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_cut_scene_playing\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_cut_scene_playing(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_cut_scene_playing\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00670CA0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_district_loaded_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_district_loaded_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_district_loaded_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_district_loaded_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676AB0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_hero_frozen(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_hero_frozen\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_hero_frozen(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_hero_frozen\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679AA0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_hero_peter_parker(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_hero_peter_parker\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_hero_peter_parker(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_hero_peter_parker\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00668B40;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_hero_spidey(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_hero_spidey\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_hero_spidey(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_hero_spidey\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00668AA0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_hero_venom(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_hero_venom\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_hero_venom(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_hero_venom\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00668AF0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_marky_cam_enabled(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_marky_cam_enabled\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_marky_cam_enabled(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_marky_cam_enabled\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662990;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_mission_active(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_mission_active\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_mission_active(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_mission_active\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676F20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_mission_loading(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_mission_loading\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_mission_loading(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_mission_loading\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676F60;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_pack_available_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_pack_available_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_pack_available_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_pack_available_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00680E40;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_pack_loaded_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_pack_loaded_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_pack_loaded_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_pack_loaded_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00680D50;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_pack_pushed_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_pack_pushed_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_pack_pushed_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_pack_pushed_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676190;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_path_graph_inside_glass_house_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_path_graph_inside_glass_house_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_path_graph_inside_glass_house_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_path_graph_inside_glass_house_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00664590;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_patrol_active(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_patrol_active\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_patrol_active(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_patrol_active\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676EE0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_patrol_node_empty_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_patrol_node_empty_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_patrol_node_empty_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_patrol_node_empty_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006771C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_paused(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_paused\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_paused(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_paused\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662EA0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_physics_enabled(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_physics_enabled\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_physics_enabled(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_physics_enabled\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663070;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_point_inside_glass_house_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_point_inside_glass_house_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_point_inside_glass_house_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_point_inside_glass_house_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00661F70;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_point_under_water_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_point_under_water_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_point_under_water_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_point_under_water_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00664540;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_is_user_camera_enabled(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of is_user_camera_enabled\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_is_user_camera_enabled(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of is_user_camera_enabled\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006629D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_load_anim_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of load_anim_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_load_anim_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of load_anim_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_load_level_str_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of load_level_str_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_load_level_str_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of load_level_str_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663AD0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_lock_all_districts(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of lock_all_districts\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_lock_all_districts(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of lock_all_districts\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676C10;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_lock_district_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of lock_district_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_lock_district_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of lock_district_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676A70;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_lock_mission_manager_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of lock_mission_manager_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_lock_mission_manager_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of lock_mission_manager_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676FA0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_los_check_vector3d_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of los_check_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_los_check_vector3d_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of los_check_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006813E0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_lower_hotpursuit_indicator_level(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of lower_hotpursuit_indicator_level\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_lower_hotpursuit_indicator_level(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of lower_hotpursuit_indicator_level\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672610;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_malor_vector3d_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of malor_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_malor_vector3d_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of malor_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00664180;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_normal_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of normal_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_normal_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of normal_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00671FD0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_pause_game_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of pause_game_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_pause_game_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of pause_game_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662EE0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_play_credits(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of play_credits\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_play_credits(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of play_credits\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672670;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_play_prerender_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of play_prerender_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_play_prerender_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of play_prerender_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663B60;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_pop_pack_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of pop_pack_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_pop_pack_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of pop_pack_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00680870;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_post_message_str_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of post_message_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_post_message_str_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of post_message_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A460;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_pre_roll_all_pfx_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of pre_roll_all_pfx_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_pre_roll_all_pfx_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of pre_roll_all_pfx_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00664510;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_press_controller_gauge_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of press_controller_gauge_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_press_controller_gauge_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of press_controller_gauge_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672770;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_press_controller_gauge_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of press_controller_gauge_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_press_controller_gauge_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of press_controller_gauge_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006727A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_purge_district_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of purge_district_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_purge_district_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of purge_district_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676BD0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_push_pack_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of push_pack_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_push_pack_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of push_pack_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00680730;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_push_pack_into_district_slot_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of push_pack_into_district_slot_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_push_pack_into_district_slot_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of push_pack_into_district_slot_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00682B80;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_raise_hotpursuit_indicator_level(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of raise_hotpursuit_indicator_level\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_raise_hotpursuit_indicator_level(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of raise_hotpursuit_indicator_level\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006725F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_random_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of random_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_random_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of random_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663280;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_remove_civilian_info_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of remove_civilian_info_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_remove_civilian_info_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of remove_civilian_info_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677870;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_remove_civilian_info_entity_entity_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of remove_civilian_info_entity_entity_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_remove_civilian_info_entity_entity_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of remove_civilian_info_entity_entity_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00681240;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_remove_glass_house_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of remove_glass_house_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_remove_glass_house_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of remove_glass_house_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006623A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_remove_item_entity_from_world_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of remove_item_entity_from_world_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_remove_item_entity_from_world_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of remove_item_entity_from_world_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00669500;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_remove_pack_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of remove_pack_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_remove_pack_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of remove_pack_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00680A90;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_remove_traffic_model_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of remove_traffic_model_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_remove_traffic_model_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of remove_traffic_model_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677810;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_reset_externed_alses(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of reset_externed_alses\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_reset_externed_alses(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of reset_externed_alses\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00669B00;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_all_anchors_activated_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_all_anchors_activated_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_all_anchors_activated_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_all_anchors_activated_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006830A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_blur_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_blur_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_blur_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_blur_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662B90;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_blur_blend_mode_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_blur_blend_mode_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_blur_blend_mode_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_blur_blend_mode_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662CC0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_blur_color_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_blur_color_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_blur_color_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_blur_color_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662BC0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_blur_offset_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_blur_offset_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_blur_offset_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_blur_offset_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662C50;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_blur_rot_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_blur_rot_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_blur_rot_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_blur_rot_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662C90;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_blur_scale_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_blur_scale_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_blur_scale_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_blur_scale_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662C10;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_clear_color_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_clear_color_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_clear_color_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_clear_color_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006630B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_current_mission_objective_caption_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_current_mission_objective_caption_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_current_mission_objective_caption_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_current_mission_objective_caption_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679570;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_default_traffic_hitpoints_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_default_traffic_hitpoints_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_default_traffic_hitpoints_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_default_traffic_hitpoints_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677A70;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_dialog_box_flavor_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_dialog_box_flavor_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_dialog_box_flavor_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_dialog_box_flavor_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673600;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_dialog_box_lockout_time_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_dialog_box_lockout_time_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_dialog_box_lockout_time_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_dialog_box_lockout_time_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673670;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_engine_property_str_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_engine_property_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_engine_property_str_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_engine_property_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006642A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_fov_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_fov_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_fov_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_fov_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662B60;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_game_info_num_str_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_game_info_num_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_game_info_num_str_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_game_info_num_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663B90;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_game_info_str_str_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_game_info_str_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_game_info_str_str_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_game_info_str_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663C90;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_global_time_dilation_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_global_time_dilation_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_global_time_dilation_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_global_time_dilation_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663A90;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_marky_cam_lookat_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_marky_cam_lookat_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_marky_cam_lookat_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_marky_cam_lookat_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662AD0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_max_streaming_distance_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_max_streaming_distance_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_max_streaming_distance_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_max_streaming_distance_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676B90;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_mission_key_pos_facing_vector3d_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_mission_key_pos_facing_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_mission_key_pos_facing_vector3d_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_mission_key_pos_facing_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676430;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_mission_key_position_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_mission_key_position_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_mission_key_position_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_mission_key_position_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676390;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_mission_text_num_elip(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_mission_text_num_elip\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_mission_text_num_elip(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_mission_text_num_elip\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672C00;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_mission_text_box_flavor_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_mission_text_box_flavor_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_mission_text_box_flavor_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_mission_text_box_flavor_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673640;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_mission_text_debug_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_mission_text_debug_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_mission_text_debug_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_mission_text_debug_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672FA0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_parking_density_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_parking_density_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_parking_density_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_parking_density_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677A40;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_pedestrian_density_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_pedestrian_density_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_pedestrian_density_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_pedestrian_density_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677990;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_render_opt_num_str_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_render_opt_num_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_render_opt_num_str_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_render_opt_num_str_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663D60;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_score_widget_score_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_score_widget_score_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_score_widget_score_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_score_widget_score_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672570;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_sound_category_volume_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_sound_category_volume_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_sound_category_volume_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_sound_category_volume_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00664300;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_spider_reflexes_blur_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_spider_reflexes_blur_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_spider_reflexes_blur_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_spider_reflexes_blur_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662CF0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_spider_reflexes_blur_blend_mode_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_spider_reflexes_blur_blend_mode_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_spider_reflexes_blur_blend_mode_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_spider_reflexes_blur_blend_mode_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662E20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_spider_reflexes_blur_color_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_spider_reflexes_blur_color_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_spider_reflexes_blur_color_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_spider_reflexes_blur_color_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662D20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_spider_reflexes_blur_offset_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_spider_reflexes_blur_offset_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_spider_reflexes_blur_offset_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_spider_reflexes_blur_offset_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662DB0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_spider_reflexes_blur_rot_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_spider_reflexes_blur_rot_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_spider_reflexes_blur_rot_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_spider_reflexes_blur_rot_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662DF0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_spider_reflexes_blur_scale_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_spider_reflexes_blur_scale_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_spider_reflexes_blur_scale_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_spider_reflexes_blur_scale_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662D70;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_spider_reflexes_hero_meter_depletion_rate_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_spider_reflexes_hero_meter_depletion_rate_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_spider_reflexes_hero_meter_depletion_rate_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_spider_reflexes_hero_meter_depletion_rate_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_spider_reflexes_spiderman_time_dilation_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_spider_reflexes_spiderman_time_dilation_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_spider_reflexes_spiderman_time_dilation_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_spider_reflexes_spiderman_time_dilation_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_spider_reflexes_world_time_dilation_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_spider_reflexes_world_time_dilation_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_spider_reflexes_world_time_dilation_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_spider_reflexes_world_time_dilation_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_state_of_the_story_caption_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_state_of_the_story_caption_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_state_of_the_story_caption_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_state_of_the_story_caption_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679570;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_target_info_entity_vector3d_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_target_info_entity_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_target_info_entity_vector3d_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_target_info_entity_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067E3C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_time_of_day_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_time_of_day_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_time_of_day_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_time_of_day_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006640E0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_traffic_density_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_traffic_density_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_traffic_density_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_traffic_density_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677A10;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_traffic_model_usage_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_traffic_model_usage_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_traffic_model_usage_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_traffic_model_usage_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00677840;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_vibration_resume_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_vibration_resume_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_vibration_resume_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_vibration_resume_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A5B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_whoosh_interp_rate_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_whoosh_interp_rate_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_whoosh_interp_rate_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_whoosh_interp_rate_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0066EBE0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_whoosh_pitch_range_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_whoosh_pitch_range_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_whoosh_pitch_range_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_whoosh_pitch_range_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0066EBB0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_whoosh_speed_range_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_whoosh_speed_range_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_whoosh_speed_range_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_whoosh_speed_range_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0066EB50;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_whoosh_volume_range_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_whoosh_volume_range_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_whoosh_volume_range_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_whoosh_volume_range_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0066EB80;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_set_zoom_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of set_zoom_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_set_zoom_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of set_zoom_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00662B30;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_show_controller_gauge(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of show_controller_gauge\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_show_controller_gauge(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of show_controller_gauge\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672730;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_show_hotpursuit_indicator_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of show_hotpursuit_indicator_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_show_hotpursuit_indicator_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of show_hotpursuit_indicator_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006725A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_show_score_widget_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of show_score_widget_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_show_score_widget_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of show_score_widget_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672520;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_shut_up_all_ai_voice_boxes(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of shut_up_all_ai_voice_boxes\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_shut_up_all_ai_voice_boxes(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of shut_up_all_ai_voice_boxes\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0066EC10;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_sin_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of sin_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_sin_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of sin_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663EF0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_sin_cos_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of sin_cos_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_sin_cos_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of sin_cos_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00664000;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_soft_load_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of soft_load_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_soft_load_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of soft_load_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006738C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_soft_save_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of soft_save_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_soft_save_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of soft_save_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673880;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_add_hero_points_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_add_hero_points_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_add_hero_points_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_add_hero_points_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679510;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_bank_stylepoints(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_bank_stylepoints\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_bank_stylepoints(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_bank_stylepoints\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_break_web(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_break_web\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_break_web(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_break_web\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_camera_add_shake_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_camera_add_shake_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_camera_add_shake_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_camera_add_shake_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006796F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_camera_autocorrect_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_camera_autocorrect_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_camera_autocorrect_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_camera_autocorrect_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679000;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_camera_clear_fixedstatic(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_camera_clear_fixedstatic\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_camera_clear_fixedstatic(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_camera_clear_fixedstatic\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006795D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_camera_enable_combat_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_camera_enable_combat_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_camera_enable_combat_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_camera_enable_combat_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679640;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_camera_enable_lookaround_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_camera_enable_lookaround_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_camera_enable_lookaround_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_camera_enable_lookaround_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006795F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_camera_set_fixedstatic_vector3d_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_camera_set_fixedstatic_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_camera_set_fixedstatic_vector3d_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_camera_set_fixedstatic_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006795A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_camera_set_follow_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_camera_set_follow_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_camera_set_follow_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_camera_set_follow_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006796A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_camera_set_hero_underwater_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_camera_set_hero_underwater_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_camera_set_hero_underwater_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_camera_set_hero_underwater_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679760;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_camera_set_interpolation_time_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_camera_set_interpolation_time_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_camera_set_interpolation_time_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_camera_set_interpolation_time_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_camera_set_lockon_min_distance_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_camera_set_lockon_min_distance_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_camera_set_lockon_min_distance_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_camera_set_lockon_min_distance_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_camera_set_lockon_y_offset_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_camera_set_lockon_y_offset_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_camera_set_lockon_y_offset_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_camera_set_lockon_y_offset_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_charged_jump(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_charged_jump\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_charged_jump(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_charged_jump\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679390;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_enable_control_button_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_enable_control_button_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_enable_control_button_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_enable_control_button_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_enable_lockon_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_enable_lockon_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_enable_lockon_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_enable_lockon_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_engage_lockon_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_engage_lockon_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_engage_lockon_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_engage_lockon_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_engage_lockon_num_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_engage_lockon_num_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_engage_lockon_num_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_engage_lockon_num_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679430;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_get_hero_points(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_get_hero_points\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_get_hero_points(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_get_hero_points\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794E0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_get_max_zip_length(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_get_max_zip_length\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_get_max_zip_length(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_get_max_zip_length\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_get_spidey_sense_level(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_get_spidey_sense_level\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_get_spidey_sense_level(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_get_spidey_sense_level\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679400;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_is_crawling(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_is_crawling\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_is_crawling(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_is_crawling\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679160;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_is_falling(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_is_falling\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_is_falling(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_is_falling\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006792F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_is_jumping(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_is_jumping\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_is_jumping(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_is_jumping\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006792F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_is_on_ceiling(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_is_on_ceiling\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_is_on_ceiling(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_is_on_ceiling\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679200;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_is_on_ground(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_is_on_ground\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_is_on_ground(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_is_on_ground\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006792A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_is_on_wall(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_is_on_wall\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_is_on_wall(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_is_on_wall\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006791B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_is_running(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_is_running\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_is_running(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_is_running\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006792A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_is_sprint_crawling(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_is_sprint_crawling\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_is_sprint_crawling(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_is_sprint_crawling\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679390;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_is_sprinting(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_is_sprinting\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_is_sprinting(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_is_sprinting\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006792F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_is_swinging(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_is_swinging\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_is_swinging(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_is_swinging\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679250;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_is_wallsprinting(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_is_wallsprinting\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_is_wallsprinting(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_is_wallsprinting\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679340;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_lock_spider_reflexes_off(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_lock_spider_reflexes_off\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_lock_spider_reflexes_off(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_lock_spider_reflexes_off\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_lock_spider_reflexes_on(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_lock_spider_reflexes_on\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_lock_spider_reflexes_on(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_lock_spider_reflexes_on\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_lockon_camera_engaged(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_lockon_camera_engaged\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_lockon_camera_engaged(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_lockon_camera_engaged\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_lockon_mode_engaged(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_lockon_mode_engaged\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_lockon_mode_engaged(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_lockon_mode_engaged\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_set_camera_target_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_set_camera_target_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_set_camera_target_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_set_camera_target_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679460;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_set_desired_mode_num_vector3d_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_set_desired_mode_num_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_set_desired_mode_num_vector3d_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_set_desired_mode_num_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663390;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_set_health_beep_min_max_cooldown_time_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_set_health_beep_min_max_cooldown_time_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_set_health_beep_min_max_cooldown_time_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_set_health_beep_min_max_cooldown_time_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_set_health_beep_threshold_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_set_health_beep_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_set_health_beep_threshold_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_set_health_beep_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_set_hero_meter_empty_rate_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_set_hero_meter_empty_rate_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_set_hero_meter_empty_rate_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_set_hero_meter_empty_rate_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_set_max_height_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_set_max_height_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_set_max_height_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_set_max_height_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_set_max_zip_length_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_set_max_zip_length_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_set_max_zip_length_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_set_max_zip_length_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_set_min_height_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_set_min_height_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_set_min_height_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_set_min_height_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_set_spidey_sense_level_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_set_spidey_sense_level_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_set_spidey_sense_level_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_set_spidey_sense_level_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006793C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_set_swing_anchor_max_sticky_time_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_set_swing_anchor_max_sticky_time_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_set_swing_anchor_max_sticky_time_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_set_swing_anchor_max_sticky_time_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_subtract_hero_points_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_subtract_hero_points_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_subtract_hero_points_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_subtract_hero_points_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679540;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_td_set_alternating_wall_run_occurrence_threshold_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_td_set_alternating_wall_run_occurrence_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_td_set_alternating_wall_run_occurrence_threshold_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_td_set_alternating_wall_run_occurrence_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_td_set_alternating_wall_run_time_threshold_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_td_set_alternating_wall_run_time_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_td_set_alternating_wall_run_time_threshold_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_td_set_alternating_wall_run_time_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_td_set_big_air_height_threshold_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_td_set_big_air_height_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_td_set_big_air_height_threshold_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_td_set_big_air_height_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_td_set_continuous_air_swings_threshold_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_td_set_continuous_air_swings_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_td_set_continuous_air_swings_threshold_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_td_set_continuous_air_swings_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_td_set_gain_altitude_height_threshold_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_td_set_gain_altitude_height_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_td_set_gain_altitude_height_threshold_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_td_set_gain_altitude_height_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_td_set_near_miss_trigger_radius_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_td_set_near_miss_trigger_radius_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_td_set_near_miss_trigger_radius_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_td_set_near_miss_trigger_radius_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_td_set_near_miss_velocity_threshold_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_td_set_near_miss_velocity_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_td_set_near_miss_velocity_threshold_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_td_set_near_miss_velocity_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_td_set_orbit_min_radius_threshold_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_td_set_orbit_min_radius_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_td_set_orbit_min_radius_threshold_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_td_set_orbit_min_radius_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_td_set_soft_landing_velocity_threshold_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_td_set_soft_landing_velocity_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_td_set_soft_landing_velocity_threshold_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_td_set_soft_landing_velocity_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_td_set_super_speed_speed_threshold_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_td_set_super_speed_speed_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_td_set_super_speed_speed_threshold_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_td_set_super_speed_speed_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_td_set_swinging_wall_run_time_threshold_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_td_set_swinging_wall_run_time_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_td_set_swinging_wall_run_time_threshold_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_td_set_swinging_wall_run_time_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_td_set_wall_sprint_time_threshold_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_td_set_wall_sprint_time_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_td_set_wall_sprint_time_threshold_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_td_set_wall_sprint_time_threshold_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_unlock_spider_reflexes(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_unlock_spider_reflexes\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_unlock_spider_reflexes(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_unlock_spider_reflexes\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spiderman_wait_add_threat_entity_str_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spiderman_wait_add_threat_entity_str_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spiderman_wait_add_threat_entity_str_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spiderman_wait_add_threat_entity_str_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006797C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_spidey_can_see_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of spidey_can_see_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_spidey_can_see_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of spidey_can_see_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679030;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_sqrt_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of sqrt_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_sqrt_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of sqrt_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663F50;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_start_patrol_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of start_patrol_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_start_patrol_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of start_patrol_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676E80;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_stop_all_sounds(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of stop_all_sounds\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_stop_all_sounds(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of stop_all_sounds\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0066EC20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_stop_credits(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of stop_credits\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_stop_credits(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of stop_credits\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672690;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_stop_vibration(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of stop_vibration\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_stop_vibration(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of stop_vibration\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A590;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_subtitle_num_num_num_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of subtitle_num_num_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_subtitle_num_num_num_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of subtitle_num_num_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673900;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_swap_hero_costume_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of swap_hero_costume_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_swap_hero_costume_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of swap_hero_costume_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676C50;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_text_width_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of text_width_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_text_width_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of text_width_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_timer_widget_get_count_up(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of timer_widget_get_count_up\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_timer_widget_get_count_up(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of timer_widget_get_count_up\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672940;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_timer_widget_get_time(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of timer_widget_get_time\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_timer_widget_get_time(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of timer_widget_get_time\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006728C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_timer_widget_set_count_up_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of timer_widget_set_count_up_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_timer_widget_set_count_up_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of timer_widget_set_count_up_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006728F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_timer_widget_set_time_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of timer_widget_set_time_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_timer_widget_set_time_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of timer_widget_set_time_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672890;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_timer_widget_start(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of timer_widget_start\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_timer_widget_start(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of timer_widget_start\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672850;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_timer_widget_stop(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of timer_widget_stop\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_timer_widget_stop(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of timer_widget_stop\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672870;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_timer_widget_turn_off(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of timer_widget_turn_off\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_timer_widget_turn_off(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of timer_widget_turn_off\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672830;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_timer_widget_turn_on(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of timer_widget_turn_on\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_timer_widget_turn_on(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of timer_widget_turn_on\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672810;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_to_beam_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of to_beam_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_to_beam_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of to_beam_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067AE20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_to_gun_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of to_gun_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_to_gun_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of to_gun_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00681950;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_to_item_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of to_item_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_to_item_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of to_item_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006819B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_to_polytube_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of to_polytube_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_to_polytube_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of to_polytube_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006806D0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_to_switch_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of to_switch_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_to_switch_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of to_switch_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067F7F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_trace_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of trace_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_trace_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of trace_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006794C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_trigger_is_valid_trigger(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of trigger_is_valid_trigger\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_trigger_is_valid_trigger(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of trigger_is_valid_trigger\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00671900;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_turn_off_boss_health(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of turn_off_boss_health\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_turn_off_boss_health(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of turn_off_boss_health\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672B00;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_turn_off_hero_health(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of turn_off_hero_health\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_turn_off_hero_health(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of turn_off_hero_health\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672B20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_turn_off_mission_text(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of turn_off_mission_text\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_turn_off_mission_text(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of turn_off_mission_text\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00673060;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_turn_off_third_party_health(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of turn_off_third_party_health\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_turn_off_third_party_health(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of turn_off_third_party_health\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00672B40;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_turn_on_boss_health_num_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of turn_on_boss_health_num_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_turn_on_boss_health_num_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of turn_on_boss_health_num_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067FFF0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_turn_on_hero_health_num_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of turn_on_hero_health_num_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_turn_on_hero_health_num_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of turn_on_hero_health_num_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00680040;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_turn_on_third_party_health_num_entity(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of turn_on_third_party_health_num_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_turn_on_third_party_health_num_entity(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of turn_on_third_party_health_num_entity\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00680090;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_unload_script(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of unload_script\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_unload_script(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of unload_script\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x006762B0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_unlock_all_exterior_districts(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of unlock_all_exterior_districts\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_unlock_all_exterior_districts(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of unlock_all_exterior_districts\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676C30;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_unlock_district_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of unlock_district_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_unlock_district_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of unlock_district_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676A30;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_vibrate_controller_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of vibrate_controller_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_vibrate_controller_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of vibrate_controller_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A550;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_vibrate_controller_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of vibrate_controller_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_vibrate_controller_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of vibrate_controller_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A510;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_vibrate_controller_num_num_num_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of vibrate_controller_num_num_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_vibrate_controller_num_num_num_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of vibrate_controller_num_num_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A4C0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_vo_delay_num_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of vo_delay_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_vo_delay_num_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of vo_delay_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663230;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_wait_animate_fog_color_vector3d_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of wait_animate_fog_color_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_wait_animate_fog_color_vector3d_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of wait_animate_fog_color_vector3d_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A100;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_wait_animate_fog_distance_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of wait_animate_fog_distance_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_wait_animate_fog_distance_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of wait_animate_fog_distance_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A2A0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_wait_animate_fog_distances_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of wait_animate_fog_distances_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_wait_animate_fog_distances_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of wait_animate_fog_distances_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A370;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_wait_change_blur_num_vector3d_num_num_num_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of wait_change_blur_num_vector3d_num_num_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_wait_change_blur_num_vector3d_num_num_num_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of wait_change_blur_num_vector3d_num_num_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679BA0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_wait_change_spider_reflexes_blur_num_vector3d_num_num_num_num_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of wait_change_spider_reflexes_blur_num_vector3d_num_num_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_wait_change_spider_reflexes_blur_num_vector3d_num_num_num_num_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of wait_change_spider_reflexes_blur_num_vector3d_num_num_num_num_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679E50;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_wait_for_streamer_to_reach_equilibrium(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of wait_for_streamer_to_reach_equilibrium\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_wait_for_streamer_to_reach_equilibrium(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of wait_for_streamer_to_reach_equilibrium\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00676B20;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_wait_fps_test_num_num_vector3d_vector3d(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of wait_fps_test_num_num_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_wait_fps_test_num_num_vector3d_vector3d(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of wait_fps_test_num_num_vector3d_vector3d\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A8F0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_wait_frame(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of wait_frame\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_wait_frame(void* this, void* edx, void* arg, void* arg1) {

	//printf("Calling action of wait_frame\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663110;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_wait_set_global_time_dilation_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of wait_set_global_time_dilation_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_wait_set_global_time_dilation_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of wait_set_global_time_dilation_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x0067A710;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_wait_set_zoom_num_num(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of wait_set_zoom_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_wait_set_zoom_num_num(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of wait_set_zoom_num_num\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00679AE0;
	return original(this, edx, arg, arg1);
}

int __fastcall slf_deconstructor_write_to_file_str_str(void* this, void* edx, void* arg) {

	printf("Calling deconstructor of write_to_file_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*);
	original_ptr original = (void*)0x0067ADE0;
	return original(this, edx, arg);
}

int __fastcall slf_action_write_to_file_str_str(void* this, void* edx, void* arg, void* arg1) {

	printf("Calling action of write_to_file_str_str\n");

	typedef int(__fastcall* original_ptr)(void*, void*, void*, void*);
	original_ptr original = (void*)0x00663620;
	return original(this, edx, arg, arg1);
}
