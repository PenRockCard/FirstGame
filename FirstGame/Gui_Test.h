#pragma once
#include <iostream>
#include <compare>
#include <vector>

#include "imgui.h"
#include "imgui_impl_win32.h"
#include "imgui_impl_dx12.h"
#include <d3d12.h>
#include <dxgi1_4.h>
#include <tchar.h>
#include "MainGame.h"

class Gui_Test
{

public:
	bool show_another_window;
	Gui_Test();
	void CreateStuff(MainGame& game);
};

