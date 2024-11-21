#include "ImGuiManager.h"

#include "Logging.h"

#include <imgui.h>
#include <implot.h>

namespace ImGuiManager {
std::unique_ptr<ControlsWindow> controlsWindow;
std::unique_ptr<LoggingWindow> loggingWindow;
} // namespace ImGuiManager

void ImGuiManager::init(GLFWwindow* window) {
    ImPlot::CreateContext();

    controlsWindow = std::make_unique<ControlsWindow>();
    loggingWindow = std::make_unique<LoggingWindow>();

    Logging::linkLoggingWindow(loggingWindow.get());
}

void ImGuiManager::render() {
    controlsWindow->draw();
    loggingWindow->draw();
}

void ImGuiManager::shutdown() {
    controlsWindow = nullptr;
    loggingWindow = nullptr;

    Logging::removeLoggingWindow();

    ImPlot::DestroyContext();
}