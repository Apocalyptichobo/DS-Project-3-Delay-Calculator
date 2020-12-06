#pragma once
#define WIDTH 358
#include <iostream>
#include <string>
#include <fstream>
#include <istream>
#include <sstream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>


using namespace std;

class GraphS {
private:
    class GFlight
    {
    public:
        int date;
        string carrier; //company VF DL
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
        //delays
        int carrier_delay; //time delayed
        int weather_delay; //time delayed
        int nas_delay;	   //time delayed
        int security_delay; //time delayed
        int late_aircraft_delay; //time delayed

        GFlight()
        {

            date = -1;
            carrier = "";
            flight_number = "";

            origin = "";
            destination = "";

            crs_dept_time = -1;
            dept_time = -1;
            dep_delay = -1;

            taxi_out = -1;
            wheels_off = -1;

            wheels_on = -1;
            taxi_in = -1;

            crs_arr_time = -1;
            arr_time = -1;
            arr_delay = -1;

            cancelled = -1;
            cancel_code = "";

            diverted = -1;

            crs_elapsed_time = -1;
            actual_elapsed_time = -1;

            air_time = -1;
            distance = -1;

            carrier_delay = -1;
            weather_delay = -1;
            nas_delay = -1;
            security_delay = -1;
            late_aircraft_delay = -1;

        }
        GFlight operator=(const GFlight& obj) {

            GFlight g;

            g.date = obj.date;
            g.carrier = obj.carrier;
            g.flight_number = obj.flight_number;

            g.crs_dept_time = obj.crs_dept_time;
            g.dept_time = obj.dept_time;
            g.dep_delay = obj.dep_delay;

            g.taxi_out = obj.taxi_out;
            g.wheels_off = obj.wheels_off;

            g.wheels_on = obj.wheels_on;
            g.taxi_in = obj.taxi_in;

            g.crs_arr_time = obj.crs_arr_time;
            g.arr_time = obj.arr_time;
            g.arr_delay = obj.arr_delay;

            g.cancelled = obj.cancelled;
            g.cancel_code = obj.cancel_code;

            g.diverted = obj.diverted;

            g.crs_elapsed_time = obj.crs_elapsed_time;
            g.actual_elapsed_time = obj.actual_elapsed_time;

            g.air_time = obj.air_time;
            g.distance = obj.distance;

            //delays
            g.carrier_delay = obj.carrier_delay;
            g.weather_delay = obj.weather_delay;
            g.nas_delay = obj.nas_delay;
            g.security_delay = obj.security_delay;
            g.late_aircraft_delay = obj.late_aircraft_delay;

            return g;
        }
    };
    vector<GFlight> data[WIDTH][WIDTH];
    map<string, int> airports;
public:
    GraphS(); //DONE
    void readData(int year); //DONE
    void Option1(string input);
    void Option2(string input, string input2);
    void Option3(string input);
    void Option4(string input);
    void Option5(string input);

	//Helper for the min and max
    string max_string(map<string, int> freqs, string null_display)
	{
		int maximum = 0;
		string maxString = null_display;
		for (auto it = freqs.end(); it != freqs.end(); it++)
		{
			if (it->second > maximum)
			{
				maximum = it->second;
				maxString = it->first;

			}

		}
    
		return maxString;
	}
    vector<string> fillVector(map<string, int> m, int how_many)
    {
		int counter = how_many;
        vector<string>v;

		for(auto it =m.begin(); it != m.end(); it++)
		{
			v.push_back(it->first);
			counter--;
			if (counter == 0) return v;
		
		}

	}
	////Helpers for sorting by value
	//bool criterionAsc(pair<string,int>& pair1, pair<string,int>&pair2)
    //{
    //    return pair1.second < pair2.second;
	//}
	//bool criterionDesc(pair<string,int>& pair1, pair<string,int>&pair2)
    //{
    //    return pair2.second > pair2.second;
	//}
    //
	//void SortbyValue(map<string,int> Map, string& s)
	//{
	//	vector<pair<string,int>> v;
    //
	//	//copy key value pairs
    //    for (auto it : Map)
    //    {
    //        v.push_back(it);
    //    }
	//	if (s == "Ascending") 
	//	{
	//		sort(Map.begin(), Map.end(), criterionAsc);
	//	}
	//	else 
	//	{
	//		sort(Map.begin(), Map.end(), criterionDesc);
	//	}
    //
	//}

	//Option 1
    float comAvgDelay(string& corp); //DONE, comAvgDelay
    string comDelayType(string& corp); // DONE, comDelayType
    float comPerDelayed(string& corp); //DONE, comPerDelayed
    float comAvgTravelTime(string& corp); //DONE, comAvgTravelTime
    int comNumLaunched(string& corp); //DONE, comNumLaunched
    int comNumDelayed(string& corp); //DONE, comNumDelayed

	//Option 2
    float ADAvgDelay(string& airpt1, string& airpt2); //DONE, ADAvgDelay
    string ADDelayType(string& airpt1, string& airpt2); //DONE, ADDelayType
    float ADPerDelayed(string& airpt1, string& airpt2); //DONE, ADPerDelayed
    float avgTaxiTime(string& airpt1, string& airpt2, int in_or_out);
    int ADNumLaunched(string& airpt1, string& airpt2); //DONE, ADNumLaunched
    int ADNumDelayed(string& airpt1, string& airpt2); //DONE, ADNumDelayed

    //Option 3
    float airAvgDelay(string& airpt); //DONE, airAvgDelay
    string airDelayType(string& airpt); //DONE, airDelayType
    string airCarrier(string& airpt); //DONE, airCarrier
    float airPercentDelayed(string& airpt); //DONE, airPercentDelayed
    int airNumFlownTo(string& aiprt); //DONE, airNumFlown
	int airNumFlownFrom(string& airpt); // DONE, airNumFlown
    int airNumDelayed(string& airpt);
    float airAvgTravelTime(string& airpt);


    //Option 4 - delays
    // CARRIER
    // WEATHER
    // NAS
    // SECURITY
    // LATE_AIRCRAFT
    float avgDelay(string& delayType); //DONE, avgDelay
    //pair<vector<string>,vector<string>> airportHighLow(string& delayType, int how_many); //airportHighLow
    float avgTravelTime(string& delayType); //DONE, avgTravelTime
    //string bestAirport(string search); //, bestAirport

	//Option 5 
    float timeAvgDelay(int time_of_day); //DONE, timeAvgDelay
    string timeDelayType(int time_of_day); //DONE, timeDelayType
    string airportDelayTimes(int time_of_day, int least_or_most); //DONE, airportDelayTimes
    float timePercentDelayed(int time_of_day); //DONE, timePercentDelayed
};	