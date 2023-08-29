#pragma once

#include "common.h"
#include "fixedstring.h"

struct nalAnyPose {};

template<typename T>
struct nalAnimClass {
    struct nalInstanceClass {};

    std::intptr_t m_vtbl;
    nalAnimClass<nalAnyPose> *field_4;
    tlFixedString field_8;
    int field_28;
    int field_2C;
    void *Skeleton;
    int field_34;
    int field_38;
    int field_3C;
};

struct nalAnimFile {
    uint32_t field_0;
    char field_4[0x30];
    void *field_34;
};

VALIDATE_OFFSET(nalAnimFile, field_34, 0x34);
