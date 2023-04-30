#pragma once

#include "variable.h"
#include "func_wrapper.h"

struct mString;

struct os_developer_options
{
    int get_int(const mString &a2)
    {
        auto func = bit_cast<fastcall_call>(0x005C2F60);
        return (int) func(this, 0, &a2);
    }

    bool get_flag(const mString &a2)
    {
        auto func = bit_cast<fastcall_call>(0x005C2F20);
        return (bool) func(this, 0, &a2);
    }

    static inline Var<os_developer_options *> instance{0x0096858C};
};
