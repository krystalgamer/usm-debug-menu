#pragma once

#include "bit.h"

struct script_object;

struct script_executable {

    char field_0[0x28];
    script_object **field_28;
    script_object **script_objects_by_name;
    int total_script_objects;

    void add_allocated_stuff(int a2, int a3, int a4) {
        void  (__fastcall *func)(script_executable *, void *edx, int a2, int a3, int a4) = bit_cast<decltype(func)>(0x005A34B0);
        func(this, nullptr, a2, a3, a4);
    }

};

