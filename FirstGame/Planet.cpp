#include "Planet.h"

//Constructor.
//To be made more programatic later.

Planet::Planet(string nameConstructor) {
	/*Resource tempResource = ;*/
	resources.push_back(new Resource(1, 100, "Bronze"));
	resources.push_back(new Resource(2, 76, "Iron"));
	resources.push_back(new Resource(3, 50, "Steel"));
	resources.push_back(new Resource(4, 40, "Mithril"));
	resources.push_back(new Resource(5, 30, "Addy"));
	resources.push_back(new Resource(6, 15, "Rune"));
	*name = nameConstructor;
}

void Planet::mineResources()
{
	//current resource mining is new amount = current amount - 2/hardness
	for (Resource* planetResource : resources)
	{
		planetResource->mineResource();
	}
}

vector<Resource *> Planet::GetCurrentResources()
{
	return vector<Resource *>();
}


