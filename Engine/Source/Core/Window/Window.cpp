#include "Core/Window/Window.hpp"

#include <cstdio>
#include <glad/glad.h>
// GLFW (include after glad)
#include <chrono>
#include <GLFW/glfw3.h>
#include <iostream>

namespace tinyE
{
    void Window::InitWindow()
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        
        GLFWWindowInstance = glfwCreateWindow(1280, 720, "LearnOpenGL", nullptr, nullptr);
        glfwMakeContextCurrent(GLFWWindowInstance);
        if (GLFWWindowInstance == nullptr)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            DestroyWindow();
            return;
        }
        
        int version = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (version == 0) {
            printf("Failed to initialize OpenGL context\n");
            return;
        }

        printf("Glad version %i\n", version);

        glfwSwapInterval(0);
        glViewport(0, 0, 1280, 720);
    }

    void Window::UpdateWindowEvent(const std::function<void()>& UpdateCallback)
    {
        while (!glfwWindowShouldClose(GLFWWindowInstance))
        {
            auto ChronoStart = std::chrono::high_resolution_clock::now();
            
            glfwPollEvents();

            UpdateCallback();

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            glfwSwapBuffers(GLFWWindowInstance);
            auto ChronoEnd = std::chrono::high_resolution_clock::now();

            std::chrono::duration<double> diff = ChronoEnd - ChronoStart;
            glfwSetWindowTitle(GLFWWindowInstance, std::to_string(1.0 / diff.count()).c_str());
        }

        DestroyWindow();
    }

    void Window::DestroyWindow()
    {
        glfwTerminate();
    }
}
