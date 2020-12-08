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
public:
    GraphS(); //DONE
    void readData(string d); //DONE
    void Option1(string& input);
    void Option2(string& input, string& input2);
    void Option3(string& input);
    void Option4(string& input);
    void Option5(string& input);
    map<string, int> airports;
    map<string, string> carrier;
    vector<string> delays{ "CARRIER", "WEATHER", "NAS", "SECURITY", "LATE_AIRCRAFT" };

    //The Big Three
    GraphS(const GraphS& other);
    GraphS& operator=(const GraphS& other);

    void copy(const GraphS& other);
	//destructor
    ~GraphS();


    //Helper for the min and max
    string max_string(map<string, int> freqs, string null_display)
    {
        int maximum = 0;
        string maxString = null_display;
        for (auto it = freqs.begin(); it != freqs.end(); it++)
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
    //Option 1
    int comAvgDelay(string& corp); //DONE, comAvgDelay
    string comDelayType(string& corp); // DONE, comDelayType
    float comPerDelayed(string& corp); //DONE, comPerDelayed
    int comAvgTravelTime(string& corp); //DONE, comAvgTravelTime
    int comNumLaunched(string& corp); //DONE, comNumLaunched
    int comNumDelayed(string& corp); //DONE, comNumDelayed

    //Option 2
    int ADAvgDelay(string& airpt1, string& airpt2); //DONE, ADAvgDelay
    string ADDelayType(string& airpt1, string& airpt2); //DONE, ADDelayType
    float ADPerDelayed(string& airpt1, string& airpt2); //DONE, ADPerDelayed
    pair<int, int> avgTaxiTime(string& airpt1, string& airpt2);
    int ADNumLaunched(string& airpt1, string& airpt2); //DONE, ADNumLaunched
    int ADNumDelayed(string& airpt1, string& airpt2); //DONE, ADNumDelayed

    //Option 3
    int airAvgDelay(string& airpt); //DONE, airAvgDelay
    string airDelayType(string& airpt); //DONE, airDelayType
    string airCarrier(string& airpt); //DONE, airCarrier
    float airPercentDelayed(string& airpt); //DONE, airPercentDelayed
    int airNumFlownTo(string& aiprt); //DONE, airNumFlown
    int airNumFlownFrom(string& airpt); // DONE, airNumFlown
    int airNumDelayed(string& airpt);
    int airAvgTravelTime(string& airpt);


    //Option 4 - delays
    // CARRIER
    // WEATHER
    // NAS
    // SECURITY
    // LATE_AIRCRAFT
    int avgDelay(string& delayType); //DONE, avgDelay
    int avgTravelTime(string& delayType); //DONE, avgTravelTime

    //Option 5
    int timeAvgDelay(int time_of_day); //DONE, timeAvgDelay
    string timeDelayType(int time_of_day); //DONE, timeDelayType
    pair<vector<string>,vector<string>> airportDelayTimes(int time_of_day); //DONE, airportDelayTimes
    float timePercentDelayed(int time_of_day); //DONE, timePercentDelayed
};