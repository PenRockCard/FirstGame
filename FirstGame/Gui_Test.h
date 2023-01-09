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
#include "MainGame.h"

class Gui_Test
{
	MainGame game;
public:
	bool show_planet_window = false;
	bool show_UPS_FPS = true;
	Gui_Test(MainGame& gameConstruct);
	void CreateStuff();
	void PopStyleCompact();
	void UPSWindow();
};

