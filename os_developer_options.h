#pragma once

#include "variable.h"
#include "func_wrapper.h"

struct mString;

struct os_developer_options
{
    bool m_flags[150];
    mString m_strings[14];
    int m_ints[76];

    int get_int(const mString &a2)
    {
        return this->m_ints[this->get_int_from_name(a2)];
    }

    static inline Var<const char *[76]> int_names { 0x00936940 };

    static inline Var<int[76]> int_defaults{0x00936A70};

    int get_int_from_name(const mString &a1) {
        const char **v2 = int_names();
        do {
            if (_strcmpi(*v2, a1.c_str()) == 0) {
                break;
            }

            ++v2;
        
        } while (v2 != bit_cast<const char **>(&int_defaults()));

        int v3 = v2 - int_names();
        if (v3 == 76) {
            printf("Nonexistent int %s", a1.c_str());
        }

        return v3;
    }

    static inline Var<const char *[150]> flag_names { 0x00936420 };

    static inline Var<BOOL[150]> flag_defaults{0x00936678};

    int get_flag_from_name(const mString &a1) {
        const char **v2 = flag_names();
        do {
            if (_strcmpi(*v2, a1.guts) == 0) {
                break;
            }

            ++v2;
        } while (v2 != (const char **) flag_defaults());

        int v3 = v2 - flag_names();
        if (v3 == 150) {
            printf("Nonexistent option flag %s", a1.c_str());
        }

        return v3;
    }

    bool get_flag(const mString &a2)
    {
        return this->m_flags[this->get_flag_from_name(a2)];
    }

    static inline Var<os_developer_options *> instance{0x0096858C};
};
