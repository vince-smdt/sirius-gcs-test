#include "LoggingWindow.h"

#include "Logging.h"

LoggingWindow::LoggingWindow(ImGuiTextBuffer *buf) : _buf(buf), _autoScroll(true) {}

void LoggingWindow::draw() {
    ImGui::Begin("Logs");
    ImGui::Checkbox("Auto Scroll", &_autoScroll);
    ImGui::SameLine();
    if (ImGui::Button("Add test log")) {
        GCS_LOG_INFO("This is a test");
    }
    ImGui::Separator();
    ImGui::BeginChild("scrolling", ImVec2(0, 0), ImGuiChildFlags_None, ImGuiWindowFlags_HorizontalScrollbar);
    ImGui::TextUnformatted(_buf->begin(), _buf->end());
    if (_autoScroll && ImGui::GetScrollY() >= ImGui::GetScrollMaxY()) {
        ImGui::SetScrollHereY(1.0f);
    }
    ImGui::EndChild();
    ImGui::LogText("Bonjour");
    ImGui::End();
}
