/*
A class designed to measure, set and get the time it takes to update the game.
*/

#include "Update_Time.h"

/*
The default constructor. Sets the minimum update time to 0.5 seconds.
TODO: Add another constructor to set it based on the time input?
*/
Update_Time::Update_Time() {
	timePeriod = nanoseconds(500000000);
};

/*
Sets the start time for the beginning of the update.
*/
void Update_Time::UpdateStart() {
	updateStartTime = high_resolution_clock::now();
}

/*
Finishes the update. Gets the current time, and compares it to the beginning time. This variable can be gotten via a getter below.
Then it'll sleep the thread long enough to meet the minimum update time.
TODO: Figure out what to do when the update time is shorter than the time it took to update the game?
*/
void Update_Time::UpdateFinish() {
	updateFinishTime = high_resolution_clock::now();

	auto valueStart = updateStartTime.time_since_epoch();
	auto valueFinish = updateFinishTime.time_since_epoch();
	updateTotalTime = valueFinish - valueStart;

	this_thread::sleep_for(timePeriod - updateTotalTime);
}

/*
Sets the minimum update time.
*/
bool Update_Time::SetUpdateTime(long long newUpdateTime) {
	timePeriod = nanoseconds(newUpdateTime);
	return true;
}

/*
Returns the time it actually took to update the game.
*/
long long Update_Time::GetUpdateTime() {
	return updateTotalTime.count();
}
