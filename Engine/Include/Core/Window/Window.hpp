#pragma once

#include <functional>

struct GLFWwindow;

namespace tinyE
{
    
    class Window
    {
    public:
        void InitWindow();

        void UpdateWindowEvent(const std::function<void()>& UpdateCallback);
        
        void DestroyWindow();
        
        GLFWwindow* GetCurrentWindowInstance() const { return GLFWWindowInstance; }
        
    private:
        GLFWwindow* GLFWWindowInstance = nullptr;
    };

}
