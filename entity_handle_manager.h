#pragma once

struct string_hash;
struct entity;

enum entity_flavor_t {
    ACTOR = 0,
    SIGNALLER = 1,
    CAMERA = 2,
    BASE = 3,
    ENTITY = 4,
    MARKER = 5,
    PARKING_MARKER = 6,
    WATER_EXIT_MARKER = 7,
    MIC = 8,
    LIGHT_SOURCE = 9,
    PFX = 10,
    ITEM = 11,
    CONGLOMERATE = 12,
    CONGLOMERATE_CLONE = 13,
    BEAM = 14,
    MANIP = 15,
    SWITCH = 16,
    POLYTUBE = 17,
    LENSFLARE = 18,
    NEOLIGHT = 19,
    GAME_CAMERA = 20,
    SPIDERMAN_CAMERA = 21,
    MARKY_CAMERA = 22,
    SNIPER_CAMERA = 23,
    AI_CAMERA = 24,
    ANCHOR_MARKER = 25,
    LINE_ANCHOR = 26,
    AI_COVER_MARKER = 27,
    NULL_FLAVOR = 28,
    IGNORE_FLAVOR = 29,
};

namespace entity_handle_manager
{
    entity *find_entity(const string_hash &a1, entity_flavor_t a2, bool a3)
    {
        return (entity *) CDECL_CALL(0x004DC300, &a1, a2, a3);
    }
}
