cmake_minimum_required(VERSION 3.16)
project(DD_Logbook LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(DD_Logbook main.cpp)

if (MINGW)
    set_target_properties(DD_Logbook PROPERTIES
        LINK_FLAGS "-static -static-libgcc -static-libstdc++"
    )
endif()
