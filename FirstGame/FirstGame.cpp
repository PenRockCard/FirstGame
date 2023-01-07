// FirstGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "imgui_demo_start.h"
#include "Gui_Start.h"
#include <iostream>
#include "MainGame.h"

using namespace std;

bool showDemo = false;
void GUI_Start();
void Main_Update();
MainGame* game = new MainGame();

int main()
{
    if (showDemo) {
        return quick_imgui_sample();
    }

    //initial window
   
    //main_window_start(*game);

    //main_window_start();
    //Main loop, temp. Move to MainGame.cpp maybe?
    thread threadUpdate(Main_Update);
    thread threadGUI(GUI_Start);


    threadUpdate.join();
    threadGUI.join();


    int x = 5;

    return 0;
}

void GUI_Start() {
    cout << "here1\n";
    main_window_start(*game);
}

void Main_Update() {
    cout << "here2\n";
    while (true) {
        game->Update();
    }
}