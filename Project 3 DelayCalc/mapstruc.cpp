#include "mapstruc.h"


MapS::MapS()
{

}

float MapS::airAvgDelay(string search) //average X's at airport. 
{
	//search is the 3letter ATL
	//this returns the average delay time at this specific airport
	float avgDelayT = 0;

	for (auto iter = data.begin(); iter != data.end(); iter++)
	{//if the 3letter idcode matches the passed in value
		if (iter->second.origin == search) 
		{
			avgDelayT += iter->second.dep_delay + iter->second.arr_delay;
		}
		
	}
	avgDelayT /= data.size();
}

string MapS::airDelayType(string search)
{
	//find the most common type of delay
	vector<int> c;
	int carrierC = 0, weatherC = 0, nasC = 0, securityC = 0, lateaircraftC = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.carrier_delay > 0) { carrierC++; }
		if (iter->second.weather_delay > 0) { weatherC++; }
		if (iter->second.nas_delay > 0) { nasC++; }
		if (iter->second.security_delay > 0) { securityC++; }
		if (iter->second.late_aircraft_delay > 0) { lateaircraftC++; }
	}
	


	return string();
}

float MapS::airPercentDelayed(string search)
{
	float total_flights = 0;
	float number_flights_delayed = 0;


	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.carrier == search)
			{

				if (iter->second.carrier_delay != -1)
				{
					number_flights_delayed++;
					continue;
				}
				else if (iter->second.weather_delay != -1)
				{
					number_flights_delayed++;
					continue;
				}
				else if (iter->second.nas_delay != -1)
				{
					number_flights_delayed++;
					continue;
				}
				else if (iter->second.security_delay != -1)
				{
					number_flights_delayed++;
					continue;
				}
				else if (iter->second.late_aircraft_delay != -1)
				{
					number_flights_delayed++;
					continue;
				}

			}

			total_flights++;
		}

		return number_flights_delayed / total_flights;
}

int MapS::airAvgTravelTime(string search)
{
	return 0;
}

int MapS::airNumLaunched(string search)
{
	return 0;
}

int MapS::airNumDelayed(string search)
{
	return 0;
}

int MapS::avgDelay(string search)
{
	return 0;
}

pair<vector<string>, vector<string>> MapS::airportHighLow(string search)
{
	return pair<vector<string>, vector<string>>();
}

int MapS::avgTravelTime(string search)
{
	return 0;
}

string MapS::bestAirport(string search)
{
	return string();
}

int MapS::timeAvgDelay(int search)
{
	return 0;
}

string MapS::timeDelayType(int time)
{
	return string();
}

pair<string, string> MapS::airportDelayTimes(int time)
{
	return pair<string, string>();
}

float MapS::timePercentDelayed(int time)
{
	return 0.0f;
}

MapS::MapS(int year)
{
	string dataset;
	if (year == 2016) dataset = "Input/2016p.csv";
	else if (year == 2017) dataset = "Input/2017p.csv";
	else if (year == 2018) dataset = "Input/2018p.csv";
	ifstream file;
	file.open(dataset, ios_base::in);
	bool first = true;
	string r, t, temp, name; //each row
	while (getline(file, r)) {
		if (first) {
			first = false;
			continue;
		}
		Flight f;
		stringstream ss(r);
		getline(ss, name, ',');
		getline(ss, temp, ',');
		f.date = stoi(temp);
		getline(ss, temp, ',');
		f.carrier = temp;
		getline(ss, temp, ',');
		f.flight_number = temp;
		getline(ss, temp, ',');
		f.origin = temp;
		getline(ss, temp, ',');
		f.destination = temp;
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
		data.emplace(stoi(name), f);
		//data[stoi(name)] = f;
	}
	file.close();
}

//start of option 1
int MapS::comAvgDelay(string search)
{
	float avgDelayT = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.carrier == search)
		{
			avgDelayT += iter->second.dep_delay + iter->second.arr_delay;
		}

	}
	return avgDelayT;
} 
//done

string MapS::comDelayType(string search)
{



	return string();
}

float MapS::comPerDelayed(string search)
{
	return 0.0f;
}

int MapS::comAvgTravelTime(string search)
{
	return 0;
}

int MapS::comNumLaunched(string search)
{
	return 0;
}

int MapS::comNumDelayed(string search)
{
	return 0;
}

int MapS::ADAvgDelay(string search)
{
	return 0;
}

string MapS::ADDelayType(string search)
{
	return string();
}

float MapS::ADPerDelayed(string search)
{
	return 0.0f;
}

pair<int, int> MapS::avgTaxiTime(string search)
{
	return pair<int, int>();
}

int MapS::ADNumLaunched(string search)
{
	return 0;
}

int MapS::ADNumDelayed(string search)
{
	return 0;
}



