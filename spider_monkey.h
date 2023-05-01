#pragma once

#include "func_wrapper.h"

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
}
