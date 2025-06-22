#include "Core/Application.hpp"

#include "Core/Window/Window.hpp"

namespace tinyE
{
    
    Application::Application()
    {
        WindowInstance = std::make_unique<Window>();
    }

    Application::~Application()
    {
        
    }

    void Application::Run()
    {
        WindowInstance->InitWindow();
        WindowInstance->UpdateWindowEvent([]()
        {
            
        });
    }
    
}