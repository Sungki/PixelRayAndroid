cmake_minimum_required(VERSION 3.4.1)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/../libs/SDL2/include

        # SDL_internal.h is located in src required by SDL_android_main.c bridge
        ${CMAKE_CURRENT_SOURCE_DIR}/../libs/SDL2/src
)

set(PIXELRAY_SRC_DIR   "${CMAKE_CURRENT_SOURCE_DIR}/src/main/cpp")
set(PIXELRAY_CMAKE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src/main/cmake")

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../libs/SDL2/ ${CMAKE_CURRENT_SOURCE_DIR}/../libs/SDL2)

include(${PIXELRAY_CMAKE_DIR}/pixelray.cmake)
#include(${PIXELRAY_CMAKE_DIR}/app_src.cmake)

add_library(
			 pixelray

             SHARED
			 
			 # Provides a relative path to your source file(s).
			 ${pixelray}
			 ${app_src}
			 )

find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

target_link_libraries( # Specifies the target library.
						pixelray
                        SDL2

                        #admob
                        #app

                        ${log-lib} )