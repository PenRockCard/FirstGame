#pragma once

#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

class Update_Time
{
	//The current minimum update time.
	chrono::nanoseconds timePeriod; 

	//The start time of the current update.
	steady_clock::time_point updateStartTime;

	//The finish time of the update.
	steady_clock::time_point updateFinishTime;

	//How long it took to update the game
	nanoseconds updateTotalTime;

public:
	Update_Time();
	void UpdateStart();
	void UpdateFinish();
	bool SetUpdateTime(long long newUpdateTime);
	long long GetUpdateTime();

};

