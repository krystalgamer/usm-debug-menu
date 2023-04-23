#pragma once

#include "common.h"
#include "func_wrapper.h"
#include "mashable_vector.h"
#include "wds.h"
#include "actor.h"
#include "ai_player_controller.h"

struct region;

struct mission_condition_instance
{
    char field_0[0x18];
    const char *script_data_name;
    char field_1C[0x38];
    unsigned int field_54;
    mashable_vector<int> field_58;
    int field_60;
    int field_64;

    bool is_flag_set(unsigned int a2)
    {
        return (a2 & this->field_54) != 0;
    }

    const char *get_script_data_name()
    {
        if ( !this->is_flag_set(8) )
        {
            return nullptr;
        }

        //assert(script_data_name != nullptr);

        return this->script_data_name;
    }
};

VALIDATE_SIZE(mission_condition_instance, 0x68);

struct mission_condition
{
    int field_0;
    int field_4;
    mashable_vector<mission_condition_instance> instances;
    mashable_vector<int> field_10;
    const char *field_18;
    const char *field_1C;
    unsigned char field_20;
    char field_21[3];
    char field_24;
    char field_25[3];
    int field_28;
    const char *field_2C;
    const char *field_30;

    bool is_flag_set(unsigned int a2) const
    {
        return (a2 & this->field_28) != 0;
    }

    bool applies_to_current_hero()
    {
        assert(g_world_ptr()->get_hero_ptr( 0 ) != nullptr);

        assert(bit_cast<actor*>(g_world_ptr()->get_hero_ptr( 0 ))->get_player_controller() != nullptr);

        auto *v8 = bit_cast<actor*>(g_world_ptr()->get_hero_ptr( 0 ))->get_player_controller();
        auto v15 = v8->field_420;
        if ( v15 == 1 )
        {
            if ( this->is_flag_set(0x8000) )
            {
                return true;
            }
        }
        else if ( v15 == 2 )
        {
            if ( this->is_flag_set(0x4000) )
            {
                return true;
            }
        }
        else if ( v15 == 3 && this->is_flag_set(0x10000) )
        {
            return true;
        }

        return false;
    }
};

VALIDATE_SIZE(mission_condition, 0x34);

struct mission_table_container {
    char field_0[0x38];
    mashable_vector<mission_condition> field_38;
    int field_40;
    region *field_44;

    struct script_info {
        const char *field_0;
        mission_condition_instance *field_4;
        int field_8;
    };

    region *get_region()
    {
        return this->field_44;
    }

    bool append_script_info(std::vector<mission_table_container::script_info> *info)
    {
        assert(info != nullptr);

        bool v9 = false;
        for ( auto &v6 : this->field_38 )
        {
            if ( v6.applies_to_current_hero() )
            {
                auto v5 = v6.instances.size();
                for ( auto i = 0u; i < v5; ++i )
                {
                    script_info v3;
                    v3.field_0 = v6.field_18;
                    v3.field_4 = &v6.instances.at(i);
                    v3.field_8 = i;
                    info->push_back(v3);
                    v9 = true;
                }
            }
        }

        return v9;
    }
};
