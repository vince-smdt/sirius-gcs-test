#ifndef CONTROLSWINDOW_H
#define CONTROLSWINDOW_H

#include "RichMapPlot.h"
#include "RichMarkStorage.h"

class ControlsWindow {
public:
    ControlsWindow();
    void draw();

private:
    enum MapView { MAP_VIEW = 0, SATELLITE_VIEW = 1 };

    std::shared_ptr<RichMapPlot> _mapPlot;
    std::shared_ptr<MarkStorage> _storage;

    int _mapView{0};
    int _prevMapView{0};
};

#endif // CONTROLSWINDOW_H
