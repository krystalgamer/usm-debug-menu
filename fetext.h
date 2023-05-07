#pragma once

#include "float.hpp"
#include "func_wrapper.h"
#include "color32.h"
#include "common.h"

struct font_index
{
    int field_0;
};

struct global_text_enum
{
    int field_0;
};

struct panel_layer
{
    int field_0;
};

struct FEText
{
    char field_0[0x18];
    font_index field_18;
    mString field_1C;
    int field_2C;
    int field_30;
    float field_34;
    float field_38;
    float field_3C;
    float field_40;
    float field_44;
    float field_48;
    color32 field_4C;
    mString field_50;
    int field_60;
    int8_t field_64;

    FEText(font_index a2,
           global_text_enum a3,
           Float a4,
           Float a5,
           int a6,
           panel_layer a7,
           Float a8,
           int a9,
           int a10,
           color32 a11)
    {
        void (__fastcall *func)(void *, void *, font_index, global_text_enum, Float, Float,
                int, panel_layer, Float, int, int, color32) = bit_cast<decltype(func)>(0x00617500);

        func(this, 0, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11);
    }

    void Draw()
    {
        void (__fastcall *func)(void *) = bit_cast<decltype(func)>(0x00617640);
        func(this);
    }
};

VALIDATE_OFFSET(FEText, field_1C, 0x1C);
