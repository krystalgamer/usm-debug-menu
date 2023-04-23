#pragma once

struct resource_key
{
    int field_0;
    int field_4;
};

resource_key create_resource_key_from_path(const char *in_string, int a3)
{
    resource_key key;
    CDECL_CALL(0x004217B0, &key, in_string, a3);

    return key;
}
