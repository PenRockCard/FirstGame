#include "MainGame.h";


MainGame::MainGame() {
	planets.push_back(new Planet());
}

void MainGame::Update() {
	for (Planet * planet : planets) {
		planet->mineResources();
	}
}