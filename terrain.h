#pragma once

#include "wds.h"
#include "mission_manager.h"
#include "resource_key.h"
#include "func_wrapper.h"
#include "region.h"
#include "string_hash.h"

#include <cassert>
#include <cstdio>

struct region;

struct terrain
{
    region **regions;
    int field_4;
    int field_8;
    int total_regions;
    int strips;
    int total_strips;
    float field_18[3];

    region *get_region(int idx)
    {
        assert(idx >= 0);
        assert(idx < total_regions);

        return this->regions[idx];
    }

    int get_num_regions() const
    {
        return this->total_regions;
    }

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

    void set_district_variant(int a2, int variant, bool a4)
    {
        void (__fastcall *func)(void *, void *, int, int, bool) =
            bit_cast<decltype(func)>( 0x00557480);

        func(this, nullptr, a2, variant, a4);
    }



};
