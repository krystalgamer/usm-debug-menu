#pragma once

#include "func_wrapper.h"

struct mString
{
    int field_0;
    int m_size;
    const char *guts;
    int field_C;

    const char *c_str() const
    {
        return guts;
    }

    mString &operator=(const char *a2)
    {
        THISCALL(0x0041FE30, this, a2);
        return (*this);
    }
};


