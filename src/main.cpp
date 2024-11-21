#include "ImGuiManager.h"
#include "Logging.h"

#include <GLFW/glfw3.h>
#include <WinSock2.h>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")

int main() {
    Logging::initSpdLog();

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        GCS_LOG_ERROR("WSAStartup failed");
        return -1;
    }

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(1920, 1080, "Sirius GCS", nullptr, nullptr);
    if (window == nullptr) {
        GCS_LOG_ERROR("Failed to create GLFW window");
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();
    glViewport(0, 0, 800, 800);

    ImGuiManager::init(window);

    GCS_LOG_TRACE("Starting program");

    while (!glfwWindowShouldClose(window)) {
        if (!glfwGetWindowAttrib(window, GLFW_ICONIFIED)) {
            glClearColor(0, 0, 0.1F, 1.0F);
            glClear(GL_COLOR_BUFFER_BIT);

            ImGuiManager::render();

            glfwSwapBuffers(window);
        }
        glfwPollEvents();
    }

    ImGuiManager::shutdown();

    glfwDestroyWindow(window);
    glfwTerminate();

    WSACleanup();

    GCS_LOG_TRACE("Terminating program");
}