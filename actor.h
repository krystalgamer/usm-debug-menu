#pragma once

#include "common.h"

struct ai_player_controller;
struct physical_interface;

struct actor 
{
    char field_0[0x8C];
    ai_player_controller *m_player_controller;

    ai_player_controller *get_player_controller() {
        return this->m_player_controller;
    }

    physical_interface *physical_ifc()
    {
        physical_interface * (__fastcall *func)(void *) = bit_cast<decltype(func)>(0x004B8B40);
        return func(this);
    }
};

VALIDATE_OFFSET(actor, m_player_controller, 0x8C);
