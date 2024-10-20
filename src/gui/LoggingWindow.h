#ifndef LOGGINGWINDOW_H
#define LOGGINGWINDOW_H

#include "imgui.h"

class LoggingWindow {
public:
    LoggingWindow(ImGuiTextBuffer *buf);
    void draw();
private:
    ImGuiTextBuffer *_buf;
};

#endif //LOGGINGWINDOW_H
