#pragma once

#include "float.hpp"
#include "func_wrapper.h"
#include "utility.h"
#include "variables.h"

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

LARGE_INTEGER query_perf_counter();

void nglQueueFlip();

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

struct nglVertexBuffer
{
    union {
        IDirect3DIndexBuffer9 *m_indexBuffer;
        struct
        {
            int pad;
            uint32_t field_4;
            IDirect3DVertexBuffer9 *m_vertexBuffer;
        };
    };
};

VALIDATE_SIZE(nglVertexBuffer, 0xC);

struct nglScratchBuffer_t
{
    nglVertexBuffer field_0[2];
    IDirect3DIndexBuffer9 *field_18[2];
    int16_t *field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    IDirect3DIndexBuffer9 *field_48;
    nglVertexBuffer field_4C;
};

VALIDATE_SIZE(nglScratchBuffer_t, 0x58);

inline Var<nglScratchBuffer_t> nglScratchBuffer {0x00972A18};

struct nglScene {};

inline Var<nglScene *> nglCurScene {0x00971F00};

inline Var<nglScene *> nglRootScene {0x00971F04};

enum nglSceneParamType {};

inline Var<const float> PCFreq {0x0093A294};

enum nglFrameLockType {};

inline Var<nglFrameLockType> nglFrameLock {0x0093AED0};

inline Var<int> nglFrameLockImmediate {0x00972668};

inline Var<int> nglVBlankCount{0x00972908};

inline Var<int> nglLastFlipVBlank{0x00972670};

inline Var<int> nglFrameVBlankCount = (0x0097290C);

inline Var<DWORD> nglFlipCycle{0x00972674};

inline Var<DWORD> nglLastFlipCycle{0x00972678};

struct nglLightContext {};

inline Var<nglLightContext *> nglDefaultLightContext {0x00973B70};

inline Var<BOOL> nglFlipQueued = {0x00972668};

inline Var<char *> nglListWork {0x00971F08};

inline Var<int> dword_975308 {0x00975308};

inline Var<int> dword_975314 {0x00975314};

inline Var<int> dword_97530C {0x0097530C};

inline Var<int> nglScratchMeshPos {0x00975310};

void nglScreenShot(const char *a1)
{
    CDECL_CALL(0x007731D0, a1);
}

void nglVif1RenderScene()
{
    CDECL_CALL(0x0077D060);
}

void sub_781A30()
{
    ;
}

void sub_76DE60()
{
    nglPerfInfo().field_28 = query_perf_counter();
}

inline Var<float> g_renderTime {0x00972664};

void sub_76DE80()
{
    nglPerfInfo().field_30 = query_perf_counter();
    g_renderTime() = (nglPerfInfo().field_30.QuadPart - nglPerfInfo().field_28.QuadPart) / PCFreq();
    nglQueueFlip();
}

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

void sub_76DE00()
{
    ++nglVBlankCount();
    if ( nglFlipQueued() ) {
        if (nglVBlankCount() - nglLastFlipVBlank() >= nglFrameLock() ) {
            sub_76DD70();
        }
    }
}

void nglInit(HWND hWnd)
{
    printf("nglInit\n");

    CDECL_CALL(0x0076E3E0, hWnd);
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
        //nglFrameLock() )
        )
    {
        if (nglFrameLockImmediate() == 0
                || (nglVBlankCount() - nglLastFlipVBlank()) < (uint32_t) nglFrameLock() )
        {
            nglFlipQueued() = true;
            return;
        }
    }

    sub_76DD70();
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
        CDECL_CALL(0x0076E0E0);
    }
}

void PumpMessages()
{
    struct tagMSG Msg;

    while ( PeekMessageA(&Msg, 0, 0, 0, PM_REMOVE) ) {
        TranslateMessage(&Msg);
        DispatchMessageA(&Msg);
    }
}

int __fastcall sub_781EA0(void *a1)
{
    int (__fastcall *func)(void *) = bit_cast<decltype(func)>(0x00781EA0);
    return func(a1);
}

void Reset3DDevice()
{
    CDECL_CALL(0x0076E800);
}

nglScene *nglListBeginScene(nglSceneParamType a1)
{
    return (nglScene *) CDECL_CALL(0x0076C970, a1);
}

void nglSceneDumpStart()
{
    ;
}

nglLightContext *nglCreateLightContext()
{
    return (nglLightContext *) CDECL_CALL(0x00775EC0);
}

void nglListInit()
{
    printf("nglListInit\n");

    if constexpr (1) {
        nglFrameVBlankCount() = nglVBlankCount();
        nglPerfInfo().field_38 = query_perf_counter();
        nglListWorkPos() = bit_cast<int>(nglListWork());
        nglDefaultLightContext() = nglCreateLightContext();
        if ( nglSyncDebug().DumpFrameLog ) {
            nglDebug().DumpFrameLog = 0;
        }

        if ( nglSyncDebug().DumpMesh ) {
            nglDebug().DumpMesh = 0;
        }

        if ( nglSyncDebug().DumpTextures ) {
            nglDebug().DumpTextures = 0;
        }

        nglSyncDebug() = nglDebug();
        nglCurScene() = nullptr;
        nglListBeginScene(static_cast<nglSceneParamType>(0));
        nglSceneDumpStart();
        auto *v3 = (int16_t *)&nglScratchBuffer().field_0[0].pad;
        auto v0 = nglScratchBuffer().field_44;
        nglScratchBuffer().field_4C = nglScratchBuffer().field_0[v0];

        nglScratchBuffer().field_48 = (IDirect3DIndexBuffer9 *)nglScratchBuffer().field_18[v0];
        if ( nglScratchBuffer().field_4C.m_vertexBuffer != nullptr ) {
            nglScratchBuffer().field_4C.m_vertexBuffer->Lock(0, 0, (void **)&v3, D3DLOCK_DISCARD);
            nglScratchBuffer().field_4C.pad = (int)v3;
        }

        auto *v2 = nglScratchBuffer().field_48;
        if ( v2 != nullptr ) {
            v2->Lock(0, 0, (void **)&v3, 0);
            nglScratchBuffer().field_20 = v3;
        }
    } else {
        CDECL_CALL(0x0076E050);
    }
}

inline Var<bool> byte_971F9C {0x00971F9C};

inline Var<int> nglFrame {0x00972904};

void nglFlip(bool a1)
{
    printf("nglFlip\n");

    ++nglVBlankCount();

    g_Direct3DDevice()->BeginScene();
    sub_781EA0(nullptr);
    g_Direct3DDevice()->EndScene();

    if ( !byte_971F9C()
            && g_Direct3DDevice()->Present(0, 0, 0, 0) == D3DERR_DEVICELOST )
    {
        Sleep(100u);
        if ( g_Direct3DDevice()->TestCooperativeLevel() == D3DERR_DEVICENOTRESET ) {
            Reset3DDevice();
        }
    }

    PumpMessages();
    ++nglFrame();
    if ( a1 ) {
        nglQueueFlip();
    }
}

void nglRenderPerfBar()
{
    CDECL_CALL(0x0077ECF0);
}

void nglRenderDebug()
{
    if ( nglSyncDebug().ShowPerfInfo ) {
        nglRenderPerfInfo();
    }

    if ( nglSyncDebug().ShowPerfBar ) {
        nglRenderPerfBar();
    }
}

void nglListSend(bool Flip)
{
    printf("nglListSend\n");

    if constexpr (1) {
        if ( EnableShader() ) {
            float v10[4] {0, 0, 1, 1};
            g_Direct3DDevice()->SetVertexShaderConstantF(90, v10, 1);
        }

        nglRenderDebug();

        sub_76DE60();
#if 0
        if (nglCurScene() != nglRootScene()) {
            error("nglListSend called while one or more scenes were still active (need to call nglListEndScene).\n");
        }
#endif

        nglPerfInfo().field_28 = query_perf_counter();

        auto v3 = []() {
            auto perf_counter = query_perf_counter();
            LARGE_INTEGER v3 = bit_cast<LARGE_INTEGER>(*(uint64_t *)&perf_counter - nglPerfInfo().field_38.QuadPart);
            return v3;
        }();

        nglPerfInfo().field_38 = v3;
        nglPerfInfo().field_74 = v3.QuadPart / PCFreq();
        nglPerfInfo().field_40 = query_perf_counter();
        nglScratchBuffer().field_44 ^= 1u;
        nglScratchBuffer().field_28 = 0;
        nglScratchBuffer().field_2C = 0;
        nglScratchBuffer().field_24 = 0;
        nglScratchBuffer().field_30 = 0;

        nglScratchBuffer().field_4C.m_vertexBuffer->Unlock();
        nglScratchBuffer().field_48->Unlock();

        nglCurScene() = nglRootScene();

        g_Direct3DDevice()->BeginScene();
        nglVif1RenderScene();
        g_Direct3DDevice()->EndScene();

        sub_781A30();

        sub_76DE80();

        auto v5 = 1.f / PCFreq();
        printf("PCFreq = %f\n", PCFreq());
        nglPerfInfo().field_40.QuadPart = query_perf_counter().QuadPart - nglPerfInfo().field_40.QuadPart;
        nglPerfInfo().field_70 = nglPerfInfo().field_40.QuadPart * v5;
        auto v6 = dword_975308();
        nglPerfInfo().field_18 = nglPerfInfo().field_48 * v5;
        nglPerfInfo().field_1C = nglPerfInfo().field_50 * v5;
        if ( dword_975314() == dword_975308() ) {
            v6 = dword_97530C();
        }

        dword_975314() = v6;
        nglScratchMeshPos() = v6;

        //dword_972AB4 = 0;
        //dword_972ABC = 0;

        g_Direct3DDevice()->SetStreamSource(0, nullptr, 0, 0);
        g_Direct3DDevice()->SetVertexShader(nullptr);
        g_Direct3DDevice()->SetPixelShader(nullptr);

#if 0
        if ( dword_971F24() != nullptr ) {
            dword_971F24()(dword_971F28());
        }
#endif

        float v8 = []() -> double {
            return query_perf_counter().QuadPart - nglPerfInfo().field_20.QuadPart;
        }();

        nglPerfInfo().m_cpu_time = v8 / PCFreq();

#if 0
        if ( dword_971F1C() != nullptr )
            dword_971F1C()(dword_971F20());
#endif

        if ( Flip ) {
            nglFlip(0);
        }

        nglPerfInfo().field_20 = query_perf_counter();
        nglPerfInfo().m_render_time = g_renderTime();
        //sp_log("m_render_time = %f", nglPerfInfo().m_render_time);

        double v9 = nglFlipCycle() - nglLastFlipCycle();
        if ( (nglFlipCycle() - nglLastFlipCycle()) < 0 ) {
            v9 += flt_86F860();
        }

        printf("nglFlipCycle = %u, nglLastFlipCycle = %u\n", nglFlipCycle(), nglLastFlipCycle());

        nglPerfInfo().field_6C = v9 / PCFreq();
        nglPerfInfo().field_5C += nglPerfInfo().field_6C;
        nglPerfInfo().m_fps = 1000.f / nglPerfInfo().field_6C;

        printf("v9 = %f, PCFreq = %f\n", v9, PCFreq());
        printf("nglPerfInfo.m_fps == %f\n", nglPerfInfo().m_fps);

        nglPerfInfo().field_60 = nglPerfInfo().field_5C * 0.001f;
        if ( nglDebug().ScreenShot ) {
            nglScreenShot(nullptr);
            nglDebug().ScreenShot = 0;
        }

        nglSyncPerfInfo() = nglPerfInfo();

        nglPerfInfo().field_80 = 0;
        nglPerfInfo().field_18 = 0.0;
        nglPerfInfo().field_1C = 0.0;
        nglPerfInfo().field_7C = 0;
        nglPerfInfo().field_78 = 0;
        nglPerfInfo().field_48 = 0;
        nglPerfInfo().field_4C = 0;
        nglPerfInfo().field_50 = 0;
        nglPerfInfo().field_54 = 0;

#if 0
        if ( dword_971F2C() ) {
            dword_971F2C()(dword_971F30());
        }
#endif

        nglCurScene() = nullptr;
    } else {
        CDECL_CALL(0x0076EA10, Flip);
    }
}

void ngl_patch()
{
    {
        REDIRECT(0x005AD264, nglSetFrameLock);
        REDIRECT(0x0076E966, nglSetFrameLock);
    }

    REDIRECT(0x005AD218, nglInit);

    SET_JUMP(0x0076E050, nglListInit);

    SET_JUMP(0x0076EA10, nglListSend);

    REDIRECT(0x0076EA59, nglRenderPerfInfo);
}
