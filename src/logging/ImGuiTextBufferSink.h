#ifndef IMGUITEXTBUFFERSINK_H
#define IMGUITEXTBUFFERSINK_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/base_sink.h>

#include "ImGuiCircularLogTextBuffer.h"

class ImGuiTextBufferSink : public spdlog::sinks::base_sink<std::mutex> {
public:
    explicit ImGuiTextBufferSink(ImGuiCircularLogTextBuffer *buffer) : _buffer(buffer) {};

protected:
    void sink_it_(const spdlog::details::log_msg &msg) override;
    void flush_() override;

private:
    ImGuiCircularLogTextBuffer *_buffer;
};

#endif //IMGUITEXTBUFFERSINK_H
