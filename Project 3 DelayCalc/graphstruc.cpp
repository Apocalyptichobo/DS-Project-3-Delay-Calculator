#include "graphstruc1.h"

GraphS::GraphS()
{
	airports.clear();
}

void GraphS::readData(int year) 
{

	int airport_id = 0;

	string dataset;
	if (year == 2016) dataset = "Input/2016p.csv";
	else if (year == 2017) dataset = "Input/2017p.csv";
	else if (year == 2018) dataset = "Input/2018p.csv";

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
		
		data[airports[origin]][airports[destination]] = f;

	}
	file.close();
}
float GraphS::avgDelayTime(string corp)
{
	float num_delayed_flights = 0;
	float total_delay = 0;

	
	for(int j = 0; j < WIDTH; j++)
	{
	    float delay_time = 0;

		if(data[airports[corp]][j].carrier_delay != -1)
		{
			delay_time += data[airports[corp]][j].carrier_delay;
		}
		if(data[airports[corp]][j].weather_delay != -1)
		{
			delay_time += data[airports[corp]][j].weather_delay;
		}
		if(data[airports[corp]][j].nas_delay != -1)
		{
			delay_time += data[airports[corp]][j].nas_delay;
		}
		if(data[airports[corp]][j].security_delay != -1)
		{
			delay_time += data[airports[corp]][j].security_delay;
		}
		if(data[airports[corp]][j].late_aircraft_delay != -1)
		{
			delay_time += data[airports[corp]][j].late_aircraft_delay;
		}
		
		if(delay_time !=0) 
		{
			total_delay += delay_time;
			num_delayed_flights++;
		}

	}
}


string GraphS::commonDelay(string corp)
{
	map<string, int> delay_freqs;

	for(int j = 0; j < WIDTH; j++)
	{

		if(data[airports[corp]][j].carrier_delay != -1)
		{
			delay_freqs["Carrier Delay"] = delay_freqs.count("Carrier Delay") + 1;
		}
		if(data[airports[corp]][j].weather_delay != -1)
		{
			delay_freqs["Weather Delay"] = delay_freqs.count("Weather Delay") + 1;
		}
		if(data[airports[corp]][j].nas_delay != -1)
		{
			delay_freqs["nas Delay"] = delay_freqs.count("nas Delay") + 1;
		}
		if(data[airports[corp]][j].security_delay != -1)
		{
			delay_freqs["Security Delay"] = delay_freqs.count("Security Delay") + 1;
		}
		if(data[airports[corp]][j].late_aircraft_delay != -1)
		{
			delay_freqs["Late Air Craft Delay"] = delay_freqs.count("Late Air Craft Delay") + 1;
		}

	}

	int maximum = delay_freqs["Carrier Delay"];
	string maxString = "Carrier Delay";
	for(auto it = delay_freqs.end(); it != delay_freqs.end(); it++)
	{
		if(it->second > maximum)
		{
			maximum = it->second;
			maxString = it->first;

		}

	}

	return maxString;
}

float GraphS::avgPercentDelayed(string corp)
{
	float num_delayed_flights = 0;
	float num_flights = 0;
	
	for(int j = 0; j < WIDTH; j++)
	{
	    float delay_time = 0;

		if(data[airports[corp]][j].date != -1)
		{
			delay_time += data[airports[corp]][j].carrier_delay;
		}

		if(data[airports[corp]][j].carrier_delay != -1)
		{
			delay_time += data[airports[corp]][j].carrier_delay;
		}
		if(data[airports[corp]][j].weather_delay != -1)
		{
			delay_time += data[airports[corp]][j].weather_delay;
		}
		if(data[airports[corp]][j].nas_delay != -1)
		{
			delay_time += data[airports[corp]][j].nas_delay;
		}
		if(data[airports[corp]][j].security_delay != -1)
		{
			delay_time += data[airports[corp]][j].security_delay;
		}
		if(data[airports[corp]][j].late_aircraft_delay != -1)
		{
			delay_time += data[airports[corp]][j].late_aircraft_delay;
		}
		
		if(delay_time !=0) 
		{
			total_delay += delay_time;
			num_delayed_flights++;
		}

	}
}


