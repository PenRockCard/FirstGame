// FirstGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "imgui_demo_start.h"
#include "Gui_Start.h"
#include <iostream>
#include "MainGame.h"

using namespace std;

bool showDemo = true;

int main()
{
    if (showDemo) {
        return quick_imgui_sample();
    }

    //main_window_start();
    //Main loop, temp. Move to MainGame.cpp maybe?
    MainGame *game = new MainGame();
    game->Update();

    int x = 5;

    return 0;
}