#pragma once

#include "variable.h"
#include "common.h"

struct input_mgr
{
    int field_0;
    struct {

        void disable_vibration()
        {
            void (__fastcall *func)(void *) = (decltype(func)) 0x005C5440;
            func(this);
        }

        void enable_vibration()
        {
            void (__fastcall *func)(void *) = (decltype(func)) 0x005C5430;
            func(this);
        }

    } *rumble_ptr;
    int field_8[10];
    void *field_30[1];

    static inline Var<input_mgr *> instance{0x009685DC};
};

VALIDATE_OFFSET(input_mgr, field_30, 0x30);
