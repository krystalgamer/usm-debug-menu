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
        return (region *) THISCALL(0x004C0760, this);
    }

    vector3d *get_abs_position()
    {
        return (vector3d *) THISCALL(0x0048AC00, this);
    }

    po *get_abs_po()
    {
        return (po *) THISCALL(0x0048AC20, this);
    }
};

VALIDATE_OFFSET(entity, my_handle, 0x1C);
