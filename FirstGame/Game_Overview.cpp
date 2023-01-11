#pragma once
#include <iostream>
#include <compare>
#include <vector>

#include "imgui\imgui.h"
#include "imgui\imgui_impl_win32.h"
#include "imgui\imgui_impl_dx12.h"
#include <d3d12.h>
#include <dxgi1_4.h>
#include <tchar.h>

#include "GuiNamespace.h"
#include "Planet_Overview.h"
#include "MainGame.h"



using namespace std;
using namespace ImGui;
using namespace GUI;


//Game_Overview::Game_Overview(MainGame& gameConstruct) {
//
//	show_planet_window = false;
//	game = gameConstruct;
//
//}

void GUI::CreateOverviewWindow() {


	Begin("Game Overview");

	//Number of planets
	string tempString2 = "The number of planets is: " + to_string(game.planets.size());
	Text(tempString2.c_str());

	for (int i = 0; i < game.planets.size(); i++) {
		string tempPlanetString = "Planet: " + *game.planets.at(i)->name;
		Text(tempPlanetString.c_str());
	}

	//Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
	Checkbox("Planet Info Window", &show_planet_window);

	End();

	if (show_planet_window) {
		Planet_Overview planetOverview = Planet_Overview(game);
		planetOverview.Planet_Window_Main();
	}
}
