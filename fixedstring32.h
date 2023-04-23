#pragma once

#include <cstring>
#include <cassert>

struct fixedstring32 {

    static inline constexpr auto MAX_CHARS = 32;

    char str[MAX_CHARS]{};

    fixedstring32() = default;

    fixedstring32(const char *str) {
        assert(str != nullptr);

        auto len = strlen(str);
        assert(len <= MAX_CHARS && "String too big for fixed size");

        memcpy(this->str, str, len);
    }

    const char *to_string() {
        assert(str[MAX_CHARS - 1] == '\0');

        return this->str;
    }

};
