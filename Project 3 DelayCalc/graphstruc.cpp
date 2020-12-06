#include "graphstruc1.h"
#include "limits.h"
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

        data[airports[origin]][airports[destination]].push_back(f);

    }
    file.close();
}
void GraphS::Option1(string input) {
    // Input a company (via company identification code) vf or DL (carrier)
    cout << "Average delay time for X: " << endl;
    cout << "Most common delay issue for X: " << endl;
    cout << "Percentage of flights delayed for X: " << endl;
    cout << "Average travel time for X: " << endl;
    cout << "Number of planes launched by X: " << endl;
    cout << "Number of planes delayed by X: " << endl;
}
void GraphS::Option2(string input) {
    //Input an arrival location and a departure location
    cout << "Average delay time between X and Y: " << endl;
    cout << "Most common delay issue between X and Y: " << endl;
    cout << "Percentage of flights delayed between X and Y: " << endl;
    cout << "Average taxi-out time at airport X: " << endl;
    cout << "Average taxi-in time at airport Y: " << endl;
    cout << "Number of planes launched between X and Y: " << endl;
    cout << "Number of planes delayed between X and Y: " << endl;
}
void GraphS::Option3(string input) {
    //Input an airport (via three letter identification code) Atlanta = ATL (origin)
    string idCode;
    cin >> idCode;
    float avgDelayT = m.airAvgDelay(idCode);
    cout << "Average delay time at " << idCode << ": " << avgDelayT << endl;
    string comD = m.airDelayType(idCode);
    cout << "Most common delay issue at " << idCode << ": " << comD << endl;

    cout << "Most common airline flown at " << idCode << ": " <<<< endl;
    float perc = m.airPercentDelayed(idCode);
    cout << "Percentage of flights delayed at " << idCode << ": " << perc * 100 << "%" << endl;

    cout << "Number of flights to X: " << endl;
    cout << "Number of flights from X: " << endl;
}
void GraphS::Option4(string input) {
    //Input type of delay (from a given list of delays)
    cout << "Average delay time for X: " << endl;
    cout << "Top five airports with the highest delay time for X: " << endl;
    cout << "Bottom five airports with the lowest delay time for X: " << endl;
    cout << "Average travel time for X delay type: " << endl;
    cout << "The best airport to go to during this year to avoid delay type X is: " << endl;
}
void GraphS::Option5(string input) {
    //Input preferred departure time (example being 0800)
    cout << "Average delay time at X time: " << endl;
    cout << "Most common delay for X time: " << endl;
    cout << "Airport to fly out of with the least amount of delay time at X time: " << endl;
    cout << "Airport to not fly out of with most amount of delay time at X time: " << endl;
    cout << "Chance that your flight will be delayed at X time: " << endl;
}
string minMax(map<string, int> freqs, string null_display)
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

///////////////////////////////////           Option 3        //////////////////////////////////////////////////////////
float GraphS::avgDelayTime(string& corp)
{
    float num_delayed_flights = 0;
    float total_delay = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < data[airports[corp]][i].size(); i++)
        {
			float dept = (float)data[airports[corp]][i][j].dep_delay;
			float arr = (float)data[airports[corp]][i][j].arr_delay;

            total_delay = dept + arr;
        }
    }

    return total_delay / num_delayed_flights;
}


string GraphS::commonDelay(string& corp)
{
    map<string, int> delay_freqs;

    for (int i = 0; i < WIDTH; i++)
    {

        for (int j = 0; j < data[airports[corp]][i].size(); j++)
        {

            if (data[airports[corp]][i][j].carrier_delay != 0) {
                delay_freqs["Carrier Delay"] = delay_freqs.count("Carrier Delay") + 1;
            }
            if (data[airports[corp]][i][j].weather_delay != 0) {
                delay_freqs["Weather Delay"] = delay_freqs.count("Weather Delay") + 1;
            }
            if (data[airports[corp]][i][j].nas_delay != 0) {
                delay_freqs["nas Delay"] = delay_freqs.count("nas Delay") + 1;
            }
            if (data[airports[corp]][i][j].security_delay != 0) {
                delay_freqs["Security Delay"] = delay_freqs.count("Security Delay") + 1;
            }
            if (data[airports[corp]][i][j].late_aircraft_delay != 0) {
                delay_freqs["Late Air Craft Delay"] = delay_freqs.count("Late Air Craft Delay") + 1;
            }
        }

    }

	return minMax(delay_freqs, "No Common Delay");
}

string GraphS::commonAirline(string& corp)
{
    map<string, int> comp_freqs;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < data[airports[corp]][i].size(); j++)
        {
            comp_freqs[data[airports[corp]][i][j].carrier] = comp_freqs.count(data[airports[corp]][i][j].carrier) + 1;
        }

    }
    return minMax(comp_freqs, "No Common Airline");
}

float GraphS::airPercentDelayed(string& corp) {
    float num_delayed_flights = 0;
    float num_flights = 0;

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < data[airports[corp]][i].size(); j++)
        {
            if (data[airports[corp]][i][j].date != 0) {
                num_flights++;
            }
            else continue;

            if (data[airports[corp]][i][j].carrier_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].weather_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].nas_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].security_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].late_aircraft_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
        }
    }
    float pct = num_delayed_flights / num_flights;
    return pct;
}

int GraphS::toX(string& corp)
{
    int num_flights = 0;
    for (int j = 0; j < WIDTH; j++)
    {
        for (int i = 0; i < data[j][airports[corp]].size(); j++)
        {
            if (data[j][airports[corp]][i].date != 0)
            {
                num_flights++;
            }
            else continue;
        }
    }

}

int GraphS::fromX(string& corp)
{
    int num_flights = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < data[airports[corp]][i].size(); j++)
        {
            if (data[airports[corp]][i][j].date != 0)
            {
                num_flights++;
            }
            else continue;
        }
    }

    return num_flights;
}

/////////////////////////////              Option 2            //////////////////////////////////////////////////////

float GraphS::avgDelayTimeXY(string& corp1, string& corp2)
{
    float num_flights = data[airports[corp1]][airports[corp2]].size();
    float delay_time = 0;

    for (int i = 0; i < data[airports[corp1]][airports[corp2]].size(); i++)
    {
        
        float dept = (float)data[airports[corp1]][airports[corp2]][i].dep_delay;
        float arr = (float)data[airports[corp1]][airports[corp2]][i].arr_delay;

        delay_time = delay_time + dept + arr;
    }

    return delay_time / num_flights;
}

string GraphS::commonDelayXY(string& corp1, string& corp2)
{
    map<string, int> delay_freqs;
    for (int i = 0; i < data[airports[corp1]][airports[corp2]].size(); i++)
    {
        if (data[airports[corp1]][airports[corp2]][i].carrier_delay != 0) {
            delay_freqs["Carrier Delay"] = delay_freqs.count("Carrier Delay") + 1;
        }
        if (data[airports[corp1]][airports[corp2]][i].weather_delay != 0) {
            delay_freqs["Weather Delay"] = delay_freqs.count("Weather Delay") + 1;
        }
        if (data[airports[corp1]][airports[corp2]][i].nas_delay != 0) {
            delay_freqs["nas Delay"] = delay_freqs.count("nas Delay") + 1;
        }
        if (data[airports[corp1]][airports[corp2]][i].security_delay != 0) {
            delay_freqs["Security Delay"] = delay_freqs.count("Security Delay") + 1;
        }
        if (data[airports[corp1]][airports[corp2]][i].late_aircraft_delay != 0) {
            delay_freqs["Late Air Craft Delay"] = delay_freqs.count("Late Air Craft Delay") + 1;
        }
    }

    return minMax(delay_freqs, "No Common Delay");
}

float GraphS::airPercentDelayedXY(string& corp1, string& corp2)
{
    float num_delayed_flights = 0;
    float num_flights = (float)data[airports[corp1]][airports[corp2]].size();

    for (int i = 0; i < data[airports[corp1]][airports[corp2]].size(); i++)
    {

        if (data[airports[corp1]][airports[corp2]][i].date != 0) {
            num_flights++;
        }
        else continue;

        if (data[airports[corp1]][airports[corp2]][i].carrier_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].weather_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].nas_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].security_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].late_aircraft_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }

    }

    float pct = num_delayed_flights / num_flights;
    return pct;
}

float GraphS::avgTaxiOutTime(string& corp) {
    float num_flights = 0;
    float total_taxi_time = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < data[airports[corp]][i].size(); i++)
        {
            if (data[airports[corp]][i][j].date != 0)
            {
                num_flights++;
            }
            else continue;
            total_taxi_time += (float)data[airports[corp]][i][j].taxi_out;

        }
    }
    return total_taxi_time / num_flights;
}

int GraphS::noPlanesFlown(string& corp1, string& corp2) {

    return data[airports[corp1]][airports[corp2]].size();
}

int GraphS::noPlanesDelayed(string& corp1, string& corp2) {

    int num_delayed_flights = 0;
    for (int i = 0; i < data[airports[corp1]][airports[corp2]].size(); i++)
    {
        if (data[airports[corp1]][airports[corp2]][i].carrier_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].weather_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].nas_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].security_delay != 0) {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].late_aircraft_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }

    }
    return num_delayed_flights;
}

////////////////////////////          Option 1  (Cubic functions)              //////////////////////////////////////////

int GraphS::noPlanesDelayed(string& corp)
{
    int num_delayed_flights = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < data[airports[corp]][i].size(); j++) {

            if (data[airports[corp]][i][j].carrier_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].weather_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].nas_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].security_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].late_aircraft_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
        }

    }
    return num_delayed_flights;
}

float GraphS::avgDelayTimeCorp(string& corp)
{
    float num_flights = 0;
    float delay_time = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].carrier == corp)
                {
                    num_flights++;

                    float dept = (float)data[i][j][k].dep_delay;
                    float arr = (float)data[i][j][k].arr_delay;

                    delay_time = delay_time + dept + arr;
                }
                else continue;
            }
        }
    }
    return delay_time / num_flights;
}

string GraphS::commonDelayCorp(string& corp)
{
    map<string, int> delay_freqs;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].carrier == corp)
                {
                    if (data[i][j][k].carrier_delay != 0) 
					{
						delay_freqs["Carrier Delay"] = delay_freqs.count("Carrier Delay") + 1;
					 }
					if (data[i][j][k].weather_delay != 0) 
					{
						delay_freqs["Weather Delay"] = delay_freqs.count("Weather Delay") + 1;
					}
					if (data[i][j][k].nas_delay != 0) 
					{
						delay_freqs["nas Delay"] = delay_freqs.count("nas Delay") + 1;
					}
					if (data[i][j][k].security_delay != 0) 
					{
						 delay_freqs["Security Delay"] = delay_freqs.count("Security Delay") + 1;
					}
					if (data[i][j][k].late_aircraft_delay != -1) 
					{
						delay_freqs["Late Air Craft Delay"] = delay_freqs.count("Late Air Craft Delay") + 1;
					}
                }
                else continue;
            }
        }
    }

    return minMax(delay_freqs, "No Common Delays");
}

float GraphS::airPercentDelayedCorp(string& corp)
{

	float num_delayed_flights = 0;
    float num_flights = 0;

	for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].carrier == corp)
                {
					num_flights++;

					if(data[i][j][k].carrier_delay != 0)
                    {
                        num_delayed_flights++;
						continue;
					}
					if(data[i][j][k].weather_delay != 0)
                    {
                        num_delayed_flights++;
						continue;
					}
					if(data[i][j][k].nas_delay != 0)
                    {
                        num_delayed_flights++;
						continue;
					}
					if(data[i][j][k].security_delay != 0)
                    {
                        num_delayed_flights++;
						continue;
					}
					if(data[i][j][k].late_aircraft_delay != 0)
                    {
                        num_delayed_flights++;
						continue;
					}
                  
                }
                else continue;
            }
        }
    }
    return num_delayed_flights / num_flights;
}

float GraphS::avgTravelTime(string& corp)
{
    float num_flights = 0;
    float travel_time = 0;

	for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (int k = 0; k < data[i][j].size(); k++)
            {
                num_flights++;

                travel_time += data[i][j][k].air_time;

            }
        }
    }
    return travel_time/num_flights;
}

int GraphS::noPlanesFlownCorp(string& corp)
{
	int num_flights = 0;

	for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (int k = 0; k < data[i][j].size(); k++)
            {
                num_flights++;
            }
        }
    }
    return num_flights;

}

int GraphS::noPlanesDelayedCorp(string& corp)
{
	float num_delayed_flights = 0;

	for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].carrier == corp)
                {

					if(data[i][j][k].carrier_delay != 0)
                    {
                        num_delayed_flights++;
						continue;
					}
					if(data[i][j][k].weather_delay != 0)
                    {
                        num_delayed_flights++;
						continue;
					}
					if(data[i][j][k].nas_delay != 0)
                    {
                        num_delayed_flights++;
						continue;
					}
					if(data[i][j][k].security_delay != 0)
                    {
                        num_delayed_flights++;
						continue;
					}
					if(data[i][j][k].late_aircraft_delay != 0)
                    {
                        num_delayed_flights++;
						continue;
					}
                  
                }
                else continue;
            }
        }
    }
    return num_delayed_flights;
}

float GraphS::avgDelayTimeWhenDelayed(string& delayType)
{
    float num_flights = 0;
    float delay_time = 0;
	
	for(int i = 0; i < WIDTH; i++)
    {
		for(int j = 0; j < WIDTH; j++)
        {
			for(int k = 0; k < data[i][j].size(); k++)
            {

				if(delayType == "CARRIER")
				{
					if(data[i][j][k].carrier_delay != 0)
                    {
						delay_time += data[i][j][k].carrier_delay;
						num_flights++;
					}
				}
                else if(delayType == "WEATHER")
				{
					if(data[i][j][k].weather_delay != 0)
                    {
						delay_time += data[i][j][k].weather_delay;
						num_flights++;
					}
				}
				else if(delayType == "NAS")
				{
					if(data[i][j][k].nas_delay != 0)
                    {
						delay_time += data[i][j][k].nas_delay;
						num_flights++;
					}
				}
                else if(delayType == "SECURITY")
				{
					if(data[i][j][k].security_delay != 0)
                    {
						delay_time += data[i][j][k].security_delay;
						num_flights++;
					}
				}
                else if(delayType == "LATE_AIRCRAFT")
				{
					if(data[i][j][k].carrier_delay != 0)
                    {
						delay_time += data[i][j][k].late_aircraft_delay;
						num_flights++;
					}
				}
			}
		}
	}
		
    return delay_time / num_flights;
} 

vector<string>GraphS::topForDelays(string& delayType, int how_many)
{
	
    map<int, vector<string>, greater<int>> locations;


	for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (int k = 0; k < data[i][j].size(); k++)
            {
               
				if(delayType == "CARRIER")
				{
					if(data[i][j][k].carrier_delay != 0)
                    {
                        locations[data[i][j][k].carrier_delay].push_back(data[i][j][k].carrier);
					}
				}
                else if(delayType == "WEATHER")
				{
					if(data[i][j][k].weather_delay != 0)
                    {
						locations[data[i][j][k].weather_delay].push_back(data[i][j][k].carrier);
					}
				}
				else if(delayType == "NAS")
				{
					if(data[i][j][k].nas_delay != 0)
                    {
						locations[data[i][j][k].nas_delay].push_back(data[i][j][k].carrier);
					}
				}
                else if(delayType == "SECURITY")
				{
					if(data[i][j][k].security_delay != 0)
                    {
						locations[data[i][j][k].security_delay].push_back(data[i][j][k].carrier);
					}
				}
                else if(delayType == "LATE_AIRCRAFT")
				{
					if(data[i][j][k].carrier_delay != 0)
                    {
						locations[data[i][j][k].late_aircraft_delay].push_back(data[i][j][k].carrier);
					}
				}

            }
        }
    }

    vector<string> five;
    int counter = how_many;

	for(auto it = locations.begin(); it != locations.end(); it++)
	{
		for(int i = 0; i < it->second.size(); i++)
        {
            five.push_back(it->second[i]);
            counter--;
            if (counter == 0) return five;
		}

	}

}

vector<string>GraphS::bottomForDelays(string& delayType, int how_many)
{
	
    map<int, vector<string>> locations;


	for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (int k = 0; k < data[i][j].size(); k++)
            {
               
				if(delayType == "CARRIER")
				{
					if(data[i][j][k].carrier_delay != 0)
                    {
                        locations[data[i][j][k].carrier_delay].push_back(data[i][j][k].carrier);
					}
				}
                else if(delayType == "WEATHER")
				{
					if(data[i][j][k].weather_delay != 0)
                    {
						locations[data[i][j][k].weather_delay].push_back(data[i][j][k].carrier);
					}
				}
				else if(delayType == "NAS")
				{
					if(data[i][j][k].nas_delay != 0)
                    {
						locations[data[i][j][k].nas_delay].push_back(data[i][j][k].carrier);
					}
				}
                else if(delayType == "SECURITY")
				{
					if(data[i][j][k].security_delay != 0)
                    {
						locations[data[i][j][k].security_delay].push_back(data[i][j][k].carrier);
					}
				}
                else if(delayType == "LATE_AIRCRAFT")
				{
					if(data[i][j][k].carrier_delay != 0)
                    {
						locations[data[i][j][k].late_aircraft_delay].push_back(data[i][j][k].carrier);
					}
				}

            }
        }
    }

    vector<string> five;
    int counter = how_many;

	for(auto it = locations.begin(); it != locations.end(); it++)
	{
		for(int i = 0; i < it->second.size(); i++)
        {
            five.push_back(it->second[i]);
            counter--;
            if (counter == 0) return five;
		}

	}

}








float avgTravelTimeWhenDelayed(string& delayType)
{

    float num_flights = 0;
    float travel_time = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (int k = 0; k < data[i][j].size(); k++)
            {

                if (delayType == "CARRIER")
                {
                    if (data[i][j][k].carrier_delay != 0)
                    {
                        travel_time += data[i][j][k].air_time;
                        num_flights++;
                    }
                }
                else if (delayType == "WEATHER")
                {
                    if (data[i][j][k].weather_delay != 0)
                    {
                        travel_time += data[i][j][k].air_time;
                        num_flights++;
                    }
                }
                else if (delayType == "NAS")
                {
                    if (data[i][j][k].nas_delay != 0)
                    {
                        travel_time += data[i][j][k].air_time;
                        num_flights++;
                    }
                }
                else if (delayType == "SECURITY")
                {
                    if (data[i][j][k].security_delay != 0)
                    {
                        travel_time += data[i][j][k].air_time;
                        num_flights++;
                    }
                }
                else if (delayType == "LATE_AIRCRAFT")
                {
                    if (data[i][j][k].carrier_delay != 0)
                    {
                        travel_time += data[i][j][k].air_time;
                        num_flights++;
                    }
                }
            }
        }
    }

		
    return travel_time/num_flights;
}
////////////////////							Option 5                   ////////////////////////////////////////
float GraphS::averageDelayTimeDay(int time_of_day)
{
	float num_flights = 0;
    float delay_time = 0;
	
	for(int i = 0; i < WIDTH; i++)
    {
		for(int j = 0; j < WIDTH; j++)
        {
			for(int k = 0; k < data[i][j].size(); k++)
            {
                
                if (data[i][j][k].dept_time == time_of_day)
                {
                    delay_time += data[i][j][k].dep_delay;
                    num_flights++;
                }
			}
		}
	}	
    return delay_time/num_flights;
}

string GraphS::commonDelayDay(int time_of_day)
{
    map<string, int> delay_freqs;

	for(int i=0; i < WIDTH; i++)
    {
		for(int j = 0; j < WIDTH; j++)
        {

			for(int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].dept_time == time_of_day)
                {
					if(data[i][j][k].carrier_delay != 0)
                    {
                        delay_freqs["Carrier Delay"] = delay_freqs.count("Carrier Delay") + 1;
					}
                    else if(data[i][j][k].carrier_delay != 0)
                    {
                        delay_freqs["Weather Delay"] = delay_freqs.count("Weather Delay") + 1;
					}
                    else if(data[i][j][k].carrier_delay != 0)
                    {
                        delay_freqs["nas Delay"] = delay_freqs.count("nas Delay") + 1;
					}
                    else if(data[i][j][k].security_delay != 0)
                    {
                        delay_freqs["Security Delay"] = delay_freqs.count("Security Delay") + 1;
					}
                    else if(data[i][j][k].late_aircraft_delay != 0)
                    {
                        delay_freqs["Late Aircraft Delay"] = delay_freqs.count("Late Aircraft Delay") + 1;
					}

                }

			}
		}
	}

	int maximum = 0;
    string maxString = "";
    for (auto it = delay_freqs.end(); it != delay_freqs.end(); it++)
    {
        if (it->second > maximum)
        {
            maximum = it->second;
            maxString = it->first;

        }

    }

    return maxString;
}

string GraphS::leastMostDelayDay(int time_of_day, int least_or_most)
{
	//least = 0, most = 1
    
	map<string,int> time_per_port;
    
	for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].dept_time == time_of_day)
                {
					if(time_per_port.count(data[i][j][k].carrier) == 0)
						time_per_port[data[i][j][k].carrier] = data[i][j][k].dep_delay;
                    else time_per_port[data[i][j][k].carrier] += data[i][j][k].dep_delay;
						
				}
                
            }
        }
    }

    if (least_or_most = 0)
    {
        int minimum = 2147483647;
        string maxString = "No best airport";
        for (auto it = time_per_port.end(); it != time_per_port.end(); it++)
        {
            if (it->second < minimum)
            {
                minimum = it->second;
                maxString = it->first;

            }

        }
        return maxString;
    }
    else
    {
        int maximum = 0;
        string maxString = "No worst airport";
        for (auto it = time_per_port.end(); it != time_per_port.end(); it++)
        {
            if (it->second > maximum)
            {
                maximum = it->second;
                maxString = it->first;

            }

        }
        return maxString;
    }

}

float GraphS::probDelayDay(int time_of_day) {
    float num_flights = 0;
    float flights_delayed = 0;

	for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (int k = 0; k < data[i][j].size(); k++)
            {
				bool lower_bound = data[i][j][k].dept_time >= (time_of_day - 5) % 2400;
				bool upper_bound = data[i][j][k].dept_time <= (time_of_day + 5) % 2400;
                if (upper_bound && lower_bound)
                {
                    num_flights++;
				    if(data[i][j][k].carrier_delay != 0)
                    {
                        flights_delayed++;
                        continue;
					}
					else if(data[i][j][k].weather_delay != 0)
                    {
                        flights_delayed++;
                        continue;
					}
					else if(data[i][j][k].nas_delay != 0)
                    {
                        flights_delayed++;
                        continue;
					}
                    else if(data[i][j][k].security_delay != 0)
                    {
                        flights_delayed++;
                        continue;
					}
                    else if(data[i][j][k].late_aircraft_delay != 0)
                    {
                        flights_delayed++;
                        continue;
					}
            }
        }
    }
    return flights_delayed / num_flights;
}












