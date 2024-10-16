#ifndef LOGGING_H
#define LOGGING_H

#include "ImGuiTextBufferSink.h"

void gcsLoggerInit(ImGuiTextBuffer *buf);

#define GCS_LOG_DEBUG(msg) spdlog::debug(msg)
#define GCS_LOG_ERROR(msg) spdlog::error(msg)
#define GCS_LOG_INFO(msg) spdlog::info(msg)
#define GCS_LOG_TRACE(msg) spdlog::trace(msg)
#define GCS_LOG_WARN(msg) spdlog::warn(msg)

#endif //LOGGING_H
