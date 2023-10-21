#pragma once

struct entity_base;

struct entity_base_vhandle {
    int field_0;

    entity_base *get_volatile_ptr()
    {
        entity_base *(__fastcall *func)(void *) = (decltype(func)) 0x00601580;
        return func(this);
    }
};
