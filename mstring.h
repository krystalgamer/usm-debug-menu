#pragma once

#include "func_wrapper.h"

struct mString
{
    int field_0;
    int m_size;
    const char *guts;
    int field_C;

    mString()
    {
        THISCALL(0x00420F00, this);
    }

    mString(const mString &a2)
    {
        THISCALL(0x00421220, this, &a2);
    }

    mString(int , const char *Format, ...)
    {
        char Dest[1024];
        va_list Args;

        va_start(Args, Format);
        vsprintf(Dest, Format, Args);
        CDECL_CALL(0x00420F60, this, 0, Dest);
    }

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

    mString &operator=(const mString &a2)
    {
        if (this != &a2)
        {
            this->update_guts(a2.c_str(), a2.m_size);
        }

        return (*this);
    }

    mString &operator=(const char *a2)
    {
        this->update_guts(a2, -1);
        return (*this);
    }


    void update_guts(const char* a2, signed int a3) {

        typedef void(__fastcall* mString_update_guts_ptr)(void *, void* edx, const char* a2, signed int a3);
        mString_update_guts_ptr mString_update_guts = (mString_update_guts_ptr) 0x41F9D0;

        //printf("mString:%s\n", a2);


        return mString_update_guts(this, 0, a2, a3);
    }

    const char *c_str() const
    {
        return guts;
    }

    void append(const char *from_string, size_t Count)
    {
        THISCALL(0x0041FAB0, this, from_string, Count);
    }

    mString &operator+=(const mString &a1)
    {
        this->append(a1.c_str(), -1);
        return (*this); 
    }

    friend mString operator+(const char *a2, const mString &a3)
    {
        mString result;
        CDECL_CALL(0x00421410, &result, a2, &a3);
        return result;
    }

    friend mString operator+(const mString &a2, const mString &a3)
    {
        mString result;
        CDECL_CALL(0x00421330, &result, &a2, &a3);
        return result;
    }

};


