#ifndef LOGGINGWINDOW_H
#define LOGGINGWINDOW_H

#include "ImGuiCircularLogTextBuffer.h"

class LoggingWindow {
public:
    explicit LoggingWindow(ImGuiCircularLogTextBuffer *buf);
    void draw();
private:
    ImGuiCircularLogTextBuffer *_buf;
    bool _autoScroll;
};

#endif //LOGGINGWINDOW_H
