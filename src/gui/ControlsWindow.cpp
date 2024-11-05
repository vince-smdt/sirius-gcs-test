#include "ControlsWindow.h"

#include <imgui.h>
#include <implot.h>

void ControlsWindow::draw() {
    float x[] = {0.0f, 1.0f, 2.0f, 3.0f, 4.0f};
    float y[] = {10.0f, 20.0f, 15.0f, 25.0f, 30.0f};

    ImGui::Begin("Controls");
    ImGui::Button("Launch la fusée");
    if (ImPlot::BeginPlot("Line Plot")) {
        ImPlot::PlotLine("Static Data", x, y, IM_ARRAYSIZE(x));
        ImPlot::EndPlot();
    }
    ImGui::End();
}
