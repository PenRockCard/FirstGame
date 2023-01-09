#pragma once
#include <vector>
#include "Planet.h"
#include <chrono>
#include <thread>
#include "Update_Time.h"

using namespace std;
class MainGame
{
	
public:
	vector<Planet *> planets;
	MainGame();
	void Update();
	Update_Time *update_Time = new Update_Time();

};

