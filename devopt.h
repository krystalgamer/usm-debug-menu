#pragma once

#include "os_developer_options.h"

#include <cassert>

struct game_option_t
{
    const char *m_name;
    union {
        BOOL *p_bval;
        int *p_ival;
        float *p_fval;
        mString *p_strval;
    } m_value;
    enum {
        UNDEFINED,
        FLAG_OPTION = 1,
        INT_OPTION = 2,
        FLOAT_OPTION = 3,
        STRING_OPTION = 4,
    } m_type;
};


inline constexpr auto NUM_OPTIONS = 150u + 76u;

game_option_t *get_option(int idx)
{
    assert(idx >= 0);
    assert(idx < NUM_OPTIONS);

    static game_option_t option{};

    if (idx < 150)
    {

        auto &name = flag_names()[idx];
        BOOL *flag = &flag_defaults()[idx];

        option.m_name = name;
        option.m_type = game_option_t::FLAG_OPTION;
        option.m_value.p_bval = flag;

        return &option;
    }

    idx = idx - 150;
    auto &name = int_names()[idx];
    auto *i = &int_defaults()[idx];

    option.m_name = name;
    option.m_type = game_option_t::INT_OPTION;
    option.m_value.p_ival = i;

    return &option;
}
