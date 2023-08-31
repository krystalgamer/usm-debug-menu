#pragma once

#include "bit.h"

struct entity_tracker_manager {

    bool get_the_arrow_target_pos(vector3d *a2)
    {
        bool (__fastcall *func)(void *, void *, vector3d *) =
            bit_cast<decltype(func)>(0x0062EE10);
        return func(this, nullptr, a2);
    }
};

