#pragma once

#include "bit.h"

struct PanelQuad;
struct PanelFile;

struct fe_health_widget {
    PanelFile *field_0[5];
    int field_14[7];
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    PanelQuad *field_40;
    PanelQuad *field_44;
    PanelQuad *field_48;
    float field_4C;
    float field_50;
    bool field_54;
    bool field_55;
    bool field_56;

    void SetShown(bool a2) {
        void (__fastcall *func)(void *, void *, bool) = bit_cast<decltype(func)>(0x0061A3F0);

        func(this, nullptr, a2);
    }

    void SetType(int the_type, int a3)
    {
        void (__fastcall *func)(void *, void *, int, int) = bit_cast<decltype(func)>(0x00641BC0);

        func(this, nullptr, the_type, a3);
    }
};
