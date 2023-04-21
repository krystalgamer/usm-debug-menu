cmake_minimum_required(VERSION 3.18)

include(cmake/i686-pc-mingw32.cmake)

set(CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-fomit-frame-pointer -m32 -fno-asynchronous-unwind-tables -masm=intel -static")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}
    "-fomit-frame-pointer -m32 -fno-asynchronous-unwind-tables -masm=intel -static -std=c++20")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)


list(APPEND flags
    #"-Werror"
    #"-pedantic-errors"
    "-Wall"
    "-Wextra"
    "-Wpedantic"
    "-Wcast-align"
    "-Wcast-qual"
    #"-Wzero-as-null-pointer-constant"
    #"-Wconversion"
    #"-Wctor-dtor-privacy"
    "-Wduplicated-branches"
    "-Wduplicated-cond"
    #"-Wextra-semi"
    "-Wfloat-equal"
    "-Wlogical-op"
    #"-Wnon-virtual-dtor"
    #"-Wold-style-cast"
    #"-Woverloaded-virtual"
    "-Wredundant-decls"
    #"-Wsign-conversion"
    #"-Wsign-promo"
    "-Wshift-negative-value"
    #"-Wno-invalid-offsetof"
    "-Wno-deprecated")

project(usm_debug_menu LANGUAGES CXX)

if(MINGW)
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
    set(CMAKE_STATIC_LIBRARY_PREFIX "")
    set(CMAKE_SHARED_MODULE_PREFIX "")
endif()

option(USE_GLM "description" ON)

if(USE_GLM)
    add_definitions(-DUSE_GLM)
endif()


add_library(binkw32 SHARED main.cpp forwards.h)
    
target_compile_options(binkw32
  PRIVATE
    ${flags}
  )


target_link_directories(binkw32 PRIVATE ${CMAKE_FIND_ROOT_PATH}/include)
target_link_directories(binkw32 PRIVATE ${CMAKE_FIND_ROOT_PATH}/lib)
target_link_libraries(binkw32 PRIVATE winmm psapi dinput8 dxguid)


set_target_properties(binkw32
    PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../
)



