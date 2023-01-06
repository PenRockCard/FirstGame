#pragma once

#include <iostream>
#include <vector>
#include "Resource.h"
using namespace std;

class Planet
{

public:
	vector<Resource *> resources;
	int *temperature;
	void mineResources();
	vector<Resource*> GetCurrentResources();
	Planet();
};

