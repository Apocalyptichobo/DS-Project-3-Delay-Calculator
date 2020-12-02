#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <vector>
#include <map>a
#include <sstream>
using namespace std;

class GraphS {

private:
	struct GFlight {

		int date;

		string op_carrier;
		int op_carrier_fl_num;

		int crs_dep_time;
		int dep_time;
		int dep_delay;

		int taxi_out;
		int wheels_off;

		int wheels_on;
		int taxi_in;

		int crs_arr_time;
		int arr_time;
		int arr_delay;

		int cancelled;
		int cancellation_code;

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

		int unnamed;
		int flight_id;

	};

	int row, column;
	//2D vector for our adjacency matrix
	vector<vector<Graph_Flight>> AdjMatrix(row, vector<int>(column));


public:
	GraphS();
	GraphS(int year);

};


// 2016: 313 by 313 (airport graph)
// 2017: 320 by 320 (airport graph)
// 2018: 358 by 358 (airport graph)

#pragma once
