#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
#include <string>
#include<windows.h>

using namespace std;

const int totalRooms = 122;
const int totalCourtyardRooms = 70, priceOfCourtyardRooms = 125;
const int totalScenicRooms = 35, priceOfScenicRooms = 145;
const int totalDeluxeSuites = 15, priceOfDeluxeSuites = 350;
const int totalPenthouses = 2, priceOfPenthouses = 1135;

class hotel {

private:

public:

	void roomSelect(string tempRoomSelect);
	void reservationSystem();
	void getTotal();
};

#endif