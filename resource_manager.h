#pragma once

#include "func_wrapper.h"
#include "resource_key.h"

struct resource_pack_location;
struct mString;

namespace resource_manager {

    void load_amalgapak()
    {
        CDECL_CALL(0x00537650);
    }

    void reload_amalgapak()
    {
        CDECL_CALL(0x0054C2E0);
    }

    bool can_reload_amalgapak()
    {
        return (bool) CDECL_CALL(0x0053DE90);
    }


    bool get_pack_file_stats(const resource_key &a1,
                                    resource_pack_location *a2,
                                    mString *a3,
                                    int *a4)
    {
        return (bool) CDECL_CALL(0x0052A820, &a1, a2, a3, a4);
    }

}
