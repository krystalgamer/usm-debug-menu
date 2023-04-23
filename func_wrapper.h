#pragma once

#include "bit.h"

typedef int(__cdecl *cdecl_call)(...);
typedef int(__stdcall *stdcall_call)(...);
typedef int(__fastcall *fastcall_call)(...);

template<typename... Args>
decltype(auto) STDCALL(int address, Args... args) {

    return (reinterpret_cast<stdcall_call>(address))(args...);
}

template<typename... Args>
decltype(auto) CDECL_CALL(int address, Args... args) {

    return (reinterpret_cast<cdecl_call>(address))(args...);
}
