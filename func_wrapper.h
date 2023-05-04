#pragma once

#include "bit.h"

typedef int(__cdecl *cdecl_call)(...);
typedef int(__stdcall *stdcall_call)(...);
typedef int(__fastcall *fastcall_call)(...);

template<typename... Args>
decltype(auto) THISCALL(int address, const void *obj, Args... args) {

    if constexpr(sizeof...(args))
    {
        return (bit_cast<fastcall_call>(address))(obj, 0, args...);
    }
    else
    {
        return (bit_cast<fastcall_call>(address))(obj);
    }
}

template<typename... Args>
decltype(auto) STDCALL(int address, Args... args) {

    return (reinterpret_cast<stdcall_call>(address))(args...);
}

template<typename... Args>
decltype(auto) CDECL_CALL(int address, Args... args) {

    return (reinterpret_cast<cdecl_call>(address))(args...);
}
