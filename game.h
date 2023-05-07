#pragma once

#include "fetext.h"
#include "variable.h"
#include "common.h"
#include "os_developer_options.h"
#include "entity_handle_manager.h"
#include "vector2di.h"
#include "ngl.h"
#include "entity.h"
#include "physical_interface.h"
#include "po.h"
#include "region.h"
#include "terrain.h"
#include "wds.h"

struct game_process
{
    const char *field_0;
    int *field_4;
    int index;
    int num_states;
    int field_10;
    bool field_14;
};

inline Var<game_process> lores_game_process{0x00922074};

struct game
{
    char field_0[0x5C];
    entity *field_5C;
    entity *current_game_camera;
    void *field_64;
    void *field_68;
    struct {
        int field_0;
        game_process *m_first;
        game_process *m_last;
        game_process *m_end;

        auto &back()
        {
            return *(m_last - 1);
        }
    } process_stack;

    int field_7C[59];

    struct {
        bool level_is_loaded;
        bool single_step;
        bool physics_enabled;
        bool field_3;
        bool game_paused;
    } flag;
    bool field_16D;
    bool field_16E;
    bool field_16F;
    bool field_170;
    bool field_171;
    bool field_172;
    bool field_173;
    vector3d field_174;
    vector3d field_180[10];
    vector3d field_1F8[10];
    int field_270;
    int field_274;
    int field_278;
    int field_27C;
    int field_280;

    void enable_physics(bool a2)
    {
        void (__fastcall *func)(void*, int, bool) = (decltype(func)) 0x00515230;
        func(this, 0, a2);
    }

    void push_process(game_process &process) {
        void (__fastcall *sub_570FD0)(void *, int, void *) = (decltype(sub_570FD0)) 0x00570FD0;

        sub_570FD0(&this->process_stack, 0, &process);

        auto &last_proc = this->process_stack.back();
        last_proc.index = 0;
        last_proc.field_10 = 0;
    }

    void push_lores()
    {
        this->push_process(lores_game_process());
    }

    void begin_hires_screenshot(int a2, int a3)
    {
        void (__fastcall *func)(void *, void *, int, int) = (decltype(func)) 0x00548C10;
        func(this, nullptr, a2, a3);
    }

    mString get_hero_info();

    mString get_camera_info();

    mString get_analyzer_info();

    void show_debug_info();
};

VALIDATE_OFFSET(game, field_172, 0x172);
VALIDATE_OFFSET(game, field_280, 0x280);

inline Var<game *> g_game_ptr{0x009682E0};

mString sub_55DD80(const vector3d &a2)
{
    mString a1 {0, "<%.3f,%.3f,%.3f>", a2.x, a2.y, a2.z};
    return a1;
}

mString game::get_camera_info()
{
    auto *v34 = this;
    auto *v2 = this->field_5C;

    mString v22;
    if ( v2->get_primary_region() != nullptr )
    {
        auto *v4 = v2->get_primary_region();
        auto &v5 = v4->get_name();
        auto *v6 = v5.to_string();
        v22 = mString{v6};
    }
    else
    {
        v22 = mString{"none"};
    }

    mString v33 = v22;


    auto &v18 = *v2->get_abs_position();
    auto *v8 = g_world_ptr()->the_terrain;
    auto *v32 = v8->find_region(v18, nullptr);
    if ( v32 != nullptr )
    {
        auto &v9 = v32->get_name();
        auto *v10 = v9.to_string();
        v33 = {v10};
    }

    auto &v12 = *v2->get_abs_position();
    auto v31 = sub_55DD80(v12);

    auto &v14 = *v2->get_abs_po();
    auto &v15 = v14.get_z_facing();

    auto v30 = sub_55DD80(v15);
    auto *v20 = v30.c_str();
    auto *v19 = v31.c_str();
    auto *v16 = v33.c_str();

    mString v29 {0, "CAMERA @ %s %s, f = %s", v16, v19, v20};

    auto v24 = " " + v33;

    v29 += v24;
    
    return v29;
}

mString game::get_analyzer_info()
{
    auto v16 = string_hash("SCENE_ANALYZER_CAM");
    auto *v3 = entity_handle_manager::find_entity(v16, entity_flavor_t::CAMERA, false);

    auto &v14 = *v3->get_abs_position();
    auto *v4 = g_world_ptr()->the_terrain;
    auto *v26 = v4->find_region(v14, nullptr);

    mString v25 {""};
    if ( v26 != nullptr )
    {
        auto &v5 = v26->get_name();
        auto *v6 = v5.to_string();
        v25 = v6;
    }

    auto &v8 = *v3->get_abs_position();
    auto v24 = sub_55DD80(v8);

    auto &v10 = *v3->get_abs_po();
    auto &v11 = v10.get_z_facing();
    auto v23 = sub_55DD80(v11);

    auto *v15 = v23.c_str();
    auto *v12 = v24.c_str();

    mString a1 {0, "ANALYZER @ %s, f = %s", v12, v15};
    auto v17 = " " + v25;
    a1 += v17;
    return a1;
}

mString game::get_hero_info()
{
    auto *hero_ptr = g_world_ptr()->get_hero_ptr(0);
    if ( hero_ptr == nullptr )
    {
        mString result {"(hero does not exist!)"};
        return result;
    }

    region *v29 = nullptr;
    if ( hero_ptr != nullptr )
    {
        v29 = hero_ptr->get_primary_region();
    }

    mString v28 {"none"};
    if ( v29 != nullptr )
    {
        auto &v4 = v29->get_name();
        auto *v5 = v4.to_string();
        v28 = {v5};
    }

    auto v27 = [&]() -> mString
    {
        if ( hero_ptr != nullptr )
        {
            auto &v6 = *hero_ptr->get_abs_position();
            return sub_55DD80(v6);
        }

        return mString{"N/A"};
    }();

    vector3d v15;
    if ( hero_ptr != nullptr )
    {
        auto *v7 = bit_cast<actor *>(hero_ptr)->physical_ifc();
        v15 = v7->get_velocity();
    }
    else
    {
        v15 = ZEROVEC;
    }

    mString v25{0, "HERO @ %s ", v28.c_str()};

    auto *v9 = v27.c_str();
    v25.append(v9, -1);
    v25.append(", v = ", -1);

    auto v14 = sub_55DD80(v15);
    v25.append(v14.c_str(), -1);

    return v25;
}

void game::show_debug_info()
{
    auto DEBUG_INFO_FONT_PCT = os_developer_options::instance()->get_int(mString{"DEBUG_INFO_FONT_PCT"});
    auto v15 = (float)DEBUG_INFO_FONT_PCT / 100.0;
    auto a1 = this->get_hero_info();

    vector2di v13 {50, 40};
    auto *v4 = a1.c_str();
    nglListAddString(nglSysFont(), (float)v13.x, (float)v13.y, 1.0, v15, v15, v4);

    auto v12 = this->get_camera_info();
    v13.y += 20;
    auto *v5 = v12.c_str();
    nglListAddString(nglSysFont(), (float)v13.x, (float)v13.y, 1.0, v15, v15, v5);

    auto v11 = this->get_analyzer_info();
    v13.y += 20;
    auto *v6 = v11.c_str();
    nglListAddString(nglSysFont(), (float)v13.x, (float)v13.y, 1.0, v15, v15, v6);
}

void render_text(const mString &a1, const vector2di &a2, color32 a3, float a4, float a5)
{
    if ( os_developer_options::instance()->get_flag(mString{"SHOW_DEBUG_TEXT"}) )
    {
        FEText fe_text{font_index{0},
                       global_text_enum{0},
                       (float) a2.x,
                       (float) a2.y,
                       (int) a4,
                       panel_layer{0},
                       a5,
                       16,
                       0,
                       a3};

        fe_text.field_1C = a1;

        fe_text.Draw();
    }
}
