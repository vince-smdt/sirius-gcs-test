cmake_minimum_required(VERSION 3.29)
project(sirius_gcs)

set(CMAKE_CXX_STANDARD 20)

include_directories(lib/imgui)

file(GLOB IMGUI_SRC
    "lib/imgui/*.cpp"
    "lib/imgui/*.h"
)

add_executable(sirius_gcs src/main.cpp ${IMGUI_SRC})
