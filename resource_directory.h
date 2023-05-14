#pragma once

#include <cstdint>

#include "func_wrapper.h"

struct resource_key;
struct resource_pack_slot;

struct resource_directory
{
    uint8_t *get_resource(const resource_key &resource_id, int *a3, resource_pack_slot **a4)
    {
        auto func = bit_cast<fastcall_call>(0x0052AA70);
        return (uint8_t *) func(this, 0, &resource_id, a3, a4);
    }
};
