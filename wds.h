#pragma once

#include "variable.h"

struct entity;
struct terrain;

struct world_dynamics_system
{
    char field_0[0x1AC];
    terrain *the_terrain;
    char field_1B0[0x40 * 2];
    entity *field_230[1];
    int field_234;
    int num_players;

    entity *get_hero_ptr(int index) {
        constexpr auto MAX_GAME_PLAYERS = 1;

        assert(index >= 0 && index <= MAX_GAME_PLAYERS);

        auto *result = this->field_230[index];
        return result;
    }

    void remove_player(int player_num)
    {
        void (__fastcall *func)(void *, void *, int) = bit_cast<decltype(func)>(0x00558550);

        func(this, nullptr, player_num);
    }

    int add_player(const mString &a2)
    {
        int (__fastcall *func)(void *, void *, const mString *) = bit_cast<decltype(func)>(0x0055B400);

        return func(this, nullptr, &a2);
    }

};

VALIDATE_OFFSET(world_dynamics_system, field_230, 0x230);

inline Var<world_dynamics_system *> g_world_ptr{0x0095C770};

