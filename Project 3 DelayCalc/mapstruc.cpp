#include "mapstruc.h"


MapS::MapS()
{

}

float MapS::average(string key) //average X's at airport.
{
	//this returns the averages
	float avgDelayT = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		avgDelayT += iter->second.dep_delay + iter->second.arr_delay;
	}
	avgDelayT /= data.size();


}

string MapS::delayType()
{
	//find the most common type of delay
	vector<int> c;
	int carrierC, weatherC, nasC, securityC, lateaircraftC;
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
	//key is airport number
	std::map<int, int> departures;

	return data[key].size();


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
	for (auto iter = data.begin(); iter != data.end(); iter++) 
	{
		avgDelayT += iter->second.dep_delay + iter->second.arr_delay;
	}
	avgDelayT /= data.size();

	//find the most common type of delay
	map<int, string> com; 
	int carrierC, weatherC, nasC, securityC, lateaircraftC; 
	for (auto iter = data.begin(); iter != data.end(); iter++) 
	{
		if (iter->second.carrier_delay > 0) { carrierC++; }
		if (iter->second.weather_delay > 0) { weatherC++; }
		if (iter->second.nas_delay > 0) { nasC++; }
		if (iter->second.security_delay > 0) { securityC++; }
		if (iter->second.late_aircraft_delay > 0) { lateaircraftC++ }
	}
	//map sorts in increasing order so last member of map is the greatest 
	com[carrierC] ="Carrier" ;
	com[weatherC] ="Weather";
	com[nasC] = "nas";
	com[securityC](stringrity" ;
	com[lateaircraftC] ="Late Aircraft" ;

	//number of delayed flights / all flights


} 

intotal = iter->second.det MapS::total(string key)
{
		if (if)
		

	int total = 0;
		
	

++	for (auto iter = data.begin(); iter != data.end(); iter)
	
	
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

