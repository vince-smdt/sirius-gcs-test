#ifndef CONTROLSWINDOW_H
#define CONTROLSWINDOW_H

#include "RichMapPlot.h"
#include "RichMarkStorage.h"

class ControlsWindow {
public:
    ControlsWindow();
    void draw();

private:
    std::shared_ptr<RichMapPlot> _mapPlot;
    std::shared_ptr<MarkStorage> _storage;
};

#endif // CONTROLSWINDOW_H
