#pragma once

#include <cstdint>

#include "bit.h"

template<typename Func>
void SET_JUMP(std::ptrdiff_t addr, Func my_func) {
    *bit_cast<uint8_t *>(addr) = 0xE9; //JUMP

    *bit_cast<uint32_t *>(bit_cast<uint8_t *>(addr + 1)) = (bit_cast<uint32_t>(my_func)) - addr - 5;

    *bit_cast<uint8_t *>(addr + 0x5) = 0xC3; //RET
};
