#include "tinyBegin_iEngine.hpp"

#include <iostream>

class MyGame : public tinyE::Application
{
public:
    MyGame()
    {
        std::cout << "Hello App!" << std::endl;
    }
    ~MyGame() override = default;
};

tinyE::Application* CreateApp()
{
    return new MyGame();
}
