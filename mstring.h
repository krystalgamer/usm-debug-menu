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
};


