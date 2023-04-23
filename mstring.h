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
        fastcall_call func = bit_cast<fastcall_call>(0x0041FE30);
        func(this, 0, a2);
        return (*this);
    }
};


