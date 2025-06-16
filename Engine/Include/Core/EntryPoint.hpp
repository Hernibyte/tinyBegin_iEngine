#pragma once

extern Application* CreateApp();

inline int main(int argc, char** argv)
{
    auto App = CreateApp();
    App->Run();
    delete App;

    return 0;
}