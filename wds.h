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

    auto *get_the_terrain() {
        return the_terrain;
    }

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

    void malor_point(const vector3d *a2, int a3, bool a4)
    {
        void (__fastcall *func)(void *, void *, const vector3d *, int, bool) = bit_cast<decltype(func)>(0x00530460);
        func(this, nullptr, a2, a3, a4);
    }

    int add_player(const mString &a2)
    {
        int (__fastcall *func)(void *, void *, const mString *) = bit_cast<decltype(func)>(0x0055B400);

        return func(this, nullptr, &a2);
    }

};

VALIDATE_OFFSET(world_dynamics_system, field_230, 0x230);

inline Var<world_dynamics_system *> g_world_ptr{0x0095C770};

