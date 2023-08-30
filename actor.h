#pragma once

#include "string_hash.h"
#include "animation_controller.h"
#include "common.h"
#include "nal_system.h"
#include "resource_key.h"
#include "resource_pack_slot.h"
#include "vector3d.h"

#include <vector>

struct nalAnyPose;
struct nalBaseSkeleton;

template<typename T>
struct nalAnimClass;

struct ai_player_controller;
struct physical_interface;

struct actor 
{
    char field_0[0x70];
    int field_70;
    animation_controller *anim_ctrl;
    void *adv_ptrs;
    void *field_7C;
    void *m_interactable_ifc;
    void *m_facial_expression_interface;
    int field_88;
    ai_player_controller *m_player_controller;
    char field_90[0xC];
    uint8_t *field_9C;
    void *field_A0;
    int16_t field_A4;
    int16_t field_A6;
    int16_t field_A8[1];
    int16_t field_AA;
    vector3d field_AC;
    int field_B8;
    resource_pack_slot *field_BC;

    ai_player_controller *get_player_controller() {
        return this->m_player_controller;
    }

    physical_interface *physical_ifc()
    {
        physical_interface * (__fastcall *func)(void *) = bit_cast<decltype(func)>(0x004B8B40);
        return func(this);
    }

    void allocate_anim_controller(unsigned int a2, nalBaseSkeleton *a3) {
        void (__fastcall *func)(void *, int, uint32_t, nalBaseSkeleton *) = 
            bit_cast<decltype(func)>(0x004CC630);
        func(this, 0, a2, a3);
    }

    animation_controller::anim_ctrl_handle play_anim(const string_hash &a3);

    static std::vector<nalAnimClass<nalAnyPose> *> get_animations(actor *a1);
};

VALIDATE_OFFSET(actor, m_player_controller, 0x8C);
VALIDATE_OFFSET(actor, field_BC, 0xBC);

std::vector<nalAnimClass<nalAnyPose> *> actor::get_animations(actor *a1)
{
    std::vector<nalAnimClass<nalAnyPose> *> a2;
    a2.reserve(100u);

    auto *v11 = a1->field_BC;
    if ( v11 != nullptr )
    {
        auto &res_dir = v11->get_resource_directory();
        auto tlresource_count = res_dir.get_tlresource_count(TLRESOURCE_TYPE_ANIM_FILE);
        for (auto idx = 0; idx < tlresource_count; ++idx)
        {
            auto *tlres_loc = res_dir.get_tlresource_location(idx, TLRESOURCE_TYPE_ANIM_FILE);
            auto *animFile = (nalAnimFile *) tlres_loc->field_8;
            if ( animFile->field_0 == 0x10101 )
            {
                for ( auto *anim = bit_cast<nalAnimClass<nalAnyPose> *>(animFile->field_34);
                        anim != nullptr;
                        anim = anim->field_4 ) {
                    a2.push_back(anim);
                }
            }
        }
    }

    return a2;
}

animation_controller::anim_ctrl_handle actor::play_anim(const string_hash &a3)
{
    printf("actor::play_anim\n");
    if ( this->anim_ctrl == nullptr ) {
        this->allocate_anim_controller(0u, nullptr);
    }

    assert(anim_ctrl != nullptr);
    this->anim_ctrl->play_base_layer_anim(a3, 0.0, 32u, true);

    animation_controller::anim_ctrl_handle result{};
    result.field_0 = true;
    result.field_8 = bit_cast<decltype(result.field_8)>(this->anim_ctrl);
    return result;
}
