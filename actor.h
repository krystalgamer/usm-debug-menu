#pragma once

#include "common.h"

struct ai_player_controller;

struct actor 
{
    char field_0[0x8C];
    ai_player_controller *m_player_controller;

    ai_player_controller *get_player_controller() {
        return this->m_player_controller;
    }
};

VALIDATE_OFFSET(actor, m_player_controller, 0x8C);
