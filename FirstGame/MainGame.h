#pragma once
#include <vector>
#include "Planet.h"
#include <chrono>
#include <thread>

using namespace std;
class MainGame
{
	
public:
	vector<Planet *> planets;
	MainGame();
	void Update();

};

