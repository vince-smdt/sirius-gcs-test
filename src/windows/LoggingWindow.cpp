#include "LoggingWindow.h"

#include "Logging.h"

LoggingWindow::LoggingWindow(ImGuiTextBuffer *buf) : _buf(buf) {}

void LoggingWindow::draw() {
    ImGui::Begin("Logs");
    if (ImGui::Button("Add test log")) {
        GCS_LOG_INFO("This is a test");
    }
    ImGui::Separator();
    ImGui::BeginChild("scrolling", ImVec2(0, 0), ImGuiChildFlags_None, ImGuiWindowFlags_HorizontalScrollbar);
    ImGui::TextUnformatted(_buf->begin(), _buf->end());
    ImGui::EndChild();
    ImGui::LogText("Bonjour");
    ImGui::End();
}
