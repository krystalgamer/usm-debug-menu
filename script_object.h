#pragma once

#include "bit.h"
#include "string_hash.h"

struct vm_executable;

struct script_object {

    string_hash field_0;
	uint8_t unk[0x1C];
	struct vm_executable** funcs;
    int total_funcs;

    int find_func(string_hash a2) const {
        int (__fastcall* func)(const script_object *, void *edx, string_hash a2) = bit_cast<decltype(func)>(0x0058EF80);
        return func(this, nullptr, a2);
    }

};
