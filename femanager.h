#pragma once

#include "float.hpp"
#include "variable.h"

struct nglFont;
struct IGOFrontEnd;
struct PauseMenuSystem;
struct FrontEndMenuSystem;
struct PanelQuad;

struct FEManager {
    FEManager() = default;

    int empty;
    nglFont *field_4[5];
    IGOFrontEnd *IGO;
    PauseMenuSystem *m_pause_menu_system;
    FrontEndMenuSystem *m_fe_menu_system;
    int field_24;
    char field_28;
    char field_29;
    bool field_2A;

    nglFont *GetFont(font_index idx);

    void RenderLoadMeter(bool a2);

    //0x00648FF0
    void InitIGO();

    //0x00618CA0
    void LoadFonts();

    //0x00640E30
    void Draw();

    //0x00638180
    PanelQuad *GetDefaultPQ();

    //0x00642B30
    void Update(Float a2);

    //0x0060B920
    void ReleaseFrontEnd();

    //0x00648AB0
    void LoadFrontEnd();

    //0x00618D10
    void ReleaseFonts();

    void ReleaseFont(font_index idx);

    static const char *font_name_array[5];
};

extern bool sub_581C30();

//0x006299B0
extern void RenderLoadMeter();

inline Var<FEManager> g_femanager{0x00937B00};

extern void FEManager_patch();
