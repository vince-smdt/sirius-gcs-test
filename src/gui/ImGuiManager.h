#ifndef IMGUIMANAGER_H
#define IMGUIMANAGER_H
#include "ControlsWindow.h"
#include "LoggingWindow.h"

// clang-format off
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <memory>
// clang-format on

namespace ImGuiManager {
void init();
void render();
void shutdown();

extern std::unique_ptr<ControlsWindow> controlsWindow;
extern std::unique_ptr<LoggingWindow> loggingWindow;
} // namespace ImGuiManager

#endif // IMGUIMANAGER_H
