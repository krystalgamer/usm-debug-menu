#pragma once

#include "func_wrapper.h"

struct resource_key
{
    struct {
        unsigned int field_0;

        const char *to_string()
        {
            auto func = bit_cast<fastcall_call>(0x005374B0);
            return (const char *) func(this);
        }

    } field_0;
    int field_4;
};

resource_key create_resource_key_from_path(const char *in_string, int a3)
{
    resource_key key;
    CDECL_CALL(0x004217B0, &key, in_string, a3);

    return key;
}
