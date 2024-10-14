cmake_minimum_required(VERSION 3.29)
project(sirius_gcs)

set(CMAKE_CXX_STANDARD 20)

include_directories(lib/imgui)

file(GLOB IMGUI_SRC
    "lib/imgui/*.cpp"
    "lib/imgui/*.h"
)

find_package(glfw3)
find_package(glad)

add_executable(sirius_gcs src/main.cpp ${IMGUI_SRC})
target_link_libraries(sirius_gcs glfw glad::glad)
