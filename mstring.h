#pragma once

#include "func_wrapper.h"

struct mString
{
    int field_0;
    int m_size;
    const char *guts;
    int field_C;

    mString(const char *str)
    {
        typedef int (__fastcall* mString_constructor_ptr)(mString* , void* edx, const char* str);
        mString_constructor_ptr mString_constructor = (mString_constructor_ptr) 0x00421100;
        mString_constructor(this, 0, str);
    }

    ~mString()
    {
        typedef int (__fastcall* mString_finalize_ptr)(mString* , void* edx, int zero);
        mString_finalize_ptr mString_finalize = (mString_finalize_ptr) 0x004209C0;

        mString_finalize(this, 0, 0);
    }

    const char *c_str() const
    {
        return guts;
    }



};


