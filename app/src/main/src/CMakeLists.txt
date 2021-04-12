cmake_minimum_required(VERSION 3.4.1)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/../../SDL2/include
)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../../SDL2/ ${CMAKE_CURRENT_SOURCE_DIR}/../../SDL2)

add_library(
             main-lib

             SHARED

             # Provides a relative path to your source file(s).
             SDL_android_main.c
             main.cpp )


find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )



target_link_libraries( # Specifies the target library.
                        main-lib
                        SDL2
                        ${log-lib} )