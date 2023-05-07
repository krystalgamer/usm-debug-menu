#pragma once

#include "wds.h"
#include "mission_manager.h"
#include "resource_key.h"
#include "func_wrapper.h"
#include "region.h"
#include "string_hash.h"

#include <cstdio>

struct terrain
{
    char field_0[0x18];
    float field_18[3];

    void update_region_pack_info()
    {
        void (__fastcall *func)(void *) = bit_cast<decltype(func)>(0x0054F380);
        func(this);
    }

    region *find_region(string_hash a2)
    {
        region *(__fastcall *func)(void *, int, string_hash) = bit_cast<decltype(func)>(0x00534920);
        return func(this, 0, a2);
    }

    region *find_region(const vector3d &a2, const region *a3)
    {
        region *(__fastcall *func)(void *, int, const vector3d *, const region *) = bit_cast<decltype(func)>(0x0052DFF0);
        return func(this, 0, &a2, a3);
    }

    void unload_district_immediate(int a2)
    {
        auto func = bit_cast<fastcall_call>(0x005571B0);
        func(this, 0, a2);
    }

    void unload_all_districts_immediate()
    {
        void (__fastcall *func)(void *) = (decltype(func)) 0x00557350;
        func(this);
    }

};
