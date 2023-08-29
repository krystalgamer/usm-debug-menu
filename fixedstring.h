#pragma once

#include <cstdint>
#include <cassert>

template<uint32_t Num>
struct fixedstring
{
    static inline auto MAX_CHARS = Num;

    char field_0[Num];

    fixedstring(const char *str)
    {
        assert(str != nullptr);

        auto len = strlen(str);
        if ( len > 16 )
        {
            printf("String too big for fixed size, str is %s", str);
            assert(0);
        }

        assert(len <= MAX_CHARS);

        std::memcpy(this->field_0, str, len);
    }

    const char *to_string() const
    {
        return field_0;
    }

    bool operator==(const fixedstring<Num> &a2)
    {
        for ( auto i = 0; i < 2; ++i )
        {
            if ( *(const int *)&this->field_0[8 * i] != *(const int *)&a2.field_0[8 * i]
                || *(const int *)&this->field_0[8 * i + 4] != *(const int *)&a2.field_0[8 * i + 4] )
            {
                return false;
            }
        }

        return true;
    }

};

struct tlFixedString {
    uint32_t m_hash;
    char field_4[28];

    auto GetHash() const {
        return this->m_hash;
    }

    const char *to_string() const {
        return field_4;
    }
};
