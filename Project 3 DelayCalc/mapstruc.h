#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class MapS {
private:
	struct Flight
	{
		int date;
		string carrier;
		string flight_number;

		string origin;
		string destination;

		int crs_dept_time;
		int dept_time;
		int dep_delay; //delay time

		int taxi_out;
		int wheels_off;

		int wheels_on;
		int taxi_in;

		int crs_arr_time;
		int arr_time;
		int arr_delay; //second delay time

		int cancelled;
		string cancel_code;

		int diverted;

		int crs_elapsed_time;
		int actual_elapsed_time;

		int air_time;
		int distance;

		int carrier_delay;
		int weather_delay;

		int nas_delay;
		int security_delay;
		int late_aircraft_delay;
	};

public:
	map<int, Flight> data; //key first line, value is the flight data
	MapS();
	MapS(int year);
	int total(string search); //total X's at airport. 
	float average(string search); //average X's at airport.
	string delayType(); //find the most common type of delay

};

