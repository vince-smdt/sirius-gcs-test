cmake_minimum_required(VERSION 3.29)
project(sirius_gcs)

set(CMAKE_CXX_STANDARD 20)

include_directories(
        lib/imgui
        lib/imgui/backends
        src/logging
        src/gui
)

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
find_package(spdlog)

add_executable(sirius_gcs ${IMGUI_SRC}
        src/main.cpp
        src/logging/ImGuiTextBufferSink.cpp
        src/logging/ImGuiTextBufferSink.h
        src/logging/Logging.cpp
        src/logging/Logging.h
        src/gui/ControlsWindow.cpp
        src/gui/ControlsWindow.h
        src/gui/LoggingWindow.cpp
        src/gui/LoggingWindow.h
        src/gui/ImGuiManager.cpp
        src/gui/ImGuiManager.h
        src/logging/ImGuiCircularLogTextBuffer.cpp
        src/logging/ImGuiCircularLogTextBuffer.h
)
target_link_libraries(sirius_gcs
        glfw
        glad::glad
        spdlog::spdlog
)
