#pragma once

#include "func_wrapper.h"

namespace geometry_manager
{
    void enable_scene_analyzer(bool a1)
    {
        CDECL_CALL(0x00515730, a1);
    }

    bool is_scene_analyzer_enabled()
    {
        return (bool) CDECL_CALL(0x00515720);
    }
}
