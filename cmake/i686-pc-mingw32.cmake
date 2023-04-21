SET(CMAKE_SYSTEM_NAME      Windows)
SET(CMAKE_SYSTEM_PROCESSOR i686)

SET(TOOLCHAIN_PREFIX i686-w64-mingw32)

# which compilers to use for C and C++ and ASM-ATT
SET(CMAKE_C_COMPILER       /usr/bin/${TOOLCHAIN_PREFIX}-gcc )
SET(CMAKE_CXX_COMPILER     /usr/bin/${TOOLCHAIN_PREFIX}-g++ )
SET(CMAKE_ASM-ATT_COMPILER /usr/bin/${TOOLCHAIN_PREFIX}-as  )

# here is the target environment located
SET(CMAKE_FIND_ROOT_PATH  /usr/${TOOLCHAIN_PREFIX}
                          )

# adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
