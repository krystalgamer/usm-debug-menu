#pragma once

#include "variable.h"

#include <d3d9.h>

#include <windows.h>

inline Var<bool> EnableShader {0x00972AB0};

inline Var<IDirect3DDevice9 *> g_Direct3DDevice {0x00971F94};

inline Var<float> flt_86F860 {0x0086F860};

inline Var<int> nglListWorkPos {0x00971F0C};

inline Var<bool> g_distance_clipping_enabled {0x0095C718};
