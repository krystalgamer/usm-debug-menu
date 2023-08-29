#pragma once

#include <cstdint>

#include "bit.h"
#include "tlresource_location.h"

struct resource_key;
struct resource_pack_slot;

struct resource_directory
{
    uint8_t *get_resource(const resource_key &resource_id, int *a3, resource_pack_slot **a4)
    {
        uint8_t * (__fastcall *func)(void *, void *, const resource_key *, int *, resource_pack_slot **) = bit_cast<decltype(func)>(0x0052AA70);
        return func(this, 0, &resource_id, a3, a4);
    }

    int get_tlresource_count(tlresource_type a1) {
        int (__fastcall *func)(void *, int, tlresource_type) = bit_cast<decltype(func)>(0x00563070);
        return func(this, 0, a1);
    }

    
    tlresource_location *get_tlresource_location(int idx, tlresource_type a2) {
        tlresource_location * (__fastcall *func)(void *, int, int, tlresource_type) = bit_cast<decltype(func)>(0x00563090);
        return func(this, 0, idx, a2);
    }
};
