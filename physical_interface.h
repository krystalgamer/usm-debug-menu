#pragma once

#include "vector3d.h"

struct physical_interface 
{
    vector3d get_velocity()
    {
        vector3d result;
        THISCALL(0x004CA0D0, this, &result);
        return result;
    }
};

