#pragma once

#include "variable.h"
#include "common.h"

struct game_process
{
    const char *field_0;
    int *field_4;
    int index;
    int num_states;
    int field_10;
    bool field_14;
};

inline Var<game_process> lores_game_process{0x00922074};

struct game
{
    char field_0[0x6C];
    struct {
        int field_0;
        game_process *m_first;
        game_process *m_last;
        game_process *m_end;

        auto &back()
        {
            return *(m_last - 1);
        }
    } process_stack;

    int field_7C[59];

    struct {
        bool level_is_loaded;
        bool single_step;
        bool physics_enabled;
        bool field_3;
        bool game_paused;
    } flag;
    bool field_16D;
    bool field_16E;
    bool field_16F;
    bool field_170;
    bool field_171;
    bool field_172;

    void enable_physics(bool a2)
    {
        void __fastcall (*func)(void*, int, bool) = (decltype(func)) 0x00515230;
        func(this, 0, a2);
    }

    void push_process(game_process &process) {
        void __fastcall (*sub_570FD0)(void *, int, void *) = (decltype(sub_570FD0)) 0x00570FD0;

        sub_570FD0(&this->process_stack, 0, &process);

        auto &last_proc = this->process_stack.back();
        last_proc.index = 0;
        last_proc.field_10 = 0;
    }

    void push_lores()
    {
        this->push_process(lores_game_process());
    }

    void begin_hires_screenshot(int a2, int a3)
    {
        void __fastcall (*func)(void *, void *, int, int) = (decltype(func)) 0x00548C10;
        func(this, nullptr, a2, a3);
    }
};

VALIDATE_OFFSET(game, field_172, 0x172);

inline Var<game *> g_game_ptr{0x009682E0};
