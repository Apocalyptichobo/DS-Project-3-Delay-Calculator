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
		string carrier; //company VF DL
		string flight_number; 

		string origin; //airport ATL,
		string destination; //airport

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

		int air_time; //time in the air
		int distance;
		//delays
		int carrier_delay; //time delayed
		int weather_delay; //time delayed
		int nas_delay;	   //time delayed	
		int security_delay; //time delayed
		int late_aircraft_delay; //time delayed
	};

public:
	map<int, Flight> data; //key first line, value is the flight data
	MapS();
	MapS(int year);
	//company option 1
	int comAvgDelay(string search); //average delay time for company (done)
	string comDelayType(string search); //most common delay type for company (done)
	float comPerDelayed(string search); //percentage of flights delayed for company (done)
	int comAvgTravelTime(string search); //average travel time for company (done)
	int comNumLaunched(string search); //number of planes launched for company (done)
	int comNumDelayed(string search); //number of planes delayed for company (done)

	//arrival/departure option 2
	int ADAvgDelay(string o, string d); //average delay time for A/D
	string ADDelayType(string o, string d); //average delay type for company A/D
	float ADPerDelayed(string o, string d); //percentage of flights delayed for A/D
	pair<int,int> avgTaxiTime(string o, string d); //gets taxi in and out time for A/D, first position is in, second is out
	int ADNumLaunched(string o, string d); //number of planes launched
	int ADNumDelayed(string o, string d); //number of planes delayed

	//airport option 3
	//int total(string search); //total X's at airport. (is this needed?)
	float airAvgDelay(string search); //average X's at airport.(done)
	string airDelayType(string search); //find the most common type of delay for given airport (done)
	float airPercentDelayed(string search); //percentage delayed at given airport (done)
	string airCarrier(string search); //most common airline flown from given airport
	int airAvgTravelTime(string search); //average travel time at given airport 
	pair<int, int> airNumFlown(string search); //flights to and from, in that order returned
	int airNumDelayed(string search); //number of planes delayed at given airport

	//type of delay option 4
	int avgDelay(string search); //average delay time for given delay
	pair<vector<string>, vector<string>> airportHighLow(string search); /*pair of vectors that contain the highest and lowest airport delay time
	first vector will have the highest, second will have the lowest*/
	int avgTravelTime(string search); //average travel time for given delay
	string bestAirport(string search); //best airport to travel with given delay

	//departure time option 5 (we should decide whether or not we will make this +- any time)
	int timeAvgDelay(int time); //average delay time for given time
	string timeDelayType(int time); //find the most common type of delay for given time
	pair<string, string> airportDelayTimes(int time); //finds the airports with the best and worst delay time for the given time, first is best second is worst
	float timePercentDelayed(int time); //percentage delayed at given time
};

