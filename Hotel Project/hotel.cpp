#include "hotel.h"
#include "room.h"
#include <iostream>
#include <string>
#include<windows.h>
#include <ctime>
#include <fstream>


using namespace std;

room courtyardRoomsArray[totalCourtyardRooms];
room scenicRoomsArray[totalScenicRooms];
room deluxeSuitesArray[totalDeluxeSuites];
room penthousesArray[totalPenthouses];

int dateStartedDay;
int dateStartedMonth;
int dateStartedYear;
int timeStartedHour;
int timeStartedMinutes;

int tempTotalCourtyardRooms = totalCourtyardRooms;
int tempTotalScenicRooms = totalScenicRooms;
int tempTotalDeluxeSuites = totalDeluxeSuites;
int tempTotalPenthouses = totalPenthouses;
string tempOptionSelect;
string tempRoomSelect;

int totalRevenue;
int timeTemp;
string tempName;


void hotel::reservationSystem()
{
	
	courtyardRoomsArray->roomNumber = 0;
	scenicRoomsArray->roomNumber = 0;
	deluxeSuitesArray->roomNumber = 0;
	penthousesArray->roomNumber = 0;

	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);

	dateStartedDay = newtime.tm_mday;
	dateStartedMonth = 1 + newtime.tm_mon;
	dateStartedYear = 1900 + newtime.tm_year;
	timeStartedHour = newtime.tm_hour;
	timeStartedMinutes = newtime.tm_min;

	string dateStartedMonth1 = to_string(dateStartedMonth);

	string dateStartedDay1 = to_string(dateStartedDay);

	string dateStartedYear1 = to_string(dateStartedYear);

	string text = dateStartedMonth1 + "-" + dateStartedDay1 + "-" + dateStartedYear1 + ".txt";

	ofstream file(text, ios::out);

	string searchText;

	do
	{
		if (system("CLS")) {
			system("clear");
		}

		if (tempTotalCourtyardRooms <= 0) {

			tempTotalCourtyardRooms = 0;

		}
		else if (tempTotalScenicRooms <= 0) {

			tempTotalScenicRooms = 0;

		}
		else if (tempTotalDeluxeSuites <= 0) {

			tempTotalDeluxeSuites = 0;

		}
		else if (tempTotalPenthouses <= 0) {

			tempTotalPenthouses = 0;

		}
		else {
		
		}

		struct tm newtime;
		time_t now = time(0);
		localtime_s(&newtime, &now);

		cout << "Date: " << 1 + newtime.tm_mon << "/" << newtime.tm_mday << "/" << 1900 + newtime.tm_year;
		cout << " | Time: " << newtime.tm_hour << ":" << newtime.tm_min;

		if (newtime.tm_hour >= 1 && newtime.tm_hour <= 11) {

			cout << " (" << newtime.tm_hour << ":" << newtime.tm_min << " AM)";
		}
		else if (newtime.tm_hour >= 12 || newtime.tm_hour >= 23) {

			if (newtime.tm_hour > 12) {

				timeTemp = newtime.tm_hour - 12;
				cout << " (" << timeTemp << ":" << newtime.tm_min << " PM)";
			}
		}

		cout << "\n\nWelcome to Savier's hotel! Please select one of the options to start:\n";
		cout << "\n    1) Reserve a Room\n    2) Get Total Made Today\n    3) Check Records\n    4) Save & Exit the Program\n\nOption: ";

		getline(cin, tempOptionSelect);

		if (tempOptionSelect == "1") {
			//Option 1 ------------------------------------------------------------------------------------------------
			cout << "\nCustomer Name: ";
			getline(cin, tempName);

			



				cout << "\nSelect which room to reserve(1-4): \n";
				cout << "=---------------------------------------------\n"
					<< "| # |  Room Names  | Available Rooms | Price |\n"
					<< "|---|--------------|-----------------|-------|\n";

				if (tempTotalCourtyardRooms < 10) { cout << "| 1 |  Courtyard   |        " << tempTotalCourtyardRooms << "        | $125  |\n"; }
				else { cout << "| 1 |  Courtyard   |        " << tempTotalCourtyardRooms << "       | $125  |\n"; }

				cout << "|---|--------------|-----------------|-------|\n";

				if (tempTotalScenicRooms < 10) { cout << "| 2 |    Scenic    |        " << tempTotalScenicRooms << "        | $145  |\n"; }
				else { cout << "| 2 |    Scenic    |        " << tempTotalScenicRooms << "       | $145  |\n"; }

				cout << "|---|--------------|-----------------|-------|\n";

				if (tempTotalDeluxeSuites < 10) { cout << "| 3 | Deluxe Suite |        " << tempTotalDeluxeSuites << "        | $350  |\n"; }
				else { cout << "| 3 | Deluxe Suite |        " << tempTotalDeluxeSuites << "       | $350  |\n"; }

				cout << "|---|--------------|-----------------|-------|\n"
					<< "| 4 |  Penthouse   |        " << tempTotalPenthouses << "        | $1135 |\n"
					<< "----------------------------------------------\n\nOption: ";

				int i = 0;
				while (i != -1)
				{
				getline(cin, tempRoomSelect);

				if (tempRoomSelect == "1") {

					if (tempTotalCourtyardRooms <= 0) {

						cout << "Error: No more Courtyard rooms, please choose another room.";
						Sleep(2000);

					}
					else if (tempTotalCourtyardRooms == 0 && tempTotalScenicRooms == 0 && tempTotalDeluxeSuites == 0 && tempTotalPenthouses == 0) {

						cout << "No more rooms available.";
						Sleep(2000);
					}

					roomSelect(tempRoomSelect);

					if (tempTotalCourtyardRooms >= 0) {i = -1;}
				}
				else if (tempRoomSelect == "2") {

					if (tempTotalScenicRooms <= 0) {

						cout << "Error: No more Scenic rooms, please choose another room.";
						Sleep(2000);

					}
					else if (tempTotalCourtyardRooms == 0 && tempTotalScenicRooms == 0 && tempTotalDeluxeSuites == 0 && tempTotalPenthouses == 0) {

						cout << "No more rooms available.";
						Sleep(2000);
					}

					roomSelect(tempRoomSelect);
					if (tempTotalCourtyardRooms >= 0) { i = -1; }
				}
				else if (tempRoomSelect == "3") {

					if (tempTotalDeluxeSuites <= 0) {

						cout << "Error: No more Deluxe Suites rooms, please choose another room.";
						Sleep(2000);

					}
					else if (tempTotalCourtyardRooms == 0 && tempTotalScenicRooms == 0 && tempTotalDeluxeSuites == 0 && tempTotalPenthouses == 0) {

						cout << "No more rooms available.";
						Sleep(2000);
					}

					roomSelect(tempRoomSelect);
					if (tempTotalCourtyardRooms >= 0) { i = -1; }
				}
				else if (tempRoomSelect == "4") {

					if (tempTotalPenthouses <= 0) {

						cout << "Error: No more Penthouse rooms, please choose another room.";
						Sleep(2000);

					}
					else if (tempTotalCourtyardRooms == 0 && tempTotalScenicRooms == 0 && tempTotalDeluxeSuites == 0 && tempTotalPenthouses == 0) {

						cout << "No more rooms available.";
						Sleep(2000);
					}

					roomSelect(tempRoomSelect);
					if (tempTotalCourtyardRooms >= 0) { i = -1; }
				}
				else {
					cout << "\nError: Wrong Number, Select a room to reserve(1-4): ";
				}
			}
			i = 0;
		}
		else if (tempOptionSelect == "2") {
			//Option 2 ------------------------------------------------------------------------------------------------
			getTotal();
		}
		else if (tempOptionSelect == "3") {
			//Option 3 ------------------------------------------------------------------------------------------------
			string stringTexts;
			int testing = -2;
			if (system("CLS")) {
				system("clear");
			}
			while (testing == -2){
				string stringTexts;
				cout << "Input a date to look for(mm-dd-yyyy) or -1 to leave: ";
				getline(cin, searchText);
				if (searchText == "-1") {
					testing = -1;
				}
				else {

					searchText = searchText + ".txt";
					ifstream fileSearch(searchText);
					if (system("CLS")) {
						system("clear");
					}
					if (fileSearch.is_open()) {
						while (getline(fileSearch, stringTexts))
						{
							cout << stringTexts << '\n';
						}
						fileSearch.close();
						cout << "\n\nType -1 to go back to the menu: ";
						cin >> testing;
					}
					else {
						cout << "\nError: File not found." << '\n';
					}
					cout << endl;
				}
			}
		}
		else if (tempOptionSelect == "4") {
			//Option 4 ------------------------------------------------------------------------------------------------
			int t = 0;
			int p = 2;
			int totalRoomsReserved;
			int totalRoomsNotReserved;

			file << "----------------------------------------------------------------------------------------------------------------------------------------------";
			file << "\nStandard Rooms, Courtyard - " << tempTotalCourtyardRooms << " room(s) left | " << totalCourtyardRooms - tempTotalCourtyardRooms << " room(s) used:\n----------------------------------------------------------------------------------------------------------------------------------------------\n";

			for (int i = 0; i < totalCourtyardRooms; i++)
			{

				if (courtyardRoomsArray[i].roomNumber == 0) {


				}
				else
				{
					file << "\n    Customer Name: " << courtyardRoomsArray[i].name;
					file << " | Room Type: " << courtyardRoomsArray[i].roomType;
					file << " | Room #: " << courtyardRoomsArray[i].roomNumber;
					file << " | Price: $" << courtyardRoomsArray[i].roomPrice;
					file << " | Date/Time Room Reserved: " << courtyardRoomsArray[i].dateStartedMonth << "/" << courtyardRoomsArray[i].dateStartedDay
						<< "/" << courtyardRoomsArray[i].dateStartedYear;
					file << " | Time: " << courtyardRoomsArray[i].timeStartedHour << ":" << courtyardRoomsArray[i].timeStartedMinutes;
					if (courtyardRoomsArray[i].timeStartedHour >= 1 && courtyardRoomsArray[i].timeStartedHour <= 11) {

						file << " (" << courtyardRoomsArray[i].timeStartedHour << ":" << courtyardRoomsArray[i].timeStartedMinutes << " AM)";
					}
					else if (courtyardRoomsArray[i].timeStartedHour >= 12 || courtyardRoomsArray[i].timeStartedHour >= 23) {

						if (courtyardRoomsArray[i].timeStartedHour > 12) {

							timeTemp = courtyardRoomsArray[i].timeStartedHour - 12;
							file << " (" << timeTemp << ":" << courtyardRoomsArray[i].timeStartedMinutes << " PM)";
						}
					}
				}
			}

			file << "\n\n----------------------------------------------------------------------------------------------------------------------------------------------";
			file << "\nStandard Room, Scenic - " << tempTotalScenicRooms << " room(s) left | " << totalScenicRooms - tempTotalScenicRooms << " room(s) used:\n----------------------------------------------------------------------------------------------------------------------------------------------\n";

			for (int i = 0; i < totalScenicRooms; i++)
			{

				if (scenicRoomsArray[i].roomNumber == 0) {


				}
				else
				{
					file << "\n    Customer Name: " << scenicRoomsArray[i].name;
					file << " | Room Type: " << scenicRoomsArray[i].roomType;
					file << " | Room #: " << scenicRoomsArray[i].roomNumber + 70;
					file << " | Price: $" << scenicRoomsArray[i].roomPrice;
					file << " | Date/Time Room Reserved: " << scenicRoomsArray[i].dateStartedMonth << "/" << scenicRoomsArray[i].dateStartedDay
						<< "/" << scenicRoomsArray[i].dateStartedYear;
					file << " | Time: " << scenicRoomsArray[i].timeStartedHour << ":" << scenicRoomsArray[i].timeStartedMinutes;
					if (scenicRoomsArray[i].timeStartedHour >= 1 && scenicRoomsArray[i].timeStartedHour <= 11) {

						file << " (" << scenicRoomsArray[i].timeStartedHour << ":" << scenicRoomsArray[i].timeStartedMinutes << " AM)";
					}
					else if (scenicRoomsArray[i].timeStartedHour >= 12 || scenicRoomsArray[i].timeStartedHour >= 23) {

						if (scenicRoomsArray[i].timeStartedHour > 12) {

							timeTemp = scenicRoomsArray[i].timeStartedHour - 12;
							file << " (" << timeTemp << ":" << scenicRoomsArray[i].timeStartedMinutes << " PM)";
						}
					}
				}
			}

			file << "\n\n----------------------------------------------------------------------------------------------------------------------------------------------";
			file << "\nDeluxe Suite - " << tempTotalDeluxeSuites << " room(s) left | " << totalDeluxeSuites - tempTotalDeluxeSuites << " room(s) used:\n----------------------------------------------------------------------------------------------------------------------------------------------\n";

			for (int i = 0; i < totalDeluxeSuites; i++)
			{

				if (deluxeSuitesArray[i].roomNumber == 0) {


				}
				else
				{
					file << "\n    Customer Name: " << deluxeSuitesArray[i].name;
					file << " | Room Type: " << deluxeSuitesArray[i].roomType;
					file << " | Room #: " << deluxeSuitesArray[i].roomNumber + 105;
					file << " | Price: $" << deluxeSuitesArray[i].roomPrice;
					file << " | Date/Time Room Reserved: " << deluxeSuitesArray[i].dateStartedMonth << "/" << deluxeSuitesArray[i].dateStartedDay
						<< "/" << deluxeSuitesArray[i].dateStartedYear;
					file << " | Time: " << deluxeSuitesArray[i].timeStartedHour << ":" << deluxeSuitesArray[i].timeStartedMinutes;

					if (deluxeSuitesArray[i].timeStartedHour >= 1 && deluxeSuitesArray[i].timeStartedHour <= 11) {

						file << " (" << deluxeSuitesArray[i].timeStartedHour << ":" << deluxeSuitesArray[i].timeStartedMinutes << " AM)";
					}
					else if (deluxeSuitesArray[i].timeStartedHour >= 12 || deluxeSuitesArray[i].timeStartedHour >= 23) {

						if (deluxeSuitesArray[i].timeStartedHour > 12) {

							timeTemp = deluxeSuitesArray[i].timeStartedHour - 12;
							file << " (" << timeTemp << ":" << deluxeSuitesArray[i].timeStartedMinutes << " PM)";
						}
					}
				}
			}

			file << "\n\n----------------------------------------------------------------------------------------------------------------------------------------------";
			file << "\nPenthouse - " << tempTotalPenthouses << " room(s) left | " << totalPenthouses - tempTotalPenthouses << " room(s) used:\n----------------------------------------------------------------------------------------------------------------------------------------------\n";

			for (int i = 0; i < totalPenthouses; i++)
			{

				if (penthousesArray[i].roomNumber == 0) {


				}
				else
				{
					file << "\n    Customer Name: " << penthousesArray[i].name;
					file << " | Room Type: " << penthousesArray[i].roomType;
					file << " | Room #: " << penthousesArray[i].roomNumber + 120;
					file << " | Price: $" << penthousesArray[i].roomPrice;
					file << " | Date/Time Room Reserved: " << penthousesArray[i].dateStartedMonth << "/" << penthousesArray[i].dateStartedDay
						<< "/" << penthousesArray[i].dateStartedYear;
					file << " | Time: " << penthousesArray[i].timeStartedHour << ":" << penthousesArray[i].timeStartedMinutes;

					if (penthousesArray[i].timeStartedHour >= 1 && penthousesArray[i].timeStartedHour <= 11) {

						file << " (" << penthousesArray[i].timeStartedHour << ":" << penthousesArray[i].timeStartedMinutes << " AM)";
					}
					else if (penthousesArray[i].timeStartedHour >= 12 || penthousesArray[i].timeStartedHour >= 23) {

						if (penthousesArray[i].timeStartedHour > 12) {

							timeTemp = penthousesArray[i].timeStartedHour - 12;
							file << " (" << timeTemp << ":" << penthousesArray[i].timeStartedMinutes << " PM)";
						}
					}
				}
			}

			totalRoomsReserved = (totalCourtyardRooms - tempTotalCourtyardRooms) + (totalScenicRooms - tempTotalScenicRooms) + (totalDeluxeSuites - tempTotalDeluxeSuites) + (totalPenthouses - tempTotalPenthouses);

			file << "\n\nTotal room(s) reserved: " << totalRoomsReserved << endl;

			totalRoomsNotReserved = (tempTotalCourtyardRooms + tempTotalScenicRooms + tempTotalDeluxeSuites + tempTotalPenthouses);

			file << "Total room(s) not reserved: " << totalRoomsNotReserved << endl;

			file << "\nRevenue generated for the day: $" << totalRevenue << "\n";
			file.close();


		}
		else {
			//Error ------------------------------------------------------------------------------------------------
			cout << "\nError: Wrong Number";
			Sleep(1000);
		}

	cout << endl;

	} while (tempOptionSelect != "4");
}

void hotel::roomSelect(string tempRoomSelect) {

	bool tempRoomSelectLoop = false;
	int i = 0;

	while (tempRoomSelectLoop == false)
	{
		if (tempRoomSelect == "1") {
			totalRevenue = totalRevenue + priceOfCourtyardRooms;
			i = 0;
			i = totalCourtyardRooms - tempTotalCourtyardRooms;
			courtyardRoomsArray[i].name = tempName;
			courtyardRoomsArray[i].roomNumber = i + 1;
			courtyardRoomsArray[i].roomPrice = priceOfCourtyardRooms;
			courtyardRoomsArray[i].roomType = "Courtyard";
			struct tm newtime;
			time_t now = time(0);
			localtime_s(&newtime, &now);
			courtyardRoomsArray[i].dateStartedDay = newtime.tm_mday;
			courtyardRoomsArray[i].dateStartedMonth = 1 + newtime.tm_mon;
			courtyardRoomsArray[i].dateStartedYear = 1900 + newtime.tm_year;
			courtyardRoomsArray[i].timeStartedHour = newtime.tm_hour;
			courtyardRoomsArray[i].timeStartedMinutes = newtime.tm_min;
			tempTotalCourtyardRooms--;
			tempName = "";
			cout << "\nCustomer Name: " << courtyardRoomsArray[i].name;
			cout << "\nRoom Number: " << courtyardRoomsArray[i].roomNumber;
			cout << "\n\nContinue?(Type anything for Yes): ";
			getline(cin, tempName);
			if (tempName != "")
			{
				tempRoomSelectLoop = true;
			}

		}
		else if (tempRoomSelect == "2") {
			totalRevenue = totalRevenue + priceOfScenicRooms;
			i = 0;
			i = totalScenicRooms - tempTotalScenicRooms;
			scenicRoomsArray[i].name = tempName;
			scenicRoomsArray[i].roomNumber = i + 1;
			scenicRoomsArray[i].roomPrice = priceOfScenicRooms;
			scenicRoomsArray[i].roomType = "Scenic";
			struct tm newtime;
			time_t now = time(0);
			localtime_s(&newtime, &now);
			scenicRoomsArray[i].dateStartedDay = newtime.tm_mday;
			scenicRoomsArray[i].dateStartedMonth = 1 + newtime.tm_mon;
			scenicRoomsArray[i].dateStartedYear = 1900 + newtime.tm_year;
			scenicRoomsArray[i].timeStartedHour = newtime.tm_hour;
			scenicRoomsArray[i].timeStartedMinutes = newtime.tm_min;
			tempTotalScenicRooms--;
			tempName = "";
			cout << "\nCustomer Name: " << scenicRoomsArray[i].name;
			cout << "\nRoom Number: " << scenicRoomsArray[i].roomNumber + 70;
			cout << "\n\nContinue?(Type anything for Yes): ";
			getline(cin, tempName);
			if (tempName != "")
			{
				tempRoomSelectLoop = true;
			}
		}
		else if (tempRoomSelect == "3") {
			totalRevenue = totalRevenue + priceOfDeluxeSuites;
			i = 0;
			i = totalDeluxeSuites - tempTotalDeluxeSuites;
			deluxeSuitesArray[i].name = tempName;
			deluxeSuitesArray[i].roomNumber = i + 1;
			deluxeSuitesArray[i].roomPrice = priceOfDeluxeSuites;
			deluxeSuitesArray[i].roomType = "Deluxe Suite";
			struct tm newtime;
			time_t now = time(0);
			localtime_s(&newtime, &now);
			deluxeSuitesArray[i].dateStartedDay = newtime.tm_mday;
			deluxeSuitesArray[i].dateStartedMonth = 1 + newtime.tm_mon;
			deluxeSuitesArray[i].dateStartedYear = 1900 + newtime.tm_year;
			deluxeSuitesArray[i].timeStartedHour = newtime.tm_hour;
			deluxeSuitesArray[i].timeStartedMinutes = newtime.tm_min;
			tempTotalDeluxeSuites--;
			tempName = "";
			cout << "\nCustomer Name: " << deluxeSuitesArray[i].name;
			cout << "\nRoom Number: " << deluxeSuitesArray[i].roomNumber + 105;
			cout << "\n\nContinue?(Type anything for Yes): ";
			getline(cin, tempName);
			if (tempName != "")
			{
				tempRoomSelectLoop = true;
			}
		}
		else if (tempRoomSelect == "4") {
			totalRevenue = totalRevenue + priceOfPenthouses;
			i = 0;
			i = totalPenthouses - tempTotalPenthouses;
			penthousesArray[i].name = tempName;
			penthousesArray[i].roomNumber = i + 1;
			penthousesArray[i].roomPrice = priceOfPenthouses;
			penthousesArray[i].roomType = "Penthouse";
			struct tm newtime;
			time_t now = time(0);
			localtime_s(&newtime, &now);
			penthousesArray[i].dateStartedDay = newtime.tm_mday;
			penthousesArray[i].dateStartedMonth = 1 + newtime.tm_mon;
			penthousesArray[i].dateStartedYear = 1900 + newtime.tm_year;
			penthousesArray[i].timeStartedHour = newtime.tm_hour;
			penthousesArray[i].timeStartedMinutes = newtime.tm_min;
			tempTotalPenthouses--;
			tempName = "";
			cout << "\nCustomer Name: " << penthousesArray[i].name;
			cout << "\nRoom Number: " << penthousesArray[i].roomNumber + 120;
			cout << "\n\nContinue?(Type anything for Yes): ";
			getline(cin, tempName);
			if (tempName != "")
			{
				tempRoomSelectLoop = true;
			}
		}
	}
}

void hotel::getTotal() {

	int t = 0;
	int p = 2;
	int totalRoomsReserved;
	int totalRoomsNotReserved;

	if (system("CLS")) {
		system("clear");
	}

	cout << "----------------------------------------------------------------------------------------------------------------------------------------------";
	cout << "\nStandard Rooms, Courtyard - " << tempTotalCourtyardRooms << " room(s) left | " << totalCourtyardRooms - tempTotalCourtyardRooms << " room(s) used:\n----------------------------------------------------------------------------------------------------------------------------------------------\n";
	
	for (int i = 0; i < totalCourtyardRooms; i++)
	{

		if (courtyardRoomsArray[i].roomNumber == 0) {


		}
		else
		{
			cout << "\n    Customer Name: " << courtyardRoomsArray[i].name;
			cout << " | Room Type: " << courtyardRoomsArray[i].roomType;
			cout << " | Room #: " << courtyardRoomsArray[i].roomNumber;
			cout << " | Price: $" << courtyardRoomsArray[i].roomPrice;
			cout << " | Date/Time Room Reserved: " << courtyardRoomsArray[i].dateStartedMonth << "/" << courtyardRoomsArray[i].dateStartedDay
				<< "/" << courtyardRoomsArray[i].dateStartedYear;
			cout << " | Time: " << courtyardRoomsArray[i].timeStartedHour << ":" << courtyardRoomsArray[i].timeStartedMinutes;
			if (courtyardRoomsArray[i].timeStartedHour >= 1 && courtyardRoomsArray[i].timeStartedHour <= 11) {

				cout << " (" << courtyardRoomsArray[i].timeStartedHour << ":" << courtyardRoomsArray[i].timeStartedMinutes << " AM)";
			}
			else if (courtyardRoomsArray[i].timeStartedHour >= 12 || courtyardRoomsArray[i].timeStartedHour >= 23) {

				if (courtyardRoomsArray[i].timeStartedHour > 12) {

					timeTemp = courtyardRoomsArray[i].timeStartedHour - 12;
					cout << " (" << timeTemp << ":" << courtyardRoomsArray[i].timeStartedMinutes << " PM)";
				}
			}
		}
	}

	cout << "\n\n----------------------------------------------------------------------------------------------------------------------------------------------";
	cout << "\nStandard Room, Scenic - " << tempTotalScenicRooms << " room(s) left | " << totalScenicRooms - tempTotalScenicRooms << " room(s) used:\n----------------------------------------------------------------------------------------------------------------------------------------------\n";

	for (int i = 0; i < totalScenicRooms; i++)
	{

		if (scenicRoomsArray[i].roomNumber == 0) {


		}
		else
		{
			cout << "\n    Customer Name: " << scenicRoomsArray[i].name;
			cout << " | Room Type: " << scenicRoomsArray[i].roomType;
			cout << " | Room #: " << scenicRoomsArray[i].roomNumber + 70;
			cout << " | Price: $" << scenicRoomsArray[i].roomPrice;
			cout << " | Date/Time Room Reserved: " << scenicRoomsArray[i].dateStartedMonth << "/" << scenicRoomsArray[i].dateStartedDay
				<< "/" << scenicRoomsArray[i].dateStartedYear;
			cout << " | Time: " << scenicRoomsArray[i].timeStartedHour << ":" << scenicRoomsArray[i].timeStartedMinutes;
			if (scenicRoomsArray[i].timeStartedHour >= 1 && scenicRoomsArray[i].timeStartedHour <= 11) {

				cout << " (" << scenicRoomsArray[i].timeStartedHour << ":" << scenicRoomsArray[i].timeStartedMinutes << " AM)";
			}
			else if (scenicRoomsArray[i].timeStartedHour >= 12 || scenicRoomsArray[i].timeStartedHour >= 23) {

				if (scenicRoomsArray[i].timeStartedHour > 12) {

					timeTemp = scenicRoomsArray[i].timeStartedHour - 12;
					cout << " (" << timeTemp << ":" << scenicRoomsArray[i].timeStartedMinutes << " PM)";
				}
			}
		}
	}

	cout << "\n\n----------------------------------------------------------------------------------------------------------------------------------------------";
	cout << "\nDeluxe Suite - " << tempTotalDeluxeSuites << " room(s) left | " << totalDeluxeSuites - tempTotalDeluxeSuites << " room(s) used:\n----------------------------------------------------------------------------------------------------------------------------------------------\n";

	for (int i = 0; i < totalDeluxeSuites; i++)
	{

		if (deluxeSuitesArray[i].roomNumber == 0) {


		}
		else
		{
			cout << "\n    Customer Name: " << deluxeSuitesArray[i].name;
			cout << " | Room Type: " << deluxeSuitesArray[i].roomType;
			cout << " | Room #: " << deluxeSuitesArray[i].roomNumber + 105;
			cout << " | Price: $" << deluxeSuitesArray[i].roomPrice;
			cout << " | Date/Time Room Reserved: " << deluxeSuitesArray[i].dateStartedMonth << "/" << deluxeSuitesArray[i].dateStartedDay
				<< "/" << deluxeSuitesArray[i].dateStartedYear;
			cout << " | Time: " << deluxeSuitesArray[i].timeStartedHour << ":" << deluxeSuitesArray[i].timeStartedMinutes;

			if (deluxeSuitesArray[i].timeStartedHour >= 1 && deluxeSuitesArray[i].timeStartedHour <= 11) {

				cout << " (" << deluxeSuitesArray[i].timeStartedHour << ":" << deluxeSuitesArray[i].timeStartedMinutes << " AM)";
			}
			else if (deluxeSuitesArray[i].timeStartedHour >= 12 || deluxeSuitesArray[i].timeStartedHour >= 23) {

				if (deluxeSuitesArray[i].timeStartedHour > 12) {

					timeTemp = deluxeSuitesArray[i].timeStartedHour - 12;
					cout << " (" << timeTemp << ":" << deluxeSuitesArray[i].timeStartedMinutes << " PM)";
				}
			}
		}
	}

	cout << "\n\n----------------------------------------------------------------------------------------------------------------------------------------------";
	cout << "\nPenthouse - " << tempTotalPenthouses << " room(s) left | " << totalPenthouses - tempTotalPenthouses << " room(s) used:\n----------------------------------------------------------------------------------------------------------------------------------------------\n";

	for (int i = 0; i < totalPenthouses; i++)
	{

		if (penthousesArray[i].roomNumber == 0) {


		}
		else
		{
			cout << "\n    Customer Name: " << penthousesArray[i].name;
			cout << " | Room Type: " << penthousesArray[i].roomType;
			cout << " | Room #: " << penthousesArray[i].roomNumber + 120;
			cout << " | Price: $" << penthousesArray[i].roomPrice;
			cout << " | Date/Time Room Reserved: " << penthousesArray[i].dateStartedMonth << "/" << penthousesArray[i].dateStartedDay
				<< "/" << penthousesArray[i].dateStartedYear;
			cout << " | Time: " << penthousesArray[i].timeStartedHour << ":" << penthousesArray[i].timeStartedMinutes;

			if (penthousesArray[i].timeStartedHour >= 1 && penthousesArray[i].timeStartedHour <= 11) {

				cout << " (" << penthousesArray[i].timeStartedHour << ":" << penthousesArray[i].timeStartedMinutes << " AM)";
			}
			else if (penthousesArray[i].timeStartedHour >= 12 || penthousesArray[i].timeStartedHour >= 23) {

				if (penthousesArray[i].timeStartedHour > 12) {

					timeTemp = penthousesArray[i].timeStartedHour - 12;
					cout << " (" << timeTemp << ":" << penthousesArray[i].timeStartedMinutes << " PM)";
				}
			}
		}
	}

	totalRoomsReserved = (totalCourtyardRooms - tempTotalCourtyardRooms) + (totalScenicRooms - tempTotalScenicRooms) + (totalDeluxeSuites - tempTotalDeluxeSuites) + (totalPenthouses - tempTotalPenthouses);

	cout << "\n\nTotal room(s) reserved: " << totalRoomsReserved << endl;

	totalRoomsNotReserved = (tempTotalCourtyardRooms + tempTotalScenicRooms + tempTotalDeluxeSuites + tempTotalPenthouses);

	cout << "Total room(s) not reserved: " << totalRoomsNotReserved << endl;

	cout << "\nRevenue generated for the day: $" << totalRevenue << "\n";

	cout << "\nContinue?(Type anything for Yes): ";
	getline(cin, tempName);

}