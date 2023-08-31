#pragma once

#include "common.h"
#include "region_mash_info.h"

struct region {
    char field_0[0x2C];
    region_mash_info *mash_info;
    void *region_entities;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    int field_4C;
	int flags;
	uint8_t unk1[0x50];
    vector3d field_A4;
    float field_B0[3];
    float field_BC;
	DWORD district_id;
	uint8_t unk3[0x4];
	uint8_t variants;
	uint8_t unk4[0x6B];

    fixedstring32 &get_name() {
        return this->mash_info->field_0;
    }

    bool is_locked() const
    {
        return this->flags & 1;
    }

    int get_district_variant_count() const
    {
        return bit_cast<int *>(bit_cast<char *>(this) + 0xC8)[0];
    }

    int get_district_variant() {
        int (__fastcall *func)(void *) = bit_cast<decltype(func)>(0x005503D0);
        return func(this);
    }

    int get_district_id() {
        constexpr auto REGION_UNINITIALIZED_DISTRICT_ID = 0;

        assert(district_id != REGION_UNINITIALIZED_DISTRICT_ID && "dsg and sin probably out of sync");

        return this->district_id;
    }
};

VALIDATE_OFFSET(region, mash_info, 0x2C);
VALIDATE_OFFSET(region, flags, 0x50);
VALIDATE_OFFSET(region, district_id, 0xC0);
VALIDATE_SIZE(region, 0x134);
