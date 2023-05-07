#pragma once

#include "func_wrapper.h"
#include "game.h"
#include "os_developer_options.h"

Var<bool> god_mode_cheat {0x0095A6A8};
Var<bool> ultra_god_mode_cheat {0x0095A6A9};
Var<bool> mega_god_mode_cheat {0x0095A6AA};

namespace spider_monkey
{
    void start()
    {
        CDECL_CALL(0x004B6690);
    }

    void on_level_load()
    {
        CDECL_CALL(0x004B3910);
    }

    void stop()
    {
        CDECL_CALL(0x004B6700);
    }

    void on_level_unload()
    {
        CDECL_CALL(0x004B3B20);
    }

    void render()
    {
        CDECL_CALL(0x004B6890);

        {
            if ( os_developer_options::instance()->get_flag(mString{"SHOW_DEBUG_INFO"}) )
            {
                g_game_ptr()->show_debug_info();
            }

            if ( os_developer_options::instance()->get_flag(mString{"SHOW_FPS"}) )
            {
                auto v40 = (g_game_ptr()->field_278 == 0 ? 0.f : (1.f / g_game_ptr()->field_278));
                auto v39 = (
                        ((g_game_ptr()->field_278 - g_game_ptr()->field_27C) - g_game_ptr()->field_280) >= 0.000099999997
                        ? (1.0 / (g_game_ptr()->field_278 - g_game_ptr()->field_27C - g_game_ptr()->field_280))
                        : 10000.0f);

                static float dword_1584E70 = 0;
                if ( v39 > dword_1584E70 )
                {
                    dword_1584E70 = v39;
                }

                static float dword_14EEB94 = 500;
                if ( dword_14EEB94 > v39 )
                {
                    dword_14EEB94 = v39;
                }

                color32 v38 {0};
                if ( v40 >= 14.2 )
                {
                    if ( v40 >= 29.4 )
                    {
                        if ( v40 >= 59.900002 )
                        {
                            color32 v5 {80, 255, 80, 255};
                            v38 = v5;
                        }
                        else
                        {
                            color32 v4 {255, 255, 32, 255};
                            v38 = v4;
                        }
                    }
                    else
                    {
                        color32 v3 {255, 128, 40, 255};
                        v38 = v3;
                    }
                }
                else
                {
                    color32 v2 {255, 33, 44, 255};
                    v38 = v2;
                }

                char a1a[200]{};
                sprintf(a1a, "%2d fps (%2d.%1d)", (int)v40, (int)v39, (int)(float)(v39 * 10.0) % 10);
                auto a5 = ((int)v38.field_0[0] >> 4) | ((int)v38.field_0[1] >> 4 << 8) | ((int)v38.field_0[2] >> 4 << 16) | 0xFF000000;
                nglListAddString(nglSysFont(), 19.0, 424.0, 1.01, a5, 0.80000001, 0.80000001, a1a);
                nglListAddString(nglSysFont(), 21.0, 426.0, 1.01, a5, 0.80000001, 0.80000001, a1a);
                nglListAddString(
                    nglSysFont(),
                    20.0,
                    425.0,
                    1.0,
                    v38.field_0[0] | (v38.field_0[1] << 8) | (v38.field_0[2] << 16) | 0xFF000000,
                    0.80000001,
                    0.80000001,
                    a1a);

                if ( god_mode_cheat() )
                {
                    if ( ultra_god_mode_cheat() )
                    {
                        mString v16 {"Ultra-God mode"};
                        auto v11 = v38;
                        vector2di v6 {20, 110};
                        render_text(v16, v6, v11, 1.0, 0.5);
                    }
                    else if ( mega_god_mode_cheat() )
                    {
                        mString v17 {"Mega-God mode"};
                        auto v12 = v38;
                        vector2di v7 {20, 110};
                        render_text(v17, v7, v12, 1.0, 0.5);
                    }
                    else
                    {
                        mString v18 {"God mode"};
                        auto v13 = v38;
                        vector2di v8 {20, 110};
                        render_text(v18, v8, v13, 1.0, 0.5);
                    }
                }
                else if ( ultra_god_mode_cheat() )
                {
                    mString v19 {"Ultra-Mortal mode"};
                    auto v14 = v38;
                    vector2di v9 {20, 110};
                    render_text(v19, v9, v14, 1.0, 0.5);
                }
                else if ( mega_god_mode_cheat() )
                {
                    mString v20 {"Mega-Mortal mode"};
                    auto v15 = v38;
                    vector2di v10 {20, 110};
                    render_text(v20, v10, v15, 1.0, 0.5);
                }
            }
        }
    }
}
