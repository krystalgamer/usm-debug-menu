#pragma once

#include <cassert>

#include "common.h"
#include "resource_pack_directory.h"
#include "resource_directory.h"

struct resource_key;

struct resource_pack_slot
{
    int field_0;
    resource_key field_4;
    int m_slot_state;
    int slot_size;
    int pack_size;
    uint8_t *header_mem_addr;
    resource_pack_directory pack_directory;

    resource_directory &get_resource_directory() {
        //assert(is_data_ready());
        //assert(pack_directory.get_resource_directory() != nullptr);

        return (*this->pack_directory.get_resource_directory());
    }

    uint8_t *get_resource(const resource_key &resource_id,
                                          int *a3,
                                          resource_pack_slot **a4) {
        auto &res_dir = this->get_resource_directory();
        return res_dir.get_resource(resource_id, a3, a4);
    }
};

VALIDATE_OFFSET(resource_pack_slot, pack_directory, 0x1C);
