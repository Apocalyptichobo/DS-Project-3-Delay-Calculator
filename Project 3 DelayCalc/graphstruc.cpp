#include "graphstruc1.h"

GraphS::GraphS()
{
	row = 1;
	column = 1;
	AdjMatrix(1, vector<int>(1));
	a_matrix = GFlight[1][1];
}

GraphS::GraphS(int year) 
{

	map<string, int> airports;
	int airport_id = 0;

	string dataset;
	if (year == 2016)
	{
		AdjMatrix(313, vector<int>(313));
		a_matrix = GFlight[313][313];
		dataset = "Input/2016p.csv";
	}
	else if (year == 2017)
	{
		AdjMatrix(320, vector<int>(320));
		a_matrix = GFlight[320][320];
		dataset = "Input/2017p.csv";
	}
	else if (year == 2018)
	{
		AdjMatrix(358, vector<int>(358));
		a_matrix =  GFlight[358][358];
		dataset = "Input/2018p.csv";
	}

	ifstream file;
	file.open(dataset, ios_base::in);
	bool first = true;
	string r, t, temp, origin, destination; //each row
	while (getline(file, r)) {
		if (first) {
			first = false;
			continue;
		}
		GFlight f;
		stringstream ss(r);
		getline(ss, temp, ','); //skips the numbering
		getline(ss, temp, ',');
		f.date = stoi(temp);	//date
		getline(ss, temp, ',');
		f.carrier = temp;		//carrier
		getline(ss, temp, ',');
		f.flight_number = temp; //num

		getline(ss, temp, ',');
		origin = temp;
		if (airports.count(origin) == 0)
		{
			airports[origin] = airport_id;
			airport_id++;
		}

		getline(ss, temp, ',');
		destination = temp;

		if (airports.count(destination) == 0)
		{
			airports[destination] = airport_id;
			airport_id++;
		}

		getline(ss, temp, ',');
		f.crs_dept_time = stoi(temp);
		getline(ss, temp, ',');
		f.dept_time = stoi(temp);
		getline(ss, temp, ',');
		f.dep_delay = stoi(temp);
		getline(ss, temp, ',');
		f.wheels_off = stoi(temp);
		getline(ss, temp, ',');
		f.wheels_on = stoi(temp);
		getline(ss, temp, ',');
		f.taxi_in = stoi(temp);
		getline(ss, temp, ',');
		f.crs_arr_time = stoi(temp);
		getline(ss, temp, ',');
		f.arr_time = stoi(temp);
		getline(ss, temp, ',');
		f.arr_delay = stoi(temp);
		getline(ss, temp, ',');
		f.cancelled = stoi(temp);
		getline(ss, temp, ',');
		f.cancel_code = temp;
		getline(ss, temp, ',');
		f.diverted = stoi(temp);
		getline(ss, temp, ',');
		f.crs_elapsed_time = stoi(temp);
		getline(ss, temp, ',');
		f.actual_elapsed_time = stoi(temp);
		getline(ss, temp, ',');
		f.air_time = stoi(temp);
		getline(ss, temp, ',');
		f.distance = stoi(temp);
		getline(ss, temp, ',');
		f.carrier_delay = stoi(temp);
		getline(ss, temp, ',');
		f.weather_delay = stoi(temp);
		getline(ss, temp, ',');
		f.nas_delay = stoi(temp);
		getline(ss, temp, ',');
		f.security_delay = stoi(temp);
		getline(ss, temp, ',');
		f.late_aircraft_delay = stoi(temp);
		AdjMatrix[airports[origin]][airports[destination]];
		a_matrix[airports[origin]][airports[destination]];
	}
	file.close();
}