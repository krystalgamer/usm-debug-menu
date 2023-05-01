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
        auto func = bit_cast<fastcall_call>(0x0054F380);
        func(this);
    }

    region *find_region(string_hash a2)
    {
        auto func = bit_cast<fastcall_call>(0x00534920);
        return (region *) func(this, 0, a2);
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
