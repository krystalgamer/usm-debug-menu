#pragma once

#include "debug_menu.h"
#include "entity_base_vhandle.h"
#include "mstring.h"

#include <map>

namespace script_memtrack {

struct entity_class_t {
    mString field_0;
    int field_C;
    std::list<std::pair<entity_base_vhandle, int>> field_10;
};

static std::string current_class_name {}; 

static int current_heap_usage {0};

static std::map<entity_base_vhandle, script_memtrack::entity_class_t *> handle_to_class_map {};

static std::map<mString, script_memtrack::entity_class_t *> name_to_class_map {};

static debug_menu *script_memtrack_debug_menu {nullptr};

void dump_info(debug_menu_entry *)
{
    printf("script_memtrack::dump_info\n");

    for ( auto it = name_to_class_map.begin(), end = name_to_class_map.end();
            it != end; ) {
        auto *cls = it->second;
        if ( !cls->field_10.empty() ) {
            auto v5 = cls->field_C;
            auto v4 = cls->field_10.size();
            auto *v1 = cls->field_0.c_str();
            printf("%s, %d instances, %d bytes\n", v1, v4, v5);

            for ( auto &p : cls->field_10 ) {
                auto v15 = p.first;
                auto *ent = (entity *) v15.get_volatile_ptr();
                if ( ent != nullptr ) {
                    auto v6 = p.second;
                    auto id = ent->get_id();
                    auto *v3 = id.to_string();
                    printf("    %s, %d bytes\n", v3, v6);
                }
            }

            ++it;
        } else {
            ++it;
        }
    }
}

void create_debug_menu(debug_menu *arg0)
{
    script_memtrack_debug_menu = create_menu("Script Memtrack", debug_menu::sort_mode_t::undefined);
    arg0->add_entry(script_memtrack_debug_menu);

    auto *v7 = create_menu_entry(mString {"Dump Memtrack Info"});
    v7->set_game_flags_handler(dump_info);
    script_memtrack_debug_menu->add_entry(v7);
}

}
