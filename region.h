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
	uint8_t status;
	uint8_t unk1[0x53];
	float x;
	float y;
	float z;
	uint8_t unk2[0x10];
	DWORD district_id;
	uint8_t unk3[0x4];
	uint8_t variants;
	uint8_t unk4[0x6B];

    const char *get_name() {
        return this->mash_info->field_0.str;
    }

    int get_district_id() {
        constexpr auto REGION_UNINITIALIZED_DISTRICT_ID = 0;

        assert(district_id != REGION_UNINITIALIZED_DISTRICT_ID && "dsg and sin probably out of sync");

        return this->district_id;
    }
};

VALIDATE_OFFSET(region, mash_info, 0x2C);
VALIDATE_OFFSET(region, district_id, 0xC0);
