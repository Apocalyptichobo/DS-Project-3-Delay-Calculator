#include "graphstruc1.h"
GraphS::GraphS()
{
    airports.clear();
    data = new vector<GFlight>* [WIDTH];
    for(int i = 0; i < WIDTH; i ++)
    {
        data[i]= new vector<GFlight>[WIDTH];
    }
}

void GraphS::copy(const GraphS &other) {
    airports = other.airports;

    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j <WIDTH; j++)
        {
            for(unsigned int k = 0; k < data[i][j].size(); k++)
            {
                data[i][j][k] = other.data[i][j][k];
            }

        }

    }

}

GraphS::GraphS(const GraphS &other) {
    copy(other);
}

GraphS &GraphS::operator=(const GraphS &other) {
    copy(other);
    return *this;
}

GraphS::~GraphS()
{
    for(int i = 0; i < WIDTH; i++)
    {
        delete[] data[i];

    }
    delete[] data;
}

void GraphS::readData(string d)
{
    int airport_id = 0;
    ifstream file;
    file.open(d, ios_base::in);
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
        f.carrier = temp;		//carrier
        carrier[temp];
        getline(ss, temp, ',');
        origin = temp;
        f.origin = origin;
        if (airports.count(origin) == 0)
        {
            airports[origin] = airport_id;
            airport_id++;
        }

        getline(ss, temp, ',');
        destination = temp;
        f.destination = destination;
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
        f.taxi_out = stoi(temp);
        getline(ss, temp, ',');
        f.taxi_in = stoi(temp);
        getline(ss, temp, ',');
        f.arr_delay = stoi(temp);
        getline(ss, temp, ',');
        f.cancelled = stoi(temp);
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
void GraphS::Option1(string& input) {
    // Input a company (via company identification code) vf or DL (carrier)
    cout << "Average delay time for " << input << ": " << comAvgDelay(input) << " minutes" << endl;
    cout << "Most common delay issue for " << input << ": " << comDelayType(input) << endl;
    cout << "Average travel time for " << input << ": " << comAvgTravelTime(input) << " minutes" << endl;
    cout << "Number of planes delayed by " << input << ": " << comNumDelayed(input) << endl;
    cout << "Number of planes launched by " << input << ": " << comNumLaunched(input) << endl;
    cout << "Percentage of flights delayed for " << input << ": " << comPerDelayed(input) * 100 << "%" << endl;

}
void GraphS::Option2(string& input, string& input2) {
    //Input an arrival location and a departure location
    if (data[airports[input]][airports[input2]].size() != 0)
    {
        cout << "Average delay time between " << input << " and " << input2 << ": " << ADAvgDelay(input, input2) << " minutes" << endl;
        cout << "Most common delay issue between " << input << " and " << input2 << ": " << ADDelayType(input, input2) << endl;
        cout << "Average taxi-out time between " << input << " and " << input2 << ": " << avgTaxiTime(input, input2).first << " minutes" << endl;
        cout << "Average taxi-in time between " << input << " and " << input2 << ": " << avgTaxiTime(input, input2).second << " minutes" << endl;
        cout << "Number of planes delayed from " << input << " to " << input2 << ": " << ADNumDelayed(input, input2) << endl;
        cout << "Number of planes launched from " << input << " to " << input2 << ": " << ADNumLaunched(input, input2) << endl;
        cout << "Percentage of flights delayed between " << input << " and " << input2 << ": " << ADPerDelayed(input, input2) * 100 << "%" << endl;
    }
	else
	{
		cout << "Error! No flight exists between these two airports!" << endl; 
        return;
	}
}
void GraphS::Option3(string& input) {
    //Input an airport (via three letter identification code) Atlanta = ATL (origin)
    cout << "Average delay time at " << input << ": " << airAvgDelay(input) << " minutes" << endl;
    cout << "Most common delay issue at " << input << ": " << airDelayType(input) << endl;
    cout << "Most common airline flown at " << input << ": " << airCarrier(input) << endl;
    cout << "Average travel time at " << input << ": " << airAvgTravelTime(input) << " minutes" << endl;
    cout << "Number of flights to " << input << ": " << airNumFlownTo(input) << endl;
    cout << "Number of flights from " << input << ": " << airNumFlownFrom(input) << endl;
    cout << "Number of flights delayed at " << input << ": " << airNumDelayed(input) << endl;
    cout << "Percentage of flights delayed at " << input << ": " << airPercentDelayed(input) * 100 << "%" << endl;
}
void GraphS::Option4(string& input) {
    //Input type of delay (from a given list of delays)
    cout << "Average delay time for " << input << " delay: " << avgDelay(input) << " minutes" << endl;
    cout << "Average travel time for " << input << " delay: " << avgTravelTime(input) << " minutes" << endl;
}
void GraphS::Option5(string& input) {
    //Input preferred departure time (example being 0800)
    int time = stoi(input);
    cout << "Average delay time at " << input << " time: " << timeAvgDelay(time) << " minutes" << endl;
    cout << "Most common delay for " << input << " time: " << timeDelayType(time) << endl;
    cout << "Airport to fly out of with the least amount of delay time at " << input << " time: " << airportDelayTimes(time).first[0] << endl;
    cout << "Airport to not fly out of with most amount of delay time at " << input << " time: " << airportDelayTimes(time).second[0] << endl;
    cout << "Chance that your flight will be delayed at " << input << " time: " << timePercentDelayed(time) * 100 << "%" << endl;
}
////////////////////////////////////                            Option 1  (Cubic functions)						 ////////////////////////////////////////////////////////////////
int GraphS::comAvgDelay(string& corp)
{
    int num_flights = 0;
    int delay_time = 0;

    for (unsigned int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].carrier == corp)
                {
                    num_flights++;
                    delay_time += data[i][j][k].dep_delay + data[i][j][k].arr_delay;
                }
                else continue;
            }
        }
    }
    return delay_time / num_flights;
}

string GraphS::comDelayType(string& corp)
{
   map<string, int> delay_freqs;

    int cd = 0, wd = 0, nd = 0, sd = 0, lad = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].carrier == corp)
                {
                    if (data[i][j][k].carrier_delay != 0)
                    {
                        delay_freqs["Carrier Delay"] = cd++;

                    }
                    if (data[i][j][k].weather_delay != 0)
                    {
                        delay_freqs["Weather Delay"] = wd++;

                    }
                    if (data[i][j][k].nas_delay != 0)
                    {
                        delay_freqs["Nas Delay"] = nd++;

                    }
                    if (data[i][j][k].security_delay != 0)
                    {
                        delay_freqs["Security Delay"] = sd++;

                    }
                    if (data[i][j][k].late_aircraft_delay != 0)
                    {
                        delay_freqs["Late Air Craft Delay"] = lad++;

                    }

                }
                else continue;
            }
        }
    }

    return max_string(delay_freqs, "No Common Delays");
}

float GraphS::comPerDelayed(string& corp)
{

    float num_delayed_flights = comNumDelayed(corp);
    float num_flights = comNumLaunched(corp);

    return num_delayed_flights / num_flights;
}

int GraphS::comAvgTravelTime(string& corp)
{
    int num_flights = 0;
    int travel_time = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].carrier == corp) 
				{
                    num_flights++;
                    travel_time += data[i][j][k].air_time;
                }
            }
        }
    }
    return travel_time / num_flights;
}

int GraphS::comNumLaunched(string& corp)
{
    int num_flights = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
            {
				if(data[i][j][k].carrier == corp)
				{
					num_flights++;
				}
            }
        }
    }

    return num_flights;

}

int GraphS::comNumDelayed(string& corp)
{
    int num_delayed_flights = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if(data[i][j][k].carrier == corp)
                {
					if(data[i][j][k].carrier_delay != 0)
                    {
                        num_delayed_flights++;
					}
					else if(data[i][j][k].weather_delay != 0)
                    {
						num_delayed_flights++;
					}
					else if(data[i][j][k].nas_delay != 0)
                    {
						num_delayed_flights++;
					}
					else if(data[i][j][k].security_delay != 0)
                    {
						num_delayed_flights++;
					}
                    else if(data[i][j][k].late_aircraft_delay != 0)
                    {
						num_delayed_flights++;
					}

				}

            }
        }
    }
    return num_delayed_flights;
}
/////////////////////////////							Option 2								//////////////////////////////////////////////////////
int GraphS::ADAvgDelay(string& airpt1, string& airpt2)
{
    int num_flights = data[airports[airpt1]][airports[airpt2]].size();
    int delay_time = 0;

    for (unsigned int i = 0; i < data[airports[airpt1]][airports[airpt2]].size(); i++)
    {

        int dept = data[airports[airpt1]][airports[airpt2]][i].dep_delay;
        int arr = data[airports[airpt1]][airports[airpt2]][i].arr_delay;

        delay_time = delay_time + dept + arr;
    }

    return delay_time / num_flights;
}

string GraphS::ADDelayType(string& airpt1, string& airpt2)
{
    map<string, int> delay_freqs;
    int cd = 1, wd = 1, nd = 1, sd = 1, lad = 1;
    for (unsigned int i = 0; i < data[airports[airpt1]][airports[airpt2]].size(); i++)
    {

        if (data[airports[airpt1]][airports[airpt2]][i].carrier_delay != 0)
        {
            delay_freqs["Carrier Delay"] = cd++;

        }
        if (data[airports[airpt1]][airports[airpt2]][i].weather_delay != 0)
        {
            delay_freqs["Weather Delay"] = wd++;

        }
        if (data[airports[airpt1]][airports[airpt2]][i].nas_delay != 0)
        {
            delay_freqs["Nas Delay"] = nd++;

        }
        if (data[airports[airpt1]][airports[airpt2]][i].security_delay != 0)
        {
            delay_freqs["Security Delay"] = sd++;

        }
        if (data[airports[airpt1]][airports[airpt2]][i].late_aircraft_delay != 0)
        {
            delay_freqs["Late Air Craft Delay"] = lad++;

        }
    }

    return max_string(delay_freqs, "No Common Delay");
}

float GraphS::ADPerDelayed(string& airpt1, string& airpt2)
{
    float num_delayed_flights = 0;
    float num_flights = (float)data[airports[airpt1]][airports[airpt2]].size();

    for (unsigned int i = 0; i < data[airports[airpt1]][airports[airpt2]].size(); i++)
    {
        if (data[airports[airpt1]][airports[airpt2]][i].carrier_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[airpt1]][airports[airpt2]][i].weather_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[airpt1]][airports[airpt2]][i].nas_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[airpt1]][airports[airpt2]][i].security_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[airpt1]][airports[airpt2]][i].late_aircraft_delay != 0)
        {
            num_delayed_flights++;
            continue;
        }

    }

    float pct = num_delayed_flights / num_flights;
    return pct;
}

pair<int, int> GraphS::avgTaxiTime(string& airpt1, string& airpt2) {
    int num_flights = 0;
    int in = 0, out = 0;

    for (unsigned int i = 0; i < data[airports[airpt1]][airports[airpt2]].size(); i++)
    {
        in += data[airports[airpt1]][airports[airpt2]][i].taxi_in;
        out += data[airports[airpt1]][airports[airpt2]][i].taxi_out;

        num_flights++;
    }

    return make_pair(in / num_flights, out / num_flights);
}

int GraphS::ADNumLaunched(string& airpt1, string& airpt2) {

    return data[airports[airpt1]][airports[airpt2]].size();
}

int GraphS::ADNumDelayed(string& airpt1, string& airpt2) {

    int num_delayed_flights = 0;
    for (unsigned int i = 0; i < data[airports[airpt1]][airports[airpt2]].size(); i++)
    {
			if (data[airports[airpt1]][airports[airpt2]][i].carrier_delay != 0)
			{
				num_delayed_flights++;
				continue;
			}
			else if (data[airports[airpt1]][airports[airpt2]][i].weather_delay != 0)
			{
				num_delayed_flights++;
				continue;
			}
			else if (data[airports[airpt1]][airports[airpt2]][i].nas_delay != 0)
			{
				num_delayed_flights++;
				continue;
			}
			else if (data[airports[airpt1]][airports[airpt2]][i].security_delay != 0)
			{
				num_delayed_flights++;
				continue;
			}
			else if (data[airports[airpt1]][airports[airpt2]][i].late_aircraft_delay != 0)
			{
				num_delayed_flights++;
				continue;
			}

    }
    return num_delayed_flights;
}
///////////////////////////////////           Option 3        //////////////////////////////////////////////////////////
int GraphS::airAvgDelay(string& airpt)
{
    int num_flights = 0;
    int delay_time = 0;

    for (unsigned int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].origin == airpt)
                {
                    num_flights++;
                    delay_time += data[i][j][k].dep_delay + data[i][j][k].arr_delay;
                }
                else continue;
            }
        }
    }
    return delay_time / num_flights;
}

string GraphS::airDelayType(string& airpt)
{
    map<string, int> delay_freqs;
    int cd = 1, wd = 1, nd = 1, sd = 1, lad = 1;

    for (int i = 0; i < WIDTH; i++)
    {

        for (unsigned int j = 0; j < data[airports[airpt]][i].size(); j++)
        {
            if(data[airports[airpt]][i][j].carrier_delay != 0)
            {
                delay_freqs["Carrier Delay"] = cd++;

            }
            if(data[airports[airpt]][i][j].weather_delay != 0)
            {
                delay_freqs["Weather Delay"] = wd++;

            }
            if(data[airports[airpt]][i][j].nas_delay != 0)
            {
                delay_freqs["Nas Delay"] = nd++;

            }
            if(data[airports[airpt]][i][j].security_delay != 0)
            {
                delay_freqs["Security Delay"] = sd++;

            }
            if(data[airports[airpt]][i][j].late_aircraft_delay != 0)
            {
                delay_freqs["Late Air Craft Delay"] = lad++;

            }

        }

    }

    return max_string(delay_freqs, "No Common Delay");
}

string GraphS::airCarrier(string& airpt)
{
    map<string, int> comp_freqs;

    for (int i = 0; i < WIDTH; i++)
    {
        for (unsigned int j = 0; j < data[airports[airpt]][i].size(); j++)
        {
            comp_freqs[data[airports[airpt]][i][j].carrier]++;
        }

    }
    return max_string(comp_freqs, "No Common Airline");
}

float GraphS::airPercentDelayed(string& airpt) {
    float num_flights = airNumFlownFrom(airpt);
    float num_flights_delayed = airNumDelayed(airpt);

    return num_flights_delayed / num_flights;
}

int GraphS::airNumFlownTo(string& airpt)
{
    int num_flights = 0;
    for (int j = 0; j < WIDTH; j++)
    {
        for (unsigned int i = 0; i < data[j][airports[airpt]].size(); i++)
        {
            num_flights++;
        }
    }
    return num_flights;
}

int GraphS::airNumFlownFrom(string& airpt)
{
    int num_flights = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (unsigned int j = 0; j < data[airports[airpt]][i].size(); j++)
        {
            num_flights++;
        }
    }

    return num_flights;
}

int GraphS::airNumDelayed(string& airpt)
{
    int num_flights = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (unsigned int j = 0; j < data[airports[airpt]][i].size(); j++)
        {
            if (data[airports[airpt]][i][j].carrier_delay != 0)
            {
                num_flights++;
                continue;
            }
            else if (data[airports[airpt]][i][j].weather_delay != 0)
            {
                num_flights++;
                continue;
            }
            else if (data[airports[airpt]][i][j].nas_delay != 0)
            {
                num_flights++;
                continue;
            }
            else if (data[airports[airpt]][i][j].security_delay != 0)
            {
                num_flights++;
                continue;
            }
            else if (data[airports[airpt]][i][j].late_aircraft_delay != 0)
            {
                num_flights++;
                continue;
            }

        }
    }

    return num_flights;

}

int GraphS::airAvgTravelTime(string& airpt)
{
    int total_travel_time = 0;
    int num_flights = 0;


    for (int i = 0; i < WIDTH; i++)
    {
        num_flights += data[airports[airpt]][i].size();
        for (unsigned int j = 0; j < data[airports[airpt]][i].size(); j++)
        {
            total_travel_time += data[airports[airpt]][i][j].air_time;

        }
    }

    return total_travel_time / num_flights;
}
////////////////////////                      Option 4         ///////////////////////////////////////////////////////
int GraphS::avgDelay(string& delayType)
{
    int num_flights = 0;
    int delay_time = 0;

    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            for(unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if(delayType == "CARRIER")
                {
					if(data[i][j][k].carrier_delay != 0 )
					{
						 delay_time += data[i][j][k].carrier_delay;
						 num_flights++;
					}
                    
                }
                else if(delayType == "WEATHER")
                {
                    delay_time += data[i][j][k].weather_delay;
                    num_flights++;

                }
                else if(delayType == "NAS")
                {
                    delay_time += data[i][j][k].nas_delay;
                    num_flights++;

                }
                else if(delayType == "SECURITY")
                {
                    delay_time += data[i][j][k].security_delay;
                    num_flights++;

                }
                else if(delayType == "LATE_AIRCRAFT")
                {
                    delay_time += data[i][j][k].late_aircraft_delay;
                    num_flights++;
                }
            }
        }
    }
    return delay_time / num_flights;
}

int GraphS::avgTravelTime(string& delayType)
{
    int num_flights = 0;
    int travel_time = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if (delayType == "CARRIER")
                {
                    travel_time += data[i][j][k].air_time;
                    num_flights++;

                }
                else if (delayType == "WEATHER")
                {
                    travel_time += data[i][j][k].air_time;
                    num_flights++;

                }
                else if (delayType == "NAS")
                {
                    travel_time += data[i][j][k].air_time;
                    num_flights++;

                }
                else if (delayType == "SECURITY")
                {
                    travel_time += data[i][j][k].air_time;
                    num_flights++;
                }
                else if (delayType == "LATE_AIRCRAFT")
                {
                    travel_time += data[i][j][k].air_time;
                    num_flights++;
                }
            }
        }
    }

    return travel_time/num_flights;
}
////////////////////									Option 5								////////////////////////////////////////
int GraphS::timeAvgDelay(int time_of_day)
{
    int num_flights = 0;
    int delay_time = 0;

    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            for(unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].crs_dept_time == time_of_day)
                {
                    delay_time += data[i][j][k].dep_delay + data[i][j][k].arr_delay;
                    num_flights++;
                }
            }
        }
    }
    return delay_time/num_flights;
}

string GraphS::timeDelayType(int time_of_day)
{
   map<string, int> delay_freqs;

    int cd = 0, wd = 0, nd = 0, sd = 0, lad = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].crs_dept_time == time_of_day)
                {
                    if (data[i][j][k].carrier_delay != 0)
                    {
                        delay_freqs["Carrier Delay"] = cd++;

                    }
                    if (data[i][j][k].weather_delay != 0)
                    {
                        delay_freqs["Weather Delay"] = wd++;

                    }
                    if (data[i][j][k].nas_delay != 0)
                    {
                        delay_freqs["Nas Delay"] = nd++;

                    }
                    if (data[i][j][k].security_delay != 0)
                    {
                        delay_freqs["Security Delay"] = sd++;

                    }
                    if (data[i][j][k].late_aircraft_delay != 0)
                    {
                        delay_freqs["Late Air Craft Delay"] = lad++;

                    }

                }
                else continue;
            }
        }
    }

    return max_string(delay_freqs, "No Common Delays");
	
}

pair<vector<string>, vector<string>> GraphS::airportDelayTimes(int time_of_day)
{
	map<int, vector<string>> ports; //delay time, list of airports, sorted from lowest to highest
	for(int i = 0; i < WIDTH; i++)
    {
		for(int j = 0; j < WIDTH; j++)
        {

			for(unsigned int k =0; k< data[i][j].size(); k++)
            {
                if (data[i][j][k].crs_dept_time == time_of_day)
                {
                    ports[data[i][j][k].dep_delay + data[i][j][k].arr_delay].push_back(data[i][j][k].origin);
                }
			}
		}
		
	}
	return make_pair(ports.begin()->second, ports.rbegin()->second);
	
}

float GraphS::timePercentDelayed(int time_of_day)
{
    float num_flights = 0;
    float num_delayed_flights = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].crs_dept_time == time_of_day)
                {
                    num_flights++;
					if (data[i][j][k].carrier_delay != 0)
					{
                        num_delayed_flights++;
						continue;
					}
					else if (data[i][j][k].weather_delay != 0)
					{
                        num_delayed_flights++;
						continue;
					}
					else if (data[i][j][k].nas_delay != 0)
					{
                        num_delayed_flights++;
						continue;
					}
					else if (data[i][j][k].security_delay != 0)
					{
                        num_delayed_flights++;
						continue;
					}
					else if (data[i][j][k].late_aircraft_delay != 0)
					{
                        num_delayed_flights++;
						continue;
					}
                }
                else continue;
            }
        }
    }
    return num_delayed_flights/ num_flights;
}