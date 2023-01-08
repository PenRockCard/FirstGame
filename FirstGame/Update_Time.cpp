#include "Update_Time.h"

Update_Time::Update_Time() {
	timePeriod = nanoseconds(500000000);
};

void Update_Time::UpdateStart() {
	updateStartTime = high_resolution_clock::now();
}

void Update_Time::UpdateFinish() {
	updateFinishTime = high_resolution_clock::now();

	auto valueStart = updateStartTime.time_since_epoch();
	auto valueFinish = updateFinishTime.time_since_epoch();
	updateTotalTime = valueFinish - valueStart;

	this_thread::sleep_for(timePeriod - updateTotalTime);
}

bool Update_Time::SetUpdateTime(long long newUpdateTime) {
	timePeriod = nanoseconds(newUpdateTime);
	return true;
}

long long Update_Time::GetUpdateTime() {
	return updateTotalTime.count();
}
