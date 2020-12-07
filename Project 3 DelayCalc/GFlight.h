#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <istream>
#include <sstream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;

class GFlight
{
public:
    //string date;
    string carrier; //company VF DL
    //string flight_number;

    string origin;
    string destination;

    int crs_dept_time;
    int dept_time;
    int dep_delay; //delay time

    int taxi_out;
    //int wheels_off;

    //int wheels_on;
    int taxi_in;

    //int crs_arr_time;
    //int arr_time;
    int arr_delay; //second delay time

    int cancelled;
    //string cancel_code;

    //int diverted;

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

        //date = -1;
        carrier = "";
        //flight_number = "";

        origin = "";
        destination = "";

        crs_dept_time = -1;
        dept_time = -1;
        dep_delay = -1;

        taxi_out = -1;
        //wheels_off = -1;

        //wheels_on = -1;
        taxi_in = -1;

        //crs_arr_time = -1;
        //arr_time = -1;
        arr_delay = -1;

        cancelled = -1;
        //cancel_code = "";

        //diverted = -1;

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

        //g.date = obj.date;
        g.carrier = obj.carrier;
        //g.flight_number = obj.flight_number;

        g.origin = obj.origin;
        g.destination = obj.destination;

        g.crs_dept_time = obj.crs_dept_time;
        g.dept_time = obj.dept_time;
        g.dep_delay = obj.dep_delay;

        g.taxi_out = obj.taxi_out;
        //g.wheels_off = obj.wheels_off;

        //g.wheels_on = obj.wheels_on;
        g.taxi_in = obj.taxi_in;

        //g.crs_arr_time = obj.crs_arr_time;
        //g.arr_time = obj.arr_time;
        g.arr_delay = obj.arr_delay;

        g.cancelled = obj.cancelled;
        //g.cancel_code = obj.cancel_code;

        //g.diverted = obj.diverted;

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
