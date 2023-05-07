#pragma once

#include "vector3d.h"

struct physical_interface 
{
    vector3d get_velocity()
    {
        vector3d result;
        void (__fastcall *func)(void *, void *, vector3d *) = bit_cast<decltype(func)>(0x004CA0D0);
        func(this, 0, &result);

        return result;
    }
};

