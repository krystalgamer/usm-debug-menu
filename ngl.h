#pragma once

#include "float.hpp"
#include "func_wrapper.h"
#include "utility.h"
#include "variable.h"

#include <psapi.h>
#include <windows.h>

#include <d3d9.h>

struct nglFont
{};

struct nglDebug_t
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    uint8_t RenderSingleNode;
    int field_14;
    uint8_t ShowPerfInfo;
    uint8_t ShowPerfBar;
    uint8_t ScreenShot;
    uint8_t DisableQuads;
    uint8_t field_1C;
    uint8_t field_1D;
    uint8_t DisableVSync;
    uint8_t DisableScratch;
    uint8_t DebugPrints;
    uint8_t DumpFrameLog;
    uint8_t DumpMesh;
    uint8_t DumpTextures;
    uint8_t DrawLightSpheres;
    uint8_t DrawMeshSpheres;
    uint8_t DisableDuplicateMaterialWarning;
    uint8_t DisableMissingTextureWarning;
};

VALIDATE_SIZE(nglDebug_t, 0x28);

inline Var<nglDebug_t> nglDebug {0x00975830};
inline Var<nglDebug_t> nglSyncDebug {0x009758E0};

struct nglPerfomanceInfo
{
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    LARGE_INTEGER field_20;
    LARGE_INTEGER field_28;
    LARGE_INTEGER field_30;
    LARGE_INTEGER field_38;
    LARGE_INTEGER field_40;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
    float m_fps;
    float field_5C;
    float field_60;
    float m_render_time;
    float m_cpu_time;
    float field_6C;
    float field_70;
    float field_74;
    float field_78;
    float field_7C;
    float field_80;
    float field_84;
};

VALIDATE_SIZE(nglPerfomanceInfo, 0x88);
VALIDATE_OFFSET(nglPerfomanceInfo, m_fps, 0x58);

inline Var<nglPerfomanceInfo> nglPerfInfo {0x00975858};
inline Var<nglPerfomanceInfo> nglSyncPerfInfo {0x00975908};

struct nglQuad {
	BYTE unk[100];
};

VALIDATE_SIZE(nglQuad, 0x64);

void nglInitQuad(nglQuad *Quad)
{
    CDECL_CALL(0x0077AC40, Quad);
}

void nglSetQuadRect(nglQuad *Quad, Float a2, Float a3, Float a4, Float a5)
{
    CDECL_CALL(0x0077AD30, Quad, a2, a3, a4, a5);
}

void nglSetQuadColor(nglQuad *Quad, uint32_t Color)
{
    CDECL_CALL(0x0077AD10, Quad, Color);
}

void nglListAddQuad(nglQuad *Quad)
{
    CDECL_CALL(0x0077AFE0, Quad);
}

void nglSetQuadZ(nglQuad *Quad, Float Z)
{
    CDECL_CALL(0x0077AD70, Quad, Z);
}


void nglGetStringDimensions(nglFont *Font, const char *a2, int *a3, int *a4, Float a5, Float a6) {
    CDECL_CALL(0x007798E0, Font, a2, a3, a4, a5, a6);
}

uint8_t *nglGetDebugFlagPtr(const char *Flag)
{
    if ( strcmpi(Flag, "ShowPerfInfo") == 0 ) {
        return &nglDebug().ShowPerfInfo;
    }

    if ( strcmpi(Flag, "ShowPerfBar") == 0 ) {
        return &nglDebug().ShowPerfBar;
    }

    if ( strcmpi(Flag, "ScreenShot") == 0 ) {
        return &nglDebug().ScreenShot;
    }

    if ( strcmpi(Flag, "DisableQuads") == 0 ) {
        return &nglDebug().DisableQuads;
    }

    if ( strcmpi(Flag, "DisableVSync") == 0 ) {
        return &nglDebug().DisableVSync;
    }

    if ( strcmpi(Flag, "DisableScratch") == 0 ) {
        return &nglDebug().DisableScratch;
    }

    if ( strcmpi(Flag, "DebugPrints") == 0 ) {
        return &nglDebug().DebugPrints;
    }

    if ( strcmpi(Flag, "DumpFrameLog") == 0 ) {
        return &nglDebug().DumpFrameLog;
    }

    if ( strcmpi(Flag, "DumpSceneFile") == 0 ) {
        return &nglDebug().DumpMesh;
    }

    if ( strcmpi(Flag, "DumpTextures") == 0 ) {
        return &nglDebug().DumpTextures;
    }

    if ( strcmpi(Flag, "DrawLightSpheres") == 0 ) {
        return &nglDebug().DrawLightSpheres;
    }

    if ( strcmpi(Flag, "DrawMeshSpheres") == 0 ) {
        return &nglDebug().DrawMeshSpheres;
    }

    if ( strcmpi(Flag, "DisableDuplicateMaterialWarning") == 0 ) {
        return &nglDebug().DisableDuplicateMaterialWarning;
    }

    if ( strcmpi(Flag, "DisableMissingTextureWarning") == 0 ) {
        return &nglDebug().DisableMissingTextureWarning;
    }

    if ( strcmpi(Flag, "RenderSingleNode") == 0 ) {
        return &nglDebug().RenderSingleNode;
    }

    return nullptr;
}

uint8_t nglGetDebugFlag(const char *Flag)
{
    auto *Ptr = nglGetDebugFlagPtr(Flag);

    uint8_t result = 0;
    if ( Ptr != nullptr ) {
        result = *Ptr;
    }

    return result;
}

void nglSetDebugFlag(const char *Flag, uint8_t Set)
{
    auto *Ptr = nglGetDebugFlagPtr(Flag);
    if ( Ptr != nullptr ) {
        *Ptr = Set;
    }

    nglSyncDebug() = nglDebug();
}


Var<nglFont *> nglSysFont{0x00975208};

void nglListAddString(nglFont *font, const char *a2, Float a3, Float a4, Float z_value, int a6, Float a7, Float a8)
{
    CDECL_CALL(0x00779C40, font, a2, a3, a4, z_value, a6, a7, a8);
}

void nglListAddString(nglFont *a1, Float a2, Float a3, Float a4, unsigned int a5, Float a6, Float a8, const char *Format, ...)
{
    char buffer[1024];
    va_list Args;

    va_start(Args, Format);
    vsprintf(buffer, Format, Args);
    nglListAddString(a1, buffer, a2, a3, a4, a5, a6, a8);
}

void nglListAddString_3(nglFont *a1, Float a2, Float a3, Float a4, unsigned int a5, Float a6, Float a8, const char *Format, ...)
{
    char buffer[1024];
    va_list Args;

    va_start(Args, Format);
    vsprintf(buffer, Format, Args);
    nglListAddString(a1, buffer, a2, a3, a4, a5, a6, a8);
}

void nglListAddString(nglFont *font, Float arg4, Float a3, Float a4, Float a5, Float a6, const char *a2, ...)
{
    char a1[1024];
    va_list va;

    va_start(va, a2);
    vsprintf(a1, a2, va);

    nglListAddString(font, a1, arg4, a3, a4, -1, a5, a6);
}

size_t sub_74A650()
{
    size_t v0 = 0;

    MEMORYSTATUS Buffer;
    GlobalMemoryStatus(&Buffer);

    auto dwTotalPhys = Buffer.dwTotalPhys;
    GetCurrentProcess();

    auto CurrentProcessId = GetCurrentProcessId();
    auto v3 = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, false, CurrentProcessId);

    PROCESS_MEMORY_COUNTERS ppsmemCounters;
    if ( GetProcessMemoryInfo(v3, &ppsmemCounters, sizeof(ppsmemCounters)) ) {
        v0 = dwTotalPhys - ppsmemCounters.PeakWorkingSetSize;
    }

    CloseHandle(v3);
    return v0;
}

inline Var<int> nglFlipCycle {0x00972674};
inline Var<int> nglLastFlipCycle {0x00972678};

enum nglFrameLockType {};

inline Var<nglFrameLockType> nglFrameLock {0x0093AED0};

inline Var<int> nglVBlankCount {0x00972908};

inline Var<bool> nglFlipQueued {0x0097267C};

inline Var<int> nglLastFlipVBlank {0x00972670};

inline Var<int> nglFrameLockImmediate {0x00972668};

LARGE_INTEGER query_perf_counter()
{
    LARGE_INTEGER PerformanceCount;

    QueryPerformanceCounter(&PerformanceCount);
    return PerformanceCount;
}

void sub_76DD70()
{
    nglLastFlipCycle() = nglFlipCycle();
    nglFlipCycle() = query_perf_counter().LowPart;
    nglLastFlipVBlank() = nglVBlankCount();
    nglFlipQueued() = false;

    printf("nglFlipCycle = %d, nglLastFlipCycle = %d\n", nglFlipCycle(), nglLastFlipCycle());
}

void nglSetFrameLock(nglFrameLockType a2)
{
    printf("nglSetFrameLock\n");

    CDECL_CALL(0x0076E750, a2);
}

void nglQueueFlip()
{
    printf("nglQueueFlip: nglFrameLock = %d, nglVBlankCount = %d, nglLastFlipVBlank = %d, nglFrameLockImmediate = %d\n",
            nglFrameLock(), nglVBlankCount(), nglLastFlipVBlank(), nglFrameLockImmediate() );

    if (0
        //nglFrameLock()
        && (!nglFrameLockImmediate() || nglVBlankCount() - nglLastFlipVBlank() < (unsigned int)nglFrameLock() ) )
    {
        nglFlipQueued() = true;
    }
    else
    {
        sub_76DD70();
    }
}

void nglRenderPerfInfo()
{
    printf("nglRenderPerfInfo\n");

    if constexpr (0) {
        char Dest[2048];

        static Var<char[1]> byte_8B7DF8 = {0x008B7DF8};

        static Var<int> nglVif1WorkSize = {0x00971F10};

        if (nglSyncDebug().ShowPerfInfo == 1) {
            printf("%f\n", nglSyncPerfInfo().m_fps);
            size_t v0 = sub_74A650();
            sprintf(Dest,
                    byte_8B7DF8(),
                    "FINAL",
                    nglSyncPerfInfo().m_fps, 
                    nglSyncPerfInfo().m_render_time,
                    nglSyncPerfInfo().m_cpu_time,
                    nglSyncPerfInfo().field_70,
                    nglSyncPerfInfo().field_74,
                    nglSyncPerfInfo().field_18,
                    nglSyncPerfInfo().field_1C,
                    nglSyncPerfInfo().field_7C,
                    nglSyncPerfInfo().field_78,
                    nglSyncPerfInfo().field_80,
                    nglSyncPerfInfo().field_0,
                    nglVif1WorkSize(),
                    nglSyncPerfInfo().field_8,
                    nglSyncPerfInfo().field_C,
                    nglSyncPerfInfo().field_10,
                    nglSyncPerfInfo().field_14,
                    nglDebug().field_8,
                    nglDebug().field_C,
                    *(int *) &nglDebug().RenderSingleNode,
                    v0);
        } else {
            sprintf(Dest,
                    "%.2f FPS\n%.2fms\n",
                    nglSyncPerfInfo().m_fps,
                    nglSyncPerfInfo().m_render_time);
        }

        uint32_t a3;
        uint32_t a4;

        nglGetStringDimensions(nglSysFont(), Dest, (int *)&a3, (int *) &a4, 1.0, 1.0);

        nglQuad a1;
        nglInitQuad(&a1);
        float v1 = a4 + 10;
        float v2 = 620 - a3;
        nglSetQuadRect(&a1, v2, 10.0, 640.0, v1);

        nglSetQuadColor(&a1, 0xC0000000);
        nglSetQuadZ(&a1, -9999.0);
        nglListAddQuad(&a1);
        float v3 = (630 - a3);
        nglListAddString(nglSysFont(), Dest, v3, 20.0, -9999.0, -1, 1.0, 1.0);
    } else {

        if (nglSyncDebug().ShowPerfInfo == 1) {
            float v1 = (nglFlipCycle() - nglLastFlipCycle()) / 733333.31;
            printf("%f %f %f\n", nglSyncPerfInfo().m_fps, nglSyncPerfInfo().field_6C, v1);
        }

        CDECL_CALL(0x0076E0E0);

        nglQueueFlip();
    }
}

BOOL sub_76D1C0()
{
    BOOL result;
    struct tagMSG Msg;

    for ( result = PeekMessageA(&Msg, 0, 0, 0, 1u);
            result;
            result = PeekMessageA(&Msg, 0, 0, 0, 1u) )
    {
        TranslateMessage(&Msg);
        DispatchMessageA(&Msg);
    }

    return result;
}

int __fastcall sub_781EA0(void *a1)
{
    int (__fastcall *func)(void *) = bit_cast<decltype(func)>(0x00781EA0);
    return func(a1);
}

void sub_76E800()
{
    CDECL_CALL(0x0076E800);
}

inline Var<bool> byte_971F9C {0x00971F9C};

inline Var<int> nglFrame {0x00972904};

void nglFlip(bool a1)
{
    printf("nglFlip\n");

    ++nglVBlankCount();

    static Var<IDirect3DDevice9 *> g_Direct3DDevice {0x00971F94};
    g_Direct3DDevice()->BeginScene();

    void *v1 = nullptr;
    sub_781EA0(v1);
    g_Direct3DDevice()->EndScene();
    if ( !byte_971F9C()
            && g_Direct3DDevice()->Present(0, 0, 0, 0) == 0x88760868 )
    {
        Sleep(0x64u);
        if ( g_Direct3DDevice()->TestCooperativeLevel() == 0x88760869 ) {
            sub_76E800();
        }
    }

    sub_76D1C0();
    ++nglFrame();
    if ( a1 ) {
        nglQueueFlip();
    }
}

void nglListSend(bool a1)
{
    //nglRenderDebug();
    CDECL_CALL(0x0076EA10, a1);
}

void ngl_patch()
{
    REDIRECT(0x005AD264, nglSetFrameLock);
    REDIRECT(0x0076E966, nglSetFrameLock);

    REDIRECT(0x0076ECF3, nglFlip); 

    REDIRECT(0x0076EA59, nglRenderPerfInfo);
}
