#pragma once

#include "func_wrapper.h"
#include "game.h"
#include "os_developer_options.h"

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
        }
    }
}
