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

public:
	bool show_planet_window;
	Gui_Test();
	void CreateStuff(MainGame& game);
	void PopStyleCompact();
};

