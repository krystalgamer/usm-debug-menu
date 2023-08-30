#pragma once

#include "actor.h"
#include "entity.h"
#include "debug_menu.h"
#include "nal_system.h"
#include "resource_manager.h"

#include <list>

void entity_animation_handler(debug_menu_entry *entry)
{
    printf("handle_animation_entry\n");

    auto *v7 = static_cast<entity *>(entry->data1);
    if ( v7 != nullptr && v7->is_an_actor() )
    {
        auto *v6 = (actor *) v7;
        auto *context = v6->field_BC;
        assert(context != nullptr);

        string_hash v4 {entry->text};
        resource_manager::push_resource_context(context);

        auto v3 = v6->play_anim(v4);
        resource_manager::pop_resource_context();
        v3.set_anim_speed(1.0);
        debug_menu::hide();
    }
}

void sub_6918AD(debug_menu_entry *entry)
{
    auto *e = static_cast<entity *>(entry->data1);
    if (e->is_an_actor())
    {
        auto *a1 = create_menu(entry->text);
        entry->set_submenu(a1);
        auto *v18 = (actor *) e;

        auto v17 = actor::get_animations(v18);
        for (auto *v15 : v17)
        {
            auto &v3 = v15->field_8;
            auto *v4 = v3.to_string();
            mString v14 {v4};

            debug_menu_entry v13 {v14};
            v13.data1 = entry->data1;
            v13.set_game_flags_handler(entity_animation_handler);
            a1->add_entry(&v13);
        }
    }
}

void populate_entity_animation_menu(debug_menu_entry *entry)
{
    auto *v26 = create_menu(entry->text);
    entry->set_submenu(v26);
    entity::find_entities(1);
    auto &found_entities = (*entity::found_entities());
    for (auto *ent : found_entities)
    {
        if ( ent->is_an_actor() )
        {
            auto *v23 = (actor *) ent;

            auto  v22 = actor::get_animations(v23);
            if ( !v22.empty() )
            {
                auto &id = bit_cast<entity *>(v23)->get_id();
                debug_menu_entry v21 {mString {id.to_string()}};

                v21.set_game_flags_handler(sub_6918AD);
                v21.data1 = ent;
                v21.set_submenu(nullptr);
                v26->add_entry(&v21);
            }
        }
    }
}

void create_entity_animation_menu(debug_menu *parent)
{
    debug_menu_entry v5 {mString{"Entity Animations"}};

    v5.set_submenu(nullptr);
    v5.set_game_flags_handler(populate_entity_animation_menu);
    parent->add_entry(&v5);
}
