#pragma once
#define WIDTH 358
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

#include "GFlight.h"


using namespace std;

class GraphS {
private:
    vector<GFlight>** data;
    map<string, int> airports;
public:
    GraphS(); //DONE
    void readData(int year); //DONE
    void Option1(string& input);
    void Option2(string& input, string& input2);
    void Option3(string& input);
    void Option4(string& input);
    void Option5(string& input);


    //The Big Three
    GraphS(const GraphS& other);
    GraphS& operator=(const GraphS& other);

    void copy(const GraphS& other);
    ~GraphS();


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


