#pragma once

#include "common.h"
#include "string_hash.h"
#include "vtbl.h"
#include "vector3d.h"

#include "list.hpp"

struct region;
struct po;

struct entity
{
    int m_vtbl;
    int field_4;
    int field_8;
    int field_C;
    string_hash field_10;
    int field_14;
    int field_18;
    struct {
        int field_0;
    } my_handle;

    auto &get_id() const {
        return this->field_10;
    }

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

    bool is_an_actor() const {
        bool (__fastcall *func)(const void *) =
            bit_cast<decltype(func)>(get_vfunc(m_vtbl, 0x64));
        return func(this);
    }

    static int find_entities(int a1)
    {
        return CDECL_CALL(0x004D67D0, a1);
    }

    static inline Var<_std::list<entity *> *> found_entities {0x0095A6E0};
};

VALIDATE_OFFSET(entity, my_handle, 0x1C);
