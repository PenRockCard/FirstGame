#include "MainGame.h";


MainGame::MainGame() {
	planets.push_back(new Planet("Neptune"));
	planets.push_back(new Planet("Mars"));
}

void MainGame::Update() {

	//Timer functionality
	auto updateStart = chrono::high_resolution_clock::now();

	for (Planet * planet : planets) {
		planet->mineResources();
	}

	auto updateFinish = chrono::high_resolution_clock::now();

	auto valueStart = updateStart.time_since_epoch();
	auto valueFinish = updateFinish.time_since_epoch();

	auto timeDifference = valueFinish - valueStart;

	auto temp=timeDifference.count();

	//chrono::high_resolution_clock::period
	chrono::nanoseconds timePeriod = 500000000ns; //0.5 sec
	this_thread::sleep_for(timePeriod - timeDifference);

}