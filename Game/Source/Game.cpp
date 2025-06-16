#include "tinyBegin_iEngine.hpp"

#include <iostream>

class MyGame : public Application
{
public:
    MyGame()
    {
        std::cout << "Hello App!" << std::endl;
    }
    ~MyGame() override = default;
};

Application* CreateApp()
{
    return new MyGame();
}