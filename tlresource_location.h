#pragma once

#include "string_hash.h"

enum tlresource_type {
    TLRESOURCE_TYPE_NONE = 0,
    TLRESOURCE_TYPE_TEXTURE = 1,
    TLRESOURCE_TYPE_MESH_FILE = 2,
    TLRESOURCE_TYPE_MESH = 3,
    TLRESOURCE_TYPE_MORPH_FILE = 4,
    TLRESOURCE_TYPE_MORPH = 5,
    TLRESOURCE_TYPE_MATERIAL_FILE = 6,
    TLRESOURCE_TYPE_MATERIAL = 7,
    TLRESOURCE_TYPE_ANIM_FILE = 8,
    TLRESOURCE_TYPE_ANIM = 9,
    TLRESOURCE_TYPE_SCENE_ANIM = 10,
    TLRESOURCE_TYPE_SKELETON = 11,
    TLRESOURCE_TYPE_Z = 12
};

struct tlresource_location {
    string_hash name;
    uint32_t m_type;
    char *field_8;
};
