#include "ImGuiManager.h"

#include "Logging.h"

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <implot.h>

namespace ImGuiManager {
std::unique_ptr<ControlsWindow> controlsWindow;
std::unique_ptr<LoggingWindow> loggingWindow;
} // namespace ImGuiManager

void ImGuiManager::init(GLFWwindow* window) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    const ImGuiIO& io = ImGui::GetIO();
    (void) io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    ImPlot::CreateContext();

    controlsWindow = std::make_unique<ControlsWindow>();
    loggingWindow = std::make_unique<LoggingWindow>();

    Logging::linkLoggingWindow(loggingWindow.get());
}

void ImGuiManager::render() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    controlsWindow->draw();
    loggingWindow->draw();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void ImGuiManager::shutdown() {
    controlsWindow = nullptr;
    loggingWindow = nullptr;

    Logging::removeLoggingWindow();

    ImPlot::DestroyContext();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}