#pragma once
#include <memory>

namespace tinyE
{

    class Window;
    
    class Application
    {
    public:

        Application();
        virtual ~Application();

        void Run();

    private:
        std::unique_ptr<Window> WindowInstance;
    };

}
