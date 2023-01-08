#pragma once

#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

class Update_Time
{
	chrono::nanoseconds timePeriod; // 0.5 sec
	steady_clock::time_point updateStartTime;
	steady_clock::time_point updateFinishTime;
	nanoseconds updateTotalTime;

public:
	Update_Time();
	void UpdateStart();
	void UpdateFinish();
	bool SetUpdateTime(long long newUpdateTime);
	long long GetUpdateTime();

};

