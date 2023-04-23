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
};

VALIDATE_OFFSET(world_dynamics_system, field_230, 0x230);

inline Var<world_dynamics_system *> g_world_ptr{0x0095C770};

