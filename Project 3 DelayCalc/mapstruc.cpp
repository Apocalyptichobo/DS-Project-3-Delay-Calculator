#include "mapstruc.h"
#include <algorithm>
#include <queue>
using namespace std;

MapS::MapS()
{

}
MapS::MapS(int year, int h)
{
	string dataset;
	if (year == 2016 && h == 1) dataset = "Input/2016p1.csv";
	else if (year == 2016 && h == 2) dataset = "Input/2016p2.csv";
	else if (year == 2017 && h == 1) dataset = "Input/2017p1.csv";
	else if (year == 2017 && h == 2) dataset = "Input/2017p2.csv";
	else if (year == 2018 && h == 1) dataset = "Input/2018p1.csv";
	else if (year == 2018 && h == 2) dataset = "Input/air2018p_jan.csv";
	ifstream file;
	file.open(dataset, ios_base::in);
	bool first = true;
	string r, t, temp, num; //each row
	while (getline(file, r)) {
		if (first) {
			first = false;
			continue;
		}
		Flight f;
		stringstream ss(r);
		getline(ss, temp, ',');
		num = temp;
		getline(ss, temp, ',');//empty
		//getline(ss, temp, ',');
		//f.date = temp;
		getline(ss, temp, ',');
		f.carrier = temp;
		//ID.emplace(temp);
		//getline(ss, temp, ',');
		//f.flight_number = temp;
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
		f.taxi_out = stoi(temp);
		//getline(ss, temp, ',');
		//f.wheels_off = stoi(temp);
		//getline(ss, temp, ',');
		//f.wheels_on = stoi(temp);
		getline(ss, temp, ',');
		f.taxi_in = stoi(temp);
		//getline(ss, temp, ',');
		//f.crs_arr_time = stoi(temp);
		//getline(ss, temp, ',');
		//f.arr_time = stoi(temp);
		getline(ss, temp, ',');
		f.arr_delay = stoi(temp);
		getline(ss, temp, ',');
		f.cancelled = stoi(temp);
		//getline(ss, temp, ',');
		//f.cancel_code = temp;
		//getline(ss, temp, ',');
		//f.diverted = stoi(temp);
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
		//data.insert(stoi(name), f);
		data[num] = f;
	}
	file.close();
}
void MapS::Option1(string& input)
{
	//check to see if input is valid
	//Input a company (via company identification code) vf or DL (carrier)
	cout << "Average delay time for " << input << ": " << comAvgDelay(input) << endl;
	cout << "Most common delay issue for " << input << ": " << comDelayType(input) << endl;
	cout << "Percentage of flights delayed for " << input << ": " << comPerDelayed(input) << endl;
	cout << "Average travel time for " << input << ": " << comAvgTravelTime(input) <<endl;
	cout << "Number of planes launched by " << input << ": " << comNumLaunched(input) << endl;
	cout << "Number of planes delayed by " << input << ": " << comNumDelayed(input) << endl;
}
//done
void MapS::Option2(string& input, string& input2)
{
	//Input an arrival location and a departure location
	cout << "Average delay time between " << input <<  " and " << input2 << ": " << ADAvgDelay(input, input2) << endl;
	cout << "Most common delay issue between " << input << " and " << input2 << ": " << ADDelayType(input, input2) << endl;
	cout << "Percentage of flights delayed between " << input << " and " << input2 << ": %" << ADPerDelayed(input, input2) << endl;
	cout << "Average taxi-out time between " << input << " and " << input2 << ": " << avgTaxiTime(input, input2).first << endl;
	cout << "Average taxi-in time between " << input << " and " << input2 << ": " << avgTaxiTime(input, input2).second << endl;
	cout << "Number of planes launched between " << input << " and " << input2 << ": " << ADNumLaunched(input, input2) << endl;
	cout << "Number of planes delayed between " << input << " and " << input2 << ": " << ADNumDelayed(input, input2) << endl;
}
//done
void MapS::Option3(string& input)
{
	//Input an airport (via three letter identification code) Atlanta = ATL (origin)
	cout << "Average delay time at " << input << ": " << airAvgDelay(input) << endl;
	cout << "Most common delay issue at " << input << ": " << airDelayType(input) << endl;
	cout << "Most common airline flown at " << input << ": " << airCarrier(input) << endl;
	cout << "Percentage of flights delayed at " << input << ": %" << airPercentDelayed(input) << endl;
	cout << "Number of flights to " << input << ": " << airNumFlown(input).first << endl;
	cout << "Number of flights from " << input << ": " << airNumFlown(input).second << endl;
	cout << "Number of flights delayed at " << input << ": " << airNumDelayed(input) << endl;
	cout << "Average travel time at " << input << ": " << airAvgTravelTime(input) << endl;
}
//done
void MapS::Option4(string& input)
{
	vector<string> best, worst;
	//Input type of delay (from a given list of delays)
	cout << "Average delay time for " << input << "delay: " << avgDelay(input) << endl;
	//cout << "Bottom five airports with the highest delay time for " << input << "delay: ";
	/*worst = airportHighLow(input).first;
	for (int i = 0; i < 5; i++)
	{
		cout << worst[i] << " ";
	}
	cout << "Top five airports with the lowest delay time for " << input << "delay: ";
	best = airportHighLow(input).second;
	for (int i = 0; i < 5; i++)
	{
		cout << best[i] << " ";
	}*/
	cout << "Average travel time for " << input << "delay: " << avgTravelTime(input) << endl;
	//cout << "The best airport to go to avoid " << input << "delay: " << bestAirport(input) << endl;
}
//done
void MapS::Option5(string& input)
{
	//Input preferred departure time (example being 0800)
	cout << "Average delay time at " << input << "time: " << timeAvgDelay(input) << endl;
	cout << "Most common delay for " << input << "time: " << timeDelayType(input) << endl;
	cout << "Airport to fly out of with the least amount of delay time at " << input << "time: " << airportDelayTimes(input).first[0] << endl;
	cout << "Airport to not fly out of with most amount of delay time at " << input << "time: " << airportDelayTimes(input).second[0] << endl;
	cout << "Chance that your flight will be delayed at " << input << "time: %" << timePercentDelayed(input) << endl;
}
//done
//------------------------------------option 1------------------------------------------
int MapS::comAvgDelay(string& search)
{
	int avgDelayT = 0;
	int count = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.carrier == search)
		{
			avgDelayT += iter->second.dep_delay + iter->second.arr_delay;
			count++;
		}

	}
	return avgDelayT / count;
}
//done
string MapS::comDelayType(string& search)
{//most common delay type for company
	float cd = 0, wd = 0, nd = 0, sd = 0, lad = 0;
	vector<pair<float, string>> vect;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.carrier == search)
		{
			cd += iter->second.carrier_delay;
			wd += iter->second.weather_delay;
			nd += iter->second.nas_delay;
			sd += iter->second.security_delay;
			lad += iter->second.late_aircraft_delay;
		}
	}
	vect.push_back(make_pair(cd, "Carrier Delay"));
	vect.push_back(make_pair(wd, "Weather Delay"));
	vect.push_back(make_pair(nd, "nas Delay"));
	vect.push_back(make_pair(sd, "Security Delay"));
	vect.push_back(make_pair(lad, "Late Air Craft Delay"));
	//get largest value
	auto it = max_element(vect.begin(), vect.end());
	return it->second;
}
//done
float MapS::comPerDelayed(string& search)
{
	float total_flights = 0.0;
	float number_flights_delayed = 0.0;


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
//done
int MapS::comAvgTravelTime(string& search)
{
	int avgTimeT = 0;
	int count = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.carrier == search)
		{
			avgTimeT += iter->second.air_time;
			count++;
		}
	}
	return avgTimeT / count;
}
//done
int MapS::comNumLaunched(string& search)
{
	int flights = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.carrier == search)
		{
			flights++;
		}
	}
	return flights;
}
//done
int MapS::comNumDelayed(string& search)
{
	int number_flights_delayed = 0;
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
	}
	return number_flights_delayed;
}
//done
//------------------------------------option 2------------------------------------------
int MapS::ADAvgDelay(string& o, string& d)
{
	int avgDelayT = 0;
	int count = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.origin == o && iter->second.destination == d)
		{
			avgDelayT += iter->second.dep_delay + iter->second.arr_delay;
			count++;
		}

	}
	return avgDelayT / count;
}
//done
string MapS::ADDelayType(string& o, string& d)
{
	float cd = 0, wd = 0, nd = 0, sd = 0, lad = 0;
	vector<pair<float, string>> vect;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.origin == o && iter->second.destination == d)
		{
			cd += iter->second.carrier_delay;
			wd += iter->second.weather_delay;
			nd += iter->second.nas_delay;
			sd += iter->second.security_delay;
			lad += iter->second.late_aircraft_delay;
		}
	}
	vect.push_back(make_pair(cd, "Carrier Delay"));
	vect.push_back(make_pair(wd, "Weather Delay"));
	vect.push_back(make_pair(nd, "nas Delay"));
	vect.push_back(make_pair(sd, "Security Delay"));
	vect.push_back(make_pair(lad, "Late Air Craft Delay"));
	//get largest value
	auto it = max_element(vect.begin(), vect.end());
	return it->second;
}
//done
float MapS::ADPerDelayed(string& o, string& d)
{
	float total_flights = 0.0;
	float number_flights_delayed = 0.0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.origin == o && iter->second.destination == d)
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
//done
pair<int, int> MapS::avgTaxiTime(string& o, string& d)
{
	int out = 0, in = 0;
	int count = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.origin == o && iter->second.destination == d)
		{
			out += iter->second.taxi_out;
			in += iter->second.taxi_in;
			count++;
		}
	}
	return make_pair(in/count, out/count);
}
//done
int MapS::ADNumLaunched(string& o, string& d)
{
	int flights = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.origin == o && iter->second.destination == d)
		{
			flights++;
		}
	}
	return flights;
}
//done
int MapS::ADNumDelayed(string& o, string& d)
{
	int number_flights_delayed = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.origin == o && iter->second.destination == d)
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
	}
	return number_flights_delayed;
}
//done
//-----------------------------------option 3-------------------------------------------
float MapS::airAvgDelay(string& search) //average X's at airport. 
{
	//search is the 3letter ATL
	//this returns the average delay time at this specific airport
	float avgDelayT = 0;
	int count = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{//if the 3letter idcode matches the passed in value
		if (iter->second.origin == search) 
		{
			avgDelayT += iter->second.dep_delay + iter->second.arr_delay;
			count++;
		}
		
	}
	return avgDelayT /= count;
}
//done
string MapS::airDelayType(string& search)
{
	//find the most common type of delay
	vector< pair <float, string> > vect;
	float carrierC = 0, weatherC = 0, nasC = 0, securityC = 0, lateaircraftC = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.carrier_delay > 0) { carrierC++; }
		if (iter->second.weather_delay > 0) { weatherC++; }
		if (iter->second.nas_delay > 0) { nasC++; }
		if (iter->second.security_delay > 0) { securityC++; }
		if (iter->second.late_aircraft_delay > 0) { lateaircraftC++; }
	}
	vect.push_back(make_pair(carrierC,"Carrier Delay"));
	vect.push_back(make_pair(weatherC,"Weather Delay"));
	vect.push_back(make_pair(nasC,"nas Delay"));
	vect.push_back(make_pair(securityC,"Security Delay"));
	vect.push_back(make_pair(lateaircraftC,"Late Air Craft Delay"));
	//get largest value
	auto it = max_element(vect.begin(), vect.end());
	return it->second;
}
//done
float MapS::airPercentDelayed(string& search)
{
	float total_flights = 0.0;
	float number_flights_delayed = 0.0;


	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.origin == search)
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
//done
string MapS::airCarrier(string& search)
{
	//most common airline flown from given airport
	//search is the 3letter ATL
	map <string, int> freqs; 

	for (auto iter = data.begin(); iter != data.end(); iter++) 
	{
		if (iter->second.origin == search) //at the given airport
		{
			freqs[iter->second.carrier]++;
		}
	}
	int maximum = 0; 
	string maxString = "";
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
//done
int MapS::airAvgTravelTime(string& search)
{
	//average travel time at given airport
	//averages of all the air times
	int count = 0;
	int co = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++) 
	{
		if (iter->second.origin == search) 
		{
			//in the given airport now
			count += iter->second.air_time;
			co++;
		}
	}
	int avg = count / co;
	return avg;
}
//done
pair<int, int> MapS::airNumFlown(string& search)
{
	//flights to and from, in that order returned
	int flightsTO = 0, flightsFROM = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.origin == search)
		{
			flightsFROM++;
		}

		if (iter->second.destination == search)
		{
			flightsTO++;
		}
	}
	return make_pair(flightsTO, flightsFROM);
}
//done
int MapS::airNumDelayed(string& search)
{
	//number of planes delayed at given airport
	int number_flights_delayed = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.origin == search)
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
		
	}
	return number_flights_delayed;
}
//done
//-----------------------------------option 4-------------------------------------------
int MapS::avgDelay(string& search)
{
	//average delay time for given delay
	//Option 4 - delays
	// CARRIER
	// WEATHER
	// NAS
	// SECURITY
	// LATE_AIRCRAFT
	int delay = 0;
	int numflights = 0;

	for (auto iter = data.begin(); iter != data.end(); iter++) 
	{
		if (search == "CARRIER")
		{
			if (iter->second.carrier_delay != 0)
			{
				delay += iter->second.carrier_delay;
				numflights++;
			}
		}
		else if (search == "WEATHER")
		{
			if (iter->second.weather_delay != 0)
			{
				delay += iter->second.weather_delay;
				numflights++;
			}
		}
		else if (search == "NAS")
		{
			if (iter->second.nas_delay != 0)
			{
				delay += iter->second.nas_delay;
				numflights++;
			}
		}
		else if (search == "SECURITY")
		{
			if (iter->second.security_delay != 0)
			{
				delay += iter->second.security_delay;
				numflights++;
			}

		}
		else if (search == "LATE_AIRCRAFT")
		{
			if (iter->second.late_aircraft_delay != 0)
			{
				delay += iter->second.late_aircraft_delay;
				numflights++;
			}
		}
	}
	return delay / numflights;
}
//done
//pair<vector<string>, vector<string>> MapS::airportHighLow(string search) {}
//pair<vector<string>, vector<string>> MapS::airportHighLow(string search)
//{
//	/*pair of vectors that contain the 5 highest and lowest airport delay time
//	first vector will have the highest, second will have the lowest*/
//	//first vector will have 5 highest delay times as airports in order
//	//second vector will have 5 lowest delay times as airports in order
//	map<string, int > delay_times; //delay time, list of airports, sorted from lowest to highest
//	for (auto iter = data.begin(); iter != data.end(); iter++)
//	{
//		int a = iter->second.carrier_delay;
//		int b = iter->second.weather_delay;
//		int c = iter->second.nas_delay;
//		int d = iter->second.security_delay;
//		int e = iter->second.late_aircraft_delay;
//		int sum = a + b + c + d + e;
//
//		if (delay_times.count(iter->second.origin) == 0) { delay_times[iter->second.origin] = sum; }
//		else delay_times[iter->second.origin] += sum;
//
//	}
//	SortbyValue(delay_times, "Ascending");
//
//	vector<string> high;
//	int counter = 5;
//
//	for (auto it = delay_times.begin(); it != delay_times.end(); it++)
//	{
//		high.push_back(it->first);
//		counter--;
//		if (counter == 0) break;
//
//	}
//
//	SortbyValue(delay_times, "Descending");
//	vector<string> low;
//	int counter2 = 5;
//
//	for (auto it = delay_times.begin(); it != delay_times.end(); it++)
//	{
//		low.push_back(it->first);
//		counter2--;
//		if (counter == 0) break;
//
//	}
//	
//	pair <vector<string>, vector<string>> PAIR = make_pair(high, low);
//	return PAIR;
//}

int MapS::avgTravelTime(string& search)
{
	//average travel time for given delay
	int travelTime = 0;
	int numflights = 0;

	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (search == "CARRIER")
		{
			if (iter->second.carrier_delay != 0)
			{
				travelTime += iter->second.air_time;
				numflights++;
			}
		}
		else if (search == "WEATHER")
		{
			if (iter->second.weather_delay != 0)
			{
				travelTime += iter->second.air_time;
				numflights++;
			}
		}
		else if (search == "NAS")
		{
			if (iter->second.nas_delay != 0)
			{
				travelTime += iter->second.air_time;
				numflights++;
			}
		}
		else if (search == "SECURITY")
		{
			if (iter->second.security_delay != 0)
			{
				travelTime += iter->second.air_time;
				numflights++;
			}

		}
		else if (search == "LATE_AIRCRAFT")
		{
			if (iter->second.late_aircraft_delay != 0)
			{
				travelTime += iter->second.air_time;
				numflights++;
			}
		}
	}
	return travelTime/numflights;
}
//done
//string MapS::bestAirport(string search)
//{
//	//best airport to travel with given delay
//	//the best airport will have the lowest times for given delay
//	map<string, int > delay_times;
//	for (auto iter = data.begin(); iter != data.end(); iter++)
//	{
//		if (search == "CARRIER")
//		{
//			int a = iter->second.carrier_delay;
//			if (delay_times.count(iter->second.origin) == 0) { delay_times[iter->second.origin] = a; }
//			else delay_times[iter->second.origin] += a;
//
//		}
//		else if (search == "WEATHER")
//		{
//			int b = iter->second.weather_delay;
//			if (delay_times.count(iter->second.origin) == 0) { delay_times[iter->second.origin] = b; }
//			else delay_times[iter->second.origin] += b;
//		}
//		else if (search == "NAS")
//		{
//			int c = iter->second.nas_delay;
//			if (delay_times.count(iter->second.origin) == 0) { delay_times[iter->second.origin] = c; }
//			else delay_times[iter->second.origin] += c;
//		}
//		else if (search == "SECURITY")
//		{
//			int d = iter->second.security_delay;
//			if (delay_times.count(iter->second.origin) == 0) { delay_times[iter->second.origin] = d; }
//			else delay_times[iter->second.origin] += d;
//
//		}
//		else if (search == "LATE_AIRCRAFT")
//		{
//			int e = iter->second.security_delay;
//			if (delay_times.count(iter->second.origin) == 0) { delay_times[iter->second.origin] = e; }
//			else delay_times[iter->second.origin] += e;
//		}
//	}
//	SortbyValue(delay_times, "Descending");
//	string best = "";
//	for (auto it = delay_times.begin(); it != delay_times.end(); it++)
//	{
//		best = it->first;
//		break;
//	}
//	return best;
//}
//-----------------------------------option 5-------------------------------------------
int MapS::timeAvgDelay(string& time)
{//average delay time for given time, assuming user searches with 4 digits
	int search = stoi(time);
	int avgDelayT = 0;
	int count = 0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.crs_dept_time == search)
		{
			avgDelayT += iter->second.dep_delay + iter->second.arr_delay;
			count++;
		}

	}
	return avgDelayT / count;
}
//done
string MapS::timeDelayType(string& time)
{//find the most common type of delay for given time
	int search = stoi(time);
	float cd = 0, wd = 0, nd = 0, sd = 0, lad = 0;
	vector<pair<float, string>> vect;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.crs_dept_time == search)
		{
			cd += iter->second.carrier_delay;
			wd += iter->second.weather_delay;
			nd += iter->second.nas_delay;
			sd += iter->second.security_delay;
			lad += iter->second.late_aircraft_delay;
		}
	}
	vect.push_back(make_pair(cd, "Carrier Delay"));
	vect.push_back(make_pair(wd, "Weather Delay"));
	vect.push_back(make_pair(nd, "Nas Delay"));
	vect.push_back(make_pair(sd, "Security Delay"));
	vect.push_back(make_pair(lad, "Late Air Craft Delay"));
	//get largest value
	auto it = max_element(vect.begin(), vect.end());
	return it->second;
}
//done
pair<vector<string>, vector<string>> MapS::airportDelayTimes(string& time)
{//finds the airports with the best and worst delay time for the given time, first is best second is worst
	int search = stoi(time);
	map<int, vector<string>> airports; //delay time, list of airports, sorted from lowest to highest
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.crs_dept_time == search)
		{
			airports[iter->second.dep_delay + iter->second.arr_delay].push_back(iter->second.origin);
		}

	}
	return make_pair(airports.begin()->second, airports.end()->second);
}
//done
float MapS::timePercentDelayed(string& time)
{//percentage delayed at given time
	int search = stoi(time);
	float total_flights = 0.0;
	float number_flights_delayed = 0.0;
	for (auto iter = data.begin(); iter != data.end(); iter++)
	{
		if (iter->second.crs_dept_time == search)
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
//done