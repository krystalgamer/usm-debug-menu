#pragma once

#include "common.h"
#include "vtbl.h"

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
};

VALIDATE_OFFSET(entity, my_handle, 0x1C);
