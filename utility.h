#pragma once

#include <cstdint>

#include "bit.h"

template<typename Func>
void SET_JUMP(std::ptrdiff_t addr, Func my_func) {
    *bit_cast<uint8_t *>(addr) = 0xE9; //JUMP

    *bit_cast<uint32_t *>(bit_cast<uint8_t *>(addr + 1)) = (bit_cast<uint32_t>(my_func)) - addr - 5;

    *bit_cast<uint8_t *>(addr + 0x5) = 0xC3; //RET
};

template<typename Func>
void REDIRECT(std::ptrdiff_t addr, Func my_func) {
    *bit_cast<uint8_t *>(addr) = 0xE8; //CALL
    *bit_cast<uint32_t *>(
        bit_cast<uint8_t *>(addr + 1)) = (bit_cast<uint32_t>(my_func)) - addr - 5;
    //sp_log("Patched address %08X with %s", addr, #my_func);
}

template<typename Func, typename = typename std::enable_if_t<std::is_member_function_pointer_v<Func>>>
void *func_address(Func func) {
    auto result = reinterpret_cast<void *&>(func);

    return result;
}
