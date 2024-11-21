#include "ImGuiManager.h"
#include "Logging.h"
#include "hello_imgui/hello_imgui.h"

#include <WinSock2.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")

int main(int, char*[]) {
    Logging::initSpdLog();

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        GCS_LOG_ERROR("WSAStartup failed");
        return -1;
    }

    ImGuiManager::init(nullptr);

    HelloImGui::Run([] { ImGuiManager::render(); }, "Sirius GCS", true);

    ImGuiManager::shutdown();

    WSACleanup();
}