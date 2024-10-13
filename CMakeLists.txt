cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

include_directories(lib/imgui)

file(GLOB IMGUI_SRC
    "lib/imgui/*.cpp"
    "lib/imgui/*.h"
)

add_executable(untitled main.cpp ${IMGUI_SRC})
