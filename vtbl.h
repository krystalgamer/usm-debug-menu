#pragma once

#include "bit.h"
#include "func_wrapper.h"

#include <type_traits>

template<typename T, typename = typename std::enable_if_t<std::is_pointer_v<T>>>
void *&get_vtbl(T p) {
    static_assert(sizeof(int) == sizeof(void *), "");

    return reinterpret_cast<void *&>((bit_cast<int *>(p))[0]);
}

inline auto *&get_vfunc(std::intptr_t vtbl, int offset) {
    auto *v = bit_cast<fastcall_call(*)[1]>(vtbl);

    return ((*v)[offset / 4]);
}

template<typename T, typename = typename std::enable_if_t<std::is_pointer_v<T>>>
void set_vtbl(T p, std::ptrdiff_t address) {
    static_assert(sizeof(int) == sizeof(void *), "");

    (bit_cast<int *>(p))[0] = address;
}
