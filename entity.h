#pragma once

#include "common.h"
#include "vtbl.h"
#include "vector3d.h"

struct region;
struct po;

struct entity
{
    int m_vtbl;
    char field_0[0x18];
    struct {
        int field_0;
    } my_handle;

    void suspend(bool a1) {
        auto &func = get_vfunc(m_vtbl, 0x1B8);

        func(this, 0, a1);
    }

    void unsuspend(bool a1) {
        auto &func = get_vfunc(m_vtbl, 0x1BC);

        func(this, 0, a1);
    }

    region * get_primary_region()
    {
        region *(__fastcall *func)(void *) = bit_cast<decltype(func)>(0x004C0760);
        return func(this);
    }

    vector3d *get_abs_position()
    {
        vector3d * (__fastcall *func)(void *) = bit_cast<decltype(func)>(0x0048AC00);
        return func(this);
    }

    po *get_abs_po()
    {
        po * (__fastcall *func)(void *) = bit_cast<decltype(func)>(0x0048AC20);
        return func(this);
    }
};

VALIDATE_OFFSET(entity, my_handle, 0x1C);
