#include "MainGame.h";


MainGame::MainGame() {
	planets.push_back(new Planet("Neptune"));
	planets.push_back(new Planet("Mars"));
	//update_Time=new Update_Time();
}

void MainGame::Update() {

	update_Time.UpdateStart();

	for (Planet* planet : planets) {
		planet->mineResources();
	}

	update_Time.UpdateFinish();

}