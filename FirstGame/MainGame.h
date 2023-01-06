#pragma once
#include <vector>
#include "Planet.h"

using namespace std;
class MainGame
{
public:
	vector<Planet *> planets;
	MainGame();
	void Update();
};

