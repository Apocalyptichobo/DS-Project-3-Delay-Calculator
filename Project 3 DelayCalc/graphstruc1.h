#pragma once
#include <iostream>
#include <istream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

class GraphS {

private:
	struct GFlight {

		int date;

		string carrier;
		string flight_number;

		int crs_dept_time;
		int dept_time;
		int dep_delay;

		int taxi_out;
		int wheels_off;

		int wheels_on;
		int taxi_in;

		int crs_arr_time;
		int arr_time;
		int arr_delay;

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
	//our adjacency matrix
	//vector<vector<GFlight>> AdjMatrix(int row, vector<int>(column));
	vector<vector<GFlight>> AdjMatrix;
	GFlight a_matrix[1][1];
public:
	GraphS();
	GraphS(int year);

};
// 2016: 313 by 313 (airport graph)
// 2017: 320 by 320 (airport graph)
// 2018: 358 by 358 (airport graph)
