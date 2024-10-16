#include "Logging.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include "ImGuiTextBufferSink.h"

void gcsLoggerInit(ImGuiTextBuffer *buf) {
    const auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    const auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs/gcs-log.txt");
    const auto imgui_sink = std::make_shared<ImGuiTextBufferSink>(buf);

    std::vector<spdlog::sink_ptr> sinks{ console_sink, file_sink, imgui_sink };

    const auto logger = std::make_shared<spdlog::logger>("multi_sink", sinks.begin(), sinks.end());
    spdlog::set_default_logger(logger);
    spdlog::set_level(spdlog::level::trace);
    spdlog::flush_every(std::chrono::seconds(5));
}
