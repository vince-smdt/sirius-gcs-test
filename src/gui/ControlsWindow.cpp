#include "ControlsWindow.h"

#include "Logging.h"
#include "TileLoaderImpl.h"

#include <imgui.h>
#include <implot.h>

ControlsWindow::ControlsWindow() {
    _mapPlot = std::make_shared<RichMapPlot>();
    _storage = std::make_shared<MarkStorage>();

    _storage->addMark({46.14665264871996, -70.66861153239353}, "Tapis Venture");
    _mapPlot->addItem(std::reinterpret_pointer_cast<IRichItem>(_storage->markItems().back().ptr));
}

void ControlsWindow::draw() {
    float x[] = {0.0f, 1.0f, 2.0f, 3.0f, 4.0f};
    float y[] = {10.0f, 20.0f, 15.0f, 25.0f, 30.0f};

    ImGui::Begin("Controls");
    ImGui::Button("Launch la fusée");

    ImGui::Dummy(ImVec2{0.0f, 20.0f});

    if (ImPlot::BeginPlot("Line Plot")) {
        ImPlot::PlotLine("Static Data", x, y, IM_ARRAYSIZE(x));
        ImPlot::EndPlot();
    }

    ImGui::Dummy(ImVec2{0.0f, 20.0f});

    ImGui::Text("Type de vue: ");
    ImGui::SameLine();
    ImGui::RadioButton("Cartographique", &_mapView, MAP_VIEW);
    ImGui::SameLine();
    ImGui::RadioButton("Satellite", &_mapView, SATELLITE_VIEW);

    if (_mapView != _prevMapView) {
        if (_mapView == MAP_VIEW) {
            _mapPlot->setTileLoader(std::make_shared<TileLoaderOsmMap>());
        } else if (_mapView == SATELLITE_VIEW) {
            _mapPlot->setTileLoader(std::make_shared<TileLoaderArcMap>());
        }
        _prevMapView = _mapView;
    }

    GCS_LOG_TRACE(_mapView);

    _mapPlot->paint();

    ImGui::End();
}
