#pragma once

#include "mstring.h"

constexpr auto EXTEND_NEW_ENTRIES = 20;

constexpr auto MAX_CHARS_SAFE = 63;
constexpr auto MAX_CHARS = MAX_CHARS_SAFE + 1;

enum debug_menu_entry_type {
    NORMAL,
    INTEGER,
    BOOLEAN_E,
    POINTER_BOOL,
    POINTER_MENU,
	CUSTOM
};

enum custom_key_type {
	LEFT,
	RIGHT,
	ENTER
};

struct debug_menu_entry;
typedef char* (*custom_string_generator_ptr)(debug_menu_entry* entry);

struct debug_menu;

struct debug_menu_entry {

	char text[MAX_CHARS];
	debug_menu_entry_type entry_type;
	void* data;
	void* data1;
    uint16_t m_id {0};
	custom_string_generator_ptr custom_string_generator;
    void (*m_game_flags_handler)(debug_menu_entry *);
    float field_20[4];

    void set_id(int id)
    {
        m_id = id;
    }

    auto get_id() const
    {
        return m_id;
    }

    void set_bval(bool a2)
    {
        this->entry_type = BOOLEAN_E;
        this->data = (void *) a2;
    }

    void set_pt_bval(bool *a2)
    {
        this->entry_type = POINTER_BOOL;
        this->data = a2;
    }

    void set_ival(int a2)
    {
        this->entry_type = INTEGER;
        this->data = (void *) a2;
    }

    void set_fl_values(const float *a2)
    {
        auto *v2 = this->field_20;
        v2[0] = a2[0];
        v2[1] = a2[1];
        v2[2] = a2[2];
        v2[3] = a2[3];
    }

    void set_game_flags_handler(void (*a2)(debug_menu_entry *))
    {
        this->m_game_flags_handler = a2;
    }

    debug_menu_entry() = default;

    debug_menu_entry(const char *p_text) : entry_type(NORMAL), data(nullptr)
    {
        strncpy(this->text, p_text, MAX_CHARS_SAFE);
    }

    debug_menu_entry(const mString &p_text) : entry_type(NORMAL), data(nullptr)
    {
        strncpy(this->text, p_text.c_str(), MAX_CHARS_SAFE);
    }

    debug_menu_entry(debug_menu *submenu);

    debug_menu_entry(const char *p_text, debug_menu_entry_type p_type, void *p_data) :
        entry_type(p_type), data(p_data)
    {
        strncpy(this->text, p_text, MAX_CHARS_SAFE);
    }
};

typedef void (*menu_handler_function)(debug_menu_entry*, custom_key_type key_type);
typedef void (*go_back_function)();

struct debug_menu {
	char title[MAX_CHARS];
	DWORD capacity;
	DWORD used_slots;
	DWORD window_start;
	DWORD cur_index;
	go_back_function go_back;
	menu_handler_function handler;
	debug_menu_entry* entries;

    void add_entry(debug_menu_entry *entry);
};

debug_menu_entry::debug_menu_entry(debug_menu *submenu) : entry_type(POINTER_MENU), data(submenu)
{
    strncpy(this->text, submenu->title, MAX_CHARS_SAFE);
}

void* add_debug_menu_entry(debug_menu* menu, debug_menu_entry* entry) {

	if (menu->used_slots < menu->capacity) {
		void* ret = &menu->entries[menu->used_slots];
		memcpy(ret, entry, sizeof(debug_menu_entry));
		++menu->used_slots;
		return ret;
	}
	else {
		DWORD current_entries_size = sizeof(debug_menu_entry) * menu->capacity;
		DWORD new_entries_size = sizeof(debug_menu_entry) * EXTEND_NEW_ENTRIES;

		void* new_ptr = realloc(menu->entries, current_entries_size + new_entries_size);

		if (new_ptr == nullptr) {
			printf("RIP\n");
			__debugbreak();
		}
		else {

			menu->capacity += EXTEND_NEW_ENTRIES;
			menu->entries = static_cast<decltype(menu->entries)>(new_ptr);
			memset(&menu->entries[menu->used_slots], 0, new_entries_size);

			return add_debug_menu_entry(menu, entry);
		}
	}
	
	return nullptr;
}

void debug_menu::add_entry(debug_menu_entry *entry)
{
    add_debug_menu_entry(this, entry);
}


debug_menu* create_menu(const char* title, go_back_function go_back, menu_handler_function function, DWORD capacity) {

	auto *mem = malloc(sizeof(debug_menu));
    debug_menu* menu = static_cast<debug_menu*>(mem);
	memset(menu, 0, sizeof(debug_menu));

	strncpy(menu->title, title, MAX_CHARS_SAFE);

	menu->capacity = capacity;
	menu->handler = function;
	menu->go_back = go_back;

	DWORD total_entries_size = sizeof(debug_menu_entry) * capacity;
	menu->entries = static_cast<decltype(menu->entries)>(malloc(total_entries_size));
	memset(menu->entries, 0, total_entries_size);

	return menu;

}
