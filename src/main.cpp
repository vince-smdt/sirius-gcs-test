/// \file

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

/// The program's entry point.
int main() {
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "sirius-gcs", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "noob";
        glfwTerminate();
        return 1;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, 800, 800);

    float bruh = 0.07;
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();

        bruh += 0.01;
        if (bruh > 0.99) {
            bruh = 0;
        }
        glClearColor(bruh, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
