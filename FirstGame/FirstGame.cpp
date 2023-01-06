// FirstGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "imgui_demo_start.h"
#include "Gui_Start.h"
#include <iostream>
#include "MainGame.h"

using namespace std;

bool showDemo = false;

int main()
{
    if (showDemo) {
        return quick_imgui_sample();
    }

    //initial window
    MainGame* game = new MainGame();
    main_window_start(*game);

    //main_window_start();
    //Main loop, temp. Move to MainGame.cpp maybe?

    while (true) {
        game->Update();
    }

    int x = 5;

    return 0;
}