#include "MainGame.h";


MainGame::MainGame() {
	planets.push_back(new Planet("Neptune"));
	planets.push_back(new Planet("Mars"));
}

void MainGame::Update() {
	for (Planet * planet : planets) {
		planet->mineResources();
	}
}