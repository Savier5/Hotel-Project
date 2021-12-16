#ifndef ROOM_H
#define ROOM_H
#include <iostream>
#include <string>
#include<windows.h>

using namespace std;

class room {

private:

public:

	string name;
	int roomNumber;
	int roomPrice;
	string roomType;
	int dateStartedDay;
	int dateStartedMonth;
	int dateStartedYear;
	int timeStartedHour;
	int timeStartedMinutes;
};

#endif