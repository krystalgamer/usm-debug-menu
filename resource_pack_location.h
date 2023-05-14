#pragma once

#include "common.h"
#include "resource_key.h"

struct resource_location
{
    resource_key field_0;
    int filed_8;
    int m_size;
};

struct resource_pack_location 
{
    resource_location loc;
    int field_10[7];
    int field_2C;
    char field_30[32];
};

VALIDATE_SIZE(resource_pack_location, 0x50);
VALIDATE_OFFSET(resource_pack_location, field_2C, 0x2C);
