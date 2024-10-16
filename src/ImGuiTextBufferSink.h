#ifndef IMGUITEXTBUFFERSINK_H
#define IMGUITEXTBUFFERSINK_H

#include <imgui.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/base_sink.h>

class ImGuiTextBufferSink : public spdlog::sinks::base_sink<std::mutex> {
public:
    explicit ImGuiTextBufferSink(ImGuiTextBuffer *buffer) : buffer_(buffer) {};

protected:
    void sink_it_(const spdlog::details::log_msg &msg) override;
    void flush_() override;

private:
    ImGuiTextBuffer *buffer_;
};

#endif //IMGUITEXTBUFFERSINK_H
