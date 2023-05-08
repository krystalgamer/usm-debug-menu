#pragma once

#include <cstdint>

#include "fixedstring32.h"

namespace MemoryUnitManager
{
    struct Container {
        int empty[144];
        int field_240;
        int field_244;
        char field_248[64];
    };
}

struct game_data_essentials {
    short field_0;
    short field_2;
    short field_4;
    short field_6;
    short field_8;
    short field_A;
    int field_C;
    int field_10;
    char field_14[25];
    char field_2E[12];
};

VALIDATE_SIZE(game_data_essentials, 0x3C);

struct game_data_meat {
    int m_hero_points;
    int field_4;
    int m_upg_impact_web_pts;
    int m_upg_hero_meter_pts;
    int field_10;
    int field_14;
    int field_18;
    int m_hero_meter_level_1;
    int m_hero_meter_level_2;
    int m_hero_meter_level_3;
    int m_cur_hero_meter_lvl;
    int m_cur_hero_meter_pts;
    bool m_opt_score_display;
    bool field_31;
    int field_34;
    float field_38;
    float field_3C;
    int field_40;
    bool m_mini_map_enabled;
    bool m_enable_web_shot;
    bool field_46;
    bool field_47;
    bool m_web_gloves;
    bool m_adv_web_gloves;
    bool m_enable_impact_web;
    bool m_adv_impact_web;
    bool m_web_cowboy;
    bool field_4D;
    bool field_4E;
    bool field_4F;
    bool field_50;
    bool field_51;
    bool field_52;
    int m_difficulty;
    float m_run_sensitivity;
    bool field_5C;
    bool field_5D;
    bool m_show_style_points;
    float m_hero_health;
    int m_hero_type;
    int m_swing_speed;
    bool field_6C;
    bool field_6D;
    bool field_6E;
    bool field_6F;
    bool field_70;
    bool field_71;
    bool field_72;
    bool field_73;
    bool field_74;
    bool field_75;
    bool field_76;
    bool field_77;
    bool field_78;
    bool field_79;
    bool field_7A;
    bool field_7B;
    bool field_7C;
    bool field_7D;
    bool field_7E;
    int field_80;
    int field_84;
    int field_88;
    int field_8C;
    int field_90;
    float field_94;
    float field_98;
    float field_9C;
    float m_miles_web_zipping;
    float m_web_fluid_used;
    int field_A8;
    int field_AC;
    int field_B0;
    int field_B4;
    int field_B8;
    float field_BC;
    float field_C0;
    float field_C4;
    int field_C8;
    int field_CC;
    int field_D0;
    int field_D4;
    int field_D8;
    int field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    int field_EC;
    int field_F0;
    int field_F4;
    int field_F8;
    int field_FC;
    int field_100;
    int field_104;
    int field_108;
    int field_10C;
    int field_110;
    fixedstring32 field_114;
    fixedstring32 field_134;
};

struct game_settings {
    std::intptr_t m_vtbl;
    MemoryUnitManager::Container field_4;
    game_data_essentials field_28C[3]{};
    game_data_meat field_340;
    char *field_494;
    char *field_498;
    char *field_49C[3];
    char field_4A8[12];
    int field_4B4;
    int field_4B8;
    bool field_4BC[3];
    bool field_4BF;
    bool field_4C0;
    bool field_4C1;
    bool field_4C2;
    int m_slot_num;
    int field_4C8;
};

VALIDATE_SIZE(game_settings, 0x4CCu);
