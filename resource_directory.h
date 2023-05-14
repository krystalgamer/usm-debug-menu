#pragma once

#include <cstdint>

#include "bit.h"

struct resource_key;
struct resource_pack_slot;

struct resource_directory
{
    uint8_t *get_resource(const resource_key &resource_id, int *a3, resource_pack_slot **a4)
    {
        uint8_t * (__fastcall *func)(void *, void *, const resource_key *, int *, resource_pack_slot **) = bit_cast<decltype(func)>(0x0052AA70);
        return func(this, 0, &resource_id, a3, a4);
    }
};
