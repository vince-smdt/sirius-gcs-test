cmake_minimum_required(VERSION 3.29)
project(sirius_gcs)

set(CMAKE_CXX_STANDARD 20)

include_directories(lib/imgui)
include_directories(lib/imgui/backends)
file(GLOB IMGUI_SRC
        "lib/imgui/*.cpp"
        "lib/imgui/*.h"
        "lib/imgui/backends/imgui_impl_opengl3.h"
        "lib/imgui/backends/imgui_impl_opengl3.cpp"
        "lib/imgui/backends/imgui_impl_glfw.h"
        "lib/imgui/backends/imgui_impl_glfw.cpp"
)

find_package(glfw3)
find_package(glad)

add_executable(sirius_gcs src/main.cpp ${IMGUI_SRC})
target_link_libraries(sirius_gcs glfw glad::glad)
