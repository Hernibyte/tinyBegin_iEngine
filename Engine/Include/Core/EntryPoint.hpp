#pragma once

extern tinyE::Application* CreateApp();

int main(int argc, char** argv)
{
    auto App = CreateApp();
    App->Run();
    delete App;

    return 0;
}