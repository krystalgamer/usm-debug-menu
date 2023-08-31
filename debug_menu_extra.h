#pragma once

#include "debug_menu.h"
#include "entity_tracker_manager.h"
#include "game_settings.h"

void district_variants_handler(debug_menu_entry *entry)
{
    auto *the_terrain = g_world_ptr()->the_terrain;
    if ( the_terrain != nullptr )
    {
        auto idx = entry->get_id();
        auto *reg = the_terrain->get_region(idx);
        auto ival = entry->get_ival();
        auto district_id = reg->get_district_id();
        the_terrain->set_district_variant(district_id, ival, true);
    }
}

std::string district_variants_render_callback(debug_menu_entry *a2)
{
    if ( a2 != nullptr && g_world_ptr()->the_terrain != nullptr )
    {
        auto *the_terrain = g_world_ptr()->the_terrain;
        auto idx = a2->get_id();
        auto *reg = the_terrain->get_region(idx);
        auto v4 = reg->get_district_variant_count() - 1;
        auto district_variant = reg->get_district_variant();

        char str[100]{};
        snprintf(str, 100, "%d [0, %d]", district_variant, v4);
        return {str};
    }
    else
    {
        auto a1 = entry_render_callback_default(a2);
        return a1;
    }
}

void populate_district_variants_menu(debug_menu_entry *entry)
{
    printf("populate_district_variants_menu\n");
    auto *v5 = create_menu(entry->text);
    entry->set_submenu(v5);
    auto *the_terrain = g_world_ptr()->the_terrain;
    if ( the_terrain != nullptr )
    {
        auto num_regions = the_terrain->get_num_regions();
        for ( auto idx = 0; idx < num_regions; ++idx )
        {
            auto *reg = the_terrain->get_region(idx);
            auto district_variant = reg->get_district_variant();
            auto district_variant_count = reg->get_district_variant_count();
            if ( district_variant_count > 1 )
            {
                auto &name = reg->get_name();
                auto *v4 = name.to_string();
                debug_menu_entry v11 {mString {v4}};

                v11.set_id(idx);
                v11.set_render_cb(district_variants_render_callback);
                v11.set_ival(district_variant);
                v11.set_min_value(0.0);
                v11.set_max_value((float)(district_variant_count - 1));
                v11.set_game_flags_handler(district_variants_handler);
                v5->add_entry(&v11);
            }
        }
    }
}

void create_debug_district_variants_menu(debug_menu *parent)
{
    debug_menu_entry v5 {mString {"District variants"}};

    v5.set_submenu(nullptr);
    v5.set_game_flags_handler(populate_district_variants_menu);
    parent->add_entry(&v5);
}

void populate_gamefile_menu(debug_menu_entry *entry)
{
    auto &v1 = entry->text;
    auto *v2 = create_menu(v1, handle_game_entry, 200);

    auto *v494 = v2;
    entry->set_submenu(v2);
    if ( g_game_ptr() != nullptr )
    {
        auto *v493 = g_game_ptr()->get_game_settings();

        auto v3 = debug_menu_entry(mString {"HERO_POINTS"});
        auto &v492 = v3;
        v492.set_p_ival(&v493->field_340.m_hero_points);
        v492.set_max_value(1000.0);
        v494->add_entry(&v492);

        auto v4 = debug_menu_entry(mString {"UPG_MINIMAP_PTS"});
        auto &v491 = v4;
        v491.set_p_ival(&v493->field_340.field_4);
        v491.set_max_value(1000.0);
        v494->add_entry(&v491);

        auto v5 = debug_menu_entry(mString {"UPG_IMPACT_WEB_PTS"});
        v5.set_p_ival(&v493->field_340.m_upg_impact_web_pts);
        v5.set_max_value(1000.0);
        v494->add_entry(&v5);

        auto v6 = debug_menu_entry(mString {"UPG_HERO_METER_PTS"});
        v6.set_p_ival(&v493->field_340.m_upg_hero_meter_pts);
        v6.set_max_value(1000.0);
        v2->add_entry(&v6);

        auto v7 = debug_menu_entry(mString {"UPG_2ND_CHANCE_PTS"});
        v7.set_p_ival(&v493->field_340.field_10);
        v7.set_max_value(1000.0);
        v494->add_entry(&v7);

        auto v8 = debug_menu_entry(mString {"UPG_SPEED_PTS"});
        v8.set_p_ival(&v493->field_340.field_14);
        v8.set_max_value(1000.0);
        v494->add_entry(&v8);

        auto v9 = debug_menu_entry(mString {"UPG_UNDERDOG_PTS"});
        v9.set_p_ival(&v493->field_340.field_18);
        v9.set_max_value(1000.0);
        v494->add_entry(&v9);

        auto v10 = debug_menu_entry(mString {"HERO_METER_LEVEL_1"});
        v10.set_p_ival(&v493->field_340.m_hero_meter_level_1);
        v10.set_max_value(1000.0);
        v494->add_entry(&v10);

        auto v11 = debug_menu_entry(mString {"HERO_METER_LEVEL_2"});
        v11.set_p_ival(&v493->field_340.m_hero_meter_level_2);
        v11.set_max_value(1000.0);
        v494->add_entry(&v11);

        auto v12 = debug_menu_entry(mString {"HERO_METER_LEVEL_3"});
        v12.set_p_ival(&v493->field_340.m_hero_meter_level_3);
        v12.set_max_value(1000.0);
        v494->add_entry(&v12);

        auto v13 = debug_menu_entry(mString {"CUR_HERO_METER_LEVEL"});
        v13.set_p_ival(&v493->field_340.m_cur_hero_meter_lvl);
        v13.set_max_value(1000.0);
        v494->add_entry(&v13);

        auto v14 = debug_menu_entry(mString {"CUR_HERO_METER_POINTS"});
        v14.set_p_ival(&v493->field_340.m_cur_hero_meter_pts);
        v14.set_max_value(1000.0);
        v2->add_entry(&v14);

        auto v15 = debug_menu_entry(mString {"OPT_SCORE_DISPLAY"});
        auto &v480 = v15;
        v15.set_pt_bval(&v493->field_340.m_opt_score_display);
        v15.set_max_value(1000.0);
        v2->add_entry(&v15);

        auto v16 = debug_menu_entry(mString {"OPT_CONT_1_RUMBLE"});
        v16.set_pt_bval(&v493->field_340.field_31);
        v16.set_max_value(1000.0);
        v2->add_entry(&v16);

        auto v17 = debug_menu_entry(mString {"OPT_AUDIO_MODE"});
        v17.set_p_ival(&v493->field_340.field_34);
        v17.set_max_value(1000.0);
        v2->add_entry(&v17);

        auto v18 = debug_menu_entry(mString {"OPT_LEVELS_GAME"});
        v18.set_pt_fval(&v493->field_340.field_38);
        v18.set_max_value(1000.0);
        v2->add_entry(&v18);

        auto v19 = debug_menu_entry(mString {"OPT_LEVELS_MUSIC"});
        v19.set_pt_fval(&v493->field_340.field_3C);
        v19.set_max_value(1000.0);
        v2->add_entry(&v19);

        auto v20 = debug_menu_entry(mString {"OPT_CONT_CONFIG"});
        v20.set_p_ival(&v493->field_340.field_40);
        v20.set_max_value(1000.0);
        v2->add_entry(&v20);

        auto v21 = debug_menu_entry(mString {"MINI_MAP_ENABLED"});
        v21.set_pt_bval(&v493->field_340.m_mini_map_enabled);
        v21.set_max_value(1000.0);
        v2->add_entry(&v21);

        auto v22 = debug_menu_entry(mString {"ENABLE_WEB_SHOT"});
        v22.set_pt_bval(&v493->field_340.m_enable_web_shot);
        v22.set_max_value(1000.0);
        v2->add_entry(&v22);

        auto v23 = debug_menu_entry(mString {"ENABLE_WEB_DOME"});
        v23.set_pt_bval(&v493->field_340.field_46);
        v23.set_max_value(1000.0);
        v2->add_entry(&v23);

        auto v24 = debug_menu_entry(mString {"ENABLE_ADV_WEB_DOME"});
        v24.set_pt_bval(&v493->field_340.field_47);
        v24.set_max_value(1000.0);
        v2->add_entry(&v24);

        auto v25 = debug_menu_entry(mString {"ENABLE_WEB_GLOVES"});
        v25.set_pt_bval(&v493->field_340.m_web_gloves);
        v25.set_max_value(1000.0);
        v2->add_entry(&v25);

        auto v26 = debug_menu_entry(mString {"ENABLE_ADV_WEB_GLOVES"});
        v26.set_pt_bval(&v493->field_340.m_adv_web_gloves);
        v26.set_max_value(1000.0);
        v2->add_entry(&v26);

        auto v27 = debug_menu_entry(mString {"ENABLE_IMPACT_WEB"});
        v27.set_pt_bval(&v493->field_340.m_enable_impact_web);
        v27.set_max_value(1000.0);
        v2->add_entry(&v27);

        auto v28 = debug_menu_entry(mString {"ENABLE_ADV_IMPACT_WEB"});
        v28.set_pt_bval(&v493->field_340.m_adv_impact_web);
        v28.set_max_value(1000.0);
        v2->add_entry(&v28);

        auto v29 = debug_menu_entry(mString {"ENABLE_WEB_COWBOY"});
        v29.set_pt_bval(&v493->field_340.m_web_cowboy);
        v29.set_max_value(1000.0);
        v2->add_entry(&v29);

        auto v30 = debug_menu_entry(mString {"ENABLE_WEB_YANK"});
        v30.set_pt_bval(&v493->field_340.field_4D);
        v30.set_max_value(1000.0);
        v2->add_entry(&v30);

        auto v31 = debug_menu_entry(mString {"ENABLE_YANK_MANIP"});
        v31.set_pt_bval((bool *)&v493->field_340.field_4E);
        v31.set_max_value(1000.0);
        v2->add_entry(&v31);

        auto v32 = debug_menu_entry(mString {"ENABLE_ZIP_WEB_ATTACK"});
        v32.set_pt_bval((bool *)&v493->field_340.field_4F);
        v32.set_max_value(1000.0);
        v2->add_entry(&v32);

        auto v33 = debug_menu_entry(mString {"ENABLE_SWING_CANNONBALL"});
        v33.set_pt_bval(&v493->field_340.field_50);
        v33.set_max_value(1000.0);
        v2->add_entry(&v33);

        auto v34 = debug_menu_entry(mString {"ENABLE_DIRECTIONAL_ATTACK"});
        v34.set_pt_bval(&v493->field_340.field_51);
        v34.set_max_value(1000.0);
        v2->add_entry(&v34);

        auto v35 = debug_menu_entry(mString {"ENABLE_DIRECTIONAL_DODGE"});
        v35.set_pt_bval(&v493->field_340.field_52);
        v35.set_max_value(1000.0);
        v2->add_entry(&v35);

        auto v36 = debug_menu_entry(mString {"DIFFICULTY"});
        v36.set_p_ival(&v493->field_340.m_difficulty);
        v36.set_max_value(1000.0);
        v2->add_entry(&v36);

        auto v37 = debug_menu_entry(mString {"RUN_SENSITIVITY"});
        v37.set_pt_fval(&v493->field_340.m_run_sensitivity);
        v37.set_max_value(1000.0);
        v2->add_entry(&v37);

        auto v38 = debug_menu_entry(mString {"CHAR_REL_MOVEMENT"});
        v38.set_pt_bval((bool *)&v493->field_340.field_5C);
        v38.set_max_value(1000.0);
        v2->add_entry(&v38);

        auto v39 = debug_menu_entry(mString {"CRAWL_CHAR_REL_MOVEMENT"});
        v39.set_pt_bval((bool *)&v493->field_340.field_5D);
        v39.set_max_value(1000.0);
        v2->add_entry(&v39);

        auto v40 = debug_menu_entry(mString {"SHOW_STYLE_SCORE"});
        v40.set_pt_bval(&v493->field_340.m_show_style_points);
        v40.set_max_value(1000.0);
        v2->add_entry(&v40);

        auto v41 = debug_menu_entry(mString {"HERO_HEALTH"});
        v41.set_pt_fval(&v493->field_340.m_hero_health);
        v41.set_max_value(1000.0);
        v2->add_entry(&v41);

        auto v42 = debug_menu_entry(mString {"HERO_TYPE"});
        v42.set_p_ival(&v493->field_340.m_hero_type);
        v42.set_max_value(1000.0);
        v2->add_entry(&v42);

        auto v43 = debug_menu_entry(mString {"SWING_SPEED"});
        v43.set_p_ival(&v493->field_340.m_swing_speed);
        v43.set_max_value(1000.0);
        v2->add_entry(&v43);

        auto v44 = debug_menu_entry(mString {"CAM_INVERTED_X"});
        v44.set_pt_bval((bool *)&v493->field_340.field_6C);
        v44.set_max_value(1000.0);
        v2->add_entry(&v44);

        auto v45 = debug_menu_entry(mString {"CAM_INVERTED_Y"});
        v45.set_pt_bval((bool *)&v493->field_340.field_6D);
        v45.set_max_value(1000.0);
        v2->add_entry(&v45);

        auto v46 = debug_menu_entry(mString {"SPEED_DEMON"});
        v46.set_pt_bval((bool *)&v493->field_340.field_6E);
        v46.set_max_value(1000.0);
        v2->add_entry(&v46);

        auto v47 = debug_menu_entry(mString {"YOURE_AMAZING"});
        v47.set_pt_bval((bool *)&v493->field_340.field_6F);
        v47.set_max_value(1000.0);
        v2->add_entry(&v47);

        auto v48 = debug_menu_entry(mString {"ERRAND_BOY"});
        v48.set_pt_bval((bool *)&v493->field_340.field_70);
        v48.set_max_value(1000.0);
        v2->add_entry(&v48);

        auto v49 = debug_menu_entry(mString {"BETTER_TO_DO"});
        v49.set_pt_bval(&v493->field_340.field_71);
        v49.set_max_value(1000.0);
        v2->add_entry(&v49);

        auto v50 = debug_menu_entry(mString {"FANBOY"});
        v50.set_pt_bval(&v493->field_340.field_72);
        v50.set_max_value(1000.0);
        v2->add_entry(&v50);

        auto v51 = debug_menu_entry(mString {"ANGSTY"});
        v51.set_pt_bval(&v493->field_340.field_73);
        v51.set_max_value(1000.0);
        v2->add_entry(&v51);

        auto v52 = debug_menu_entry(mString {"SECRET_IDENTITY"});
        v52.set_pt_bval(&v493->field_340.field_74);
        v52.set_max_value(1000.0);
        v2->add_entry(&v52);

        auto v53 = debug_menu_entry(mString {"STYLE"});
        v53.set_pt_bval(&v493->field_340.field_75);
        v53.set_max_value(1000.0);
        v2->add_entry(&v53);

        auto v54 = debug_menu_entry(mString {"FASHION"});
        v54.set_pt_bval(&v493->field_340.field_76);
        v54.set_max_value(1000.0);
        v2->add_entry(&v54);

        auto v55 = debug_menu_entry(mString {"PICTURES"});
        v55.set_pt_bval(&v493->field_340.field_77);
        v55.set_max_value(1000.0);
        v2->add_entry(&v55);

        auto v56 = debug_menu_entry(mString {"BUNNY"});
        v56.set_pt_bval(&v493->field_340.field_78);
        v56.set_max_value(1000.0);
        v2->add_entry(&v56);

        auto v57 = debug_menu_entry(mString {"CLOBBER"});
        v57.set_pt_bval(&v493->field_340.field_79);
        v57.set_max_value(1000.0);
        v2->add_entry(&v57);

        auto v58 = debug_menu_entry(mString {"SCRAP_HEAP"});
        v58.set_pt_bval(&v493->field_340.field_7A);
        v58.set_max_value(1000.0);
        v2->add_entry(&v58);

        auto v59 = debug_menu_entry(mString {"SILVER_SPOON"});
        v59.set_pt_bval(&v493->field_340.field_7B);
        v59.set_max_value(1000.0);
        v2->add_entry(&v59);

        auto v60 = debug_menu_entry(mString {"KUNG_FU_FIGHTING"});
        v60.set_pt_bval(&v493->field_340.field_7C);
        v60.set_max_value(1000.0);
        v2->add_entry(&v60);

        auto v61 = debug_menu_entry(mString {"BIG_TIME_SUPER_HERO"});
        v61.set_pt_bval(&v493->field_340.field_7D);
        v61.set_max_value(1000.0);
        v2->add_entry(&v61);

        auto v62 = debug_menu_entry(mString {"ENJOY_THE_SUNSHINE"});
        v62.set_pt_bval(&v493->field_340.field_7E);
        v62.set_max_value(1000.0);
        v2->add_entry(&v62);

        auto v63 = debug_menu_entry(mString {"TIME_PLAYED"});
        v63.set_p_ival(&v493->field_340.field_80);
        v63.set_max_value(1000.0);
        v2->add_entry(&v63);

        auto v64 = debug_menu_entry(mString {"STORY_PERCENT_COMPLETE"});
        v64.set_p_ival(&v493->field_340.field_84);
        v64.set_max_value(1000.0);
        v2->add_entry(&v64);

        auto v65 = debug_menu_entry(mString {"STORY_MISSION_FAILURES"});
        v65.set_p_ival(&v493->field_340.field_88);
        v65.set_max_value(1000.0);
        v2->add_entry(&v65);

        auto v66 = debug_menu_entry(mString {"STORY_MISSIONS_COMPLETED"});
        v66.set_p_ival(&v493->field_340.field_8C);
        v66.set_max_value(1000.0);
        v2->add_entry(&v66);

        auto v67 = debug_menu_entry(mString {"SPIDEY_RACES_COMPLETED"});
        v67.set_p_ival(&v493->field_340.field_90);
        v67.set_max_value(1000.0);
        v2->add_entry(&v67);

        auto v68 = debug_menu_entry(mString {"MILES_RUN_SPIDEY"});
        v68.set_pt_fval(&v493->field_340.field_94);
        v68.set_max_value(1000.0);
        v2->add_entry(&v68);

        auto v69 = debug_menu_entry(mString {"MILES_CRAWLED_SPIDEY"});
        v69.set_pt_fval(&v493->field_340.field_98);
        v69.set_max_value(1000.0);
        v2->add_entry(&v69);

        auto v70 = debug_menu_entry(mString {"MILES_WEB_SWINGING"});
        v70.set_pt_fval(&v493->field_340.field_9C);
        v70.set_max_value(1000.0);
        v2->add_entry(&v70);

        auto v71 = debug_menu_entry(mString {"MILES_WEB_ZIPPING"});
        v71.set_pt_fval(&v493->field_340.m_miles_web_zipping);
        v71.set_max_value(1000.0);
        v2->add_entry(&v71);

        auto v72 = debug_menu_entry(mString {"WEB_FLUID_USED"});
        v72.set_pt_fval(&v493->field_340.m_web_fluid_used);
        v72.set_max_value(1000.0);
        v2->add_entry(&v72);

        auto v73 = debug_menu_entry(mString {"YANCY_DEFEATED"});
        v73.set_p_ival(&v493->field_340.field_A8);
        v73.set_max_value(1000.0);
        v2->add_entry(&v73);

        auto v74 = debug_menu_entry(mString {"DIE_CASTEDEFEATED"});
        v74.set_p_ival(&v493->field_340.field_AC);
        v74.set_max_value(1000.0);
        v2->add_entry(&v74);

        auto v75 = debug_menu_entry(mString {"HIGH_ROLLERSDEFEATED"});
        v75.set_p_ival(&v493->field_340.field_B0);
        v75.set_max_value(1000.0);
        v2->add_entry(&v75);

        auto v76 = debug_menu_entry(mString {"FOU_TOU_BANGDEFEATED"});
        v76.set_p_ival(&v493->field_340.field_B4);
        v76.set_max_value(1000.0);
        v2->add_entry(&v76);

        auto v77 = debug_menu_entry(mString {"VENOM_RACES_COMPLETED"});
        v77.set_p_ival(&v493->field_340.field_B8);
        v77.set_max_value(1000.0);
        v2->add_entry(&v77);

        auto v78 = debug_menu_entry(mString {"MILES_RUN_VENOM"});
        v78.set_pt_fval(&v493->field_340.field_BC);
        v78.set_max_value(1000.0);
        v2->add_entry(&v78);

        auto v79 = debug_menu_entry(mString {"MILES_CRAWLED_VENOM"});
        v79.set_pt_fval(&v493->field_340.field_C0);
        v79.set_max_value(1000.0);
        v2->add_entry(&v79);

        auto v80 = debug_menu_entry(mString {"MILES_LOCOMOTION_JUMPED"});
        v80.set_pt_fval(&v493->field_340.field_C4);
        v80.set_max_value(1000.0);
        v2->add_entry(&v80);

        auto v81 = debug_menu_entry(mString {"PEOPLE_EATEN"});
        v81.set_p_ival(&v493->field_340.field_C8);
        v81.set_max_value(1000.0);
        v2->add_entry(&v81);

        auto v82 = debug_menu_entry(mString {"CARS_THROWN"});
        v82.set_p_ival(&v493->field_340.field_CC);
        v82.set_max_value(1000.0);
        v2->add_entry(&v82);

        auto v83 = debug_menu_entry(mString {"VENOM_HOT_PERSUIT"});
        v83.set_p_ival(&v493->field_340.field_D0);
        v83.set_max_value(1000.0);
        v2->add_entry(&v83);

        auto v84 = debug_menu_entry(mString {"TOKENS_COLLECTED_COUNT"});
        v84.set_p_ival(&v493->field_340.field_D4);
        v84.set_max_value(1000.0);
        v2->add_entry(&v84);

        auto v85 = debug_menu_entry(mString {"RACE_POINTS_EARNED_COUNT"});
        v85.set_p_ival(&v493->field_340.field_D8);
        v85.set_max_value(1000.0);
        v2->add_entry(&v85);

        auto v86 = debug_menu_entry(mString {"COMBAT_TOURS_COMPLETED_COUNT"});
        v86.set_p_ival(&v493->field_340.field_DC);
        v86.set_max_value(1000.0);
        v2->add_entry(&v86);

        auto v87 = debug_menu_entry(mString {"CITY_EVENTS_COMPLETED_COUNT"});
        v87.set_p_ival(&v493->field_340.field_E0);
        v87.set_max_value(1000.0);
        v2->add_entry(&v87);

        auto v88 = debug_menu_entry(mString {"TOKENS_COLLECTED_MAX"});
        v88.set_p_ival(&v493->field_340.field_E4);
        v88.set_max_value(1000.0);
        v2->add_entry(&v88);

        auto v89 = debug_menu_entry(mString {"RACE_POINTS_EARNED_MAX"});
        v89.set_p_ival(&v493->field_340.field_E8);
        v89.set_max_value(1000.0);
        v2->add_entry(&v89);

        auto v90 = debug_menu_entry(mString {"COMBAT_TOURS_COMPLETED_MAX"});
        v90.set_p_ival(&v493->field_340.field_EC);
        v90.set_max_value(1000.0);
        v2->add_entry(&v90);

        auto v91 = debug_menu_entry(mString {"CITY_EVENTS_COMPLETED_MAX"});
        v91.set_p_ival(&v493->field_340.field_F0);
        v91.set_max_value(1000.0);
        v2->add_entry(&v91);

        auto v92 = debug_menu_entry(mString {"TOKENS_COLLECTED_TOT_COUNT"});
        v92.set_p_ival(&v493->field_340.field_F4);
        v92.set_max_value(1000.0);
        v2->add_entry(&v92);

        auto v93 = debug_menu_entry(mString {"RACE_POINTS_EARNED_TOT_COUNT"});
        v93.set_p_ival(&v493->field_340.field_F8);
        v93.set_max_value(1000.0);
        v2->add_entry(&v93);

        auto v94 = debug_menu_entry(mString {"COMBAT_TOURS_COMPLETED_TOT_COUNT"});
        auto &v401 = v94;
        v401.set_p_ival(&v493->field_340.field_FC);
        v401.set_max_value(1000.0);
        v2->add_entry(&v401);

        auto v95 = debug_menu_entry(mString {"CITY_EVENTS_COMPLETED_TOT_COUNT"});
        v95.set_p_ival(&v493->field_340.field_100);
        v95.set_max_value(1000.0);
        v494->add_entry(&v95);

        auto v96 = debug_menu_entry(mString {"TOKENS_COLLECTED_TOT_MAX"});
        v96.set_p_ival(&v493->field_340.field_104);
        v96.set_max_value(1000.0);
        v494->add_entry(&v96);

        auto v97 = debug_menu_entry(mString {"RACE_POINTS_EARNED_TOT_MAX"});
        v97.set_p_ival(&v493->field_340.field_108);
        v97.set_max_value(1000.0);
        v494->add_entry(&v97);

        auto v98 = debug_menu_entry(mString {"COMBAT_TOURS_COMPLETED_TOT_MAX"});
        v98.set_p_ival(&v493->field_340.field_10C);
        v98.set_max_value(1000.0);
        v494->add_entry(&v98);

        auto v99 = debug_menu_entry(mString {"CITY_EVENTS_COMPLETED_TOT_MAX"});
        auto &v396 = v99;
        v396.set_p_ival(&v493->field_340.field_110);
        v396.set_max_value(1000.0);
        v494->add_entry(&v396);
    }
}

void create_gamefile_menu(debug_menu *parent)
{
    assert(parent != nullptr);

    auto v5 = debug_menu_entry(mString{"Saved Game Settings"});
    parent->add_entry(&v5);

    debug_menu_entry *entry = &parent->entries[parent->used_slots - 1];
    populate_gamefile_menu(entry);
}

void warp_handler(debug_menu_entry *entry)
{
    auto idx = entry->get_id();
    auto *the_terrain = g_world_ptr()->the_terrain;
    if ( the_terrain != nullptr )
    {
        auto *reg = the_terrain->get_region(idx);
        if ( reg->is_locked() )
        {
            auto district_id = reg->get_district_id();
            auto *v1 = g_world_ptr()->get_the_terrain();
            v1->unlock_district(district_id);
        }

        auto *v2 = &reg->field_A4;
        g_world_ptr()->malor_point(v2, 0, false);
    }

    debug_menu::hide();
}

void warp_poi_handler(debug_menu_entry *menu_entry)
{
    auto *v2 = g_femanager().IGO->field_54;
    if ( v2 != nullptr )
    {
        vector3d a1{};
        if ( v2->get_the_arrow_target_pos(&a1) )
        {
            g_world_ptr()->malor_point(&a1, 0, false);
            debug_menu::hide();
        }
    }
}

void populate_warp_menu(debug_menu_entry *entry)
{
    printf("populate_warp_menu");

    auto *v20 = create_menu(entry->text);
    entry->set_submenu(v20);

    debug_menu_entry v19 {mString {"--WARP TO POI--"}};
    v19.set_game_flags_handler(warp_poi_handler);
    v20->add_entry(&v19);
    auto *the_terrain = g_world_ptr()->the_terrain;
    if ( the_terrain != nullptr )
    {
        auto num_regions = the_terrain->get_num_regions();
        for ( auto idx = 0; idx < num_regions; ++idx )
        {
            auto *reg = the_terrain->get_region(idx);
            if ( (reg->flags & 0x4000) != 0 )
            {
                auto &name = reg->get_name();
                auto *v4 = name.to_string();

                debug_menu_entry v15 {mString {v4}};
                v15.set_id(idx);
                v15.set_game_flags_handler(warp_handler);
                v20->add_entry(&v15);
            }
        }
    }
}

void create_warp_menu(debug_menu *parent)
{
    debug_menu_entry v5 {mString {"Warp"}};

    v5.set_submenu(nullptr);
    v5.set_game_flags_handler(populate_warp_menu);
    parent->add_entry(&v5);
}
