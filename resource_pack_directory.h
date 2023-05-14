#pragma once

struct resource_directory;

struct resource_pack_directory
{
    resource_directory *field_0;

    resource_directory *get_resource_directory() {
        return this->field_0;
    }
};
