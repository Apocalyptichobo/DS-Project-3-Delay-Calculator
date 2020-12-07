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
            for(int k = 0; k < data[i][j].size(); k++)
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
        //getline(ss, temp, ',');
        //f.date = temp;	//date
        getline(ss, temp, ',');
        f.carrier = temp;		//carrier
        //getline(ss, temp, ',');
        //f.flight_number = temp; //num

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
        /*getline(ss, temp, ',');
        f.wheels_off = stoi(temp);
        getline(ss, temp, ',');
        f.wheels_on = stoi(temp);
        getline(ss, temp, ',');
        f.taxi_in = stoi(temp);
        getline(ss, temp, ',');
        f.crs_arr_time = stoi(temp);
        getline(ss, temp, ',');
        f.arr_time = stoi(temp);*/
        getline(ss, temp, ',');
        f.arr_delay = stoi(temp);
        getline(ss, temp, ',');
        f.cancelled = stoi(temp);
        /*getline(ss, temp, ',');
        f.cancel_code = temp;
        getline(ss, temp, ',');
        f.diverted = stoi(temp);*/
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
        //cout << data[0][1][1].destination;
    }
    file.close();
}
void GraphS::Option1(string& input) {
    string fix = "\"";
    string correct = fix + input;
    correct.append(fix);
    // Input a company (via company identification code) vf or DL (carrier)
    cout << "Average delay time for " << input << ": " << comAvgDelay(correct) << endl;
    cout << "Most common delay issue for " << input << ": " << comDelayType(correct) << endl;
    cout << "Average travel time for " << input << ": " << comAvgTravelTime(correct) << endl;
    cout << "Number of planes launched by " << input << ": " << comNumLaunched(correct) << endl;
    cout << "Number of planes delayed by " << input << ": " << comNumDelayed(correct) << endl;
    cout << "Percentage of flights delayed for " << input << ": " << comPerDelayed(correct) * 100 << endl;

}
void GraphS::Option2(string& input, string& input2) {

    string fix = "\"";
    string correct = fix + input;
    correct.append(fix);
    string correct2 = fix + input2;
    correct2.append(fix);
    //Input an arrival location and a departure location
    cout << "Average delay time between " << input <<  " and " << input2 << ": " << ADAvgDelay(correct, correct2) << endl;
    cout << "Most common delay issue between " << input << " and " << input2 << ": " << ADDelayType(correct, correct2) << endl;
    cout << "Percentage of flights delayed between " << input << " and " << input2 << ": %" << ADPerDelayed(correct, correct2) * 100 << endl;
    cout << "Average taxi-out time between " << input << " and " << input2 << ": " << avgTaxiTime(correct, correct2).second << endl;
    cout << "Average taxi-in time between " << input << " and " << input2 << ": " << avgTaxiTime(correct, correct2).first << endl;
    cout << "Number of planes launched between " << input << " and " << input2 << ": " << ADNumLaunched(correct, correct2) << endl;
    cout << "Number of planes delayed between " << input << " and " << input2 << ": " << ADNumDelayed(correct, correct2) << endl;
}
void GraphS::Option3(string& input) {
    string fix = "\"";
    string correct = fix + input;
    correct.append(fix);
    //Input an airport (via three letter identification code) Atlanta = ATL (origin)
    cout << "Average delay time at " << input << ": " << airAvgDelay(correct) << endl;
    cout << "Most common delay issue at " << input << ": " << airDelayType(correct) << endl;
    cout << "Most common airline flown at " << input << ": " << airCarrier(correct) << endl;
    cout << "Percentage of flights delayed at " << input << ": %" << airPercentDelayed(correct) << endl;
    cout << "Number of flights to " << input << ": " << airNumFlownTo(correct) << endl;
    cout << "Number of flights from " << input << ": " << airNumFlownFrom(correct)<< endl;
    cout << "Number of flights delayed at " << input << ": " << airNumDelayed(correct) << endl;
    cout << "Average travel time at " << input << ": " << airAvgTravelTime(correct) << endl;
}
void GraphS::Option4(string& input) {
    string fix = "\"";
    string correct = fix + input;
    correct.append(fix);
    vector<string> best, worst;
    string bestApt;
    //Input type of delay (from a given list of delays)
    cout << "Average delay time for " << input << " delay: " << avgDelay(correct) << endl;
    cout << "Bottom five airports with the highest delay time for " << input << " delay: " << endl;
    /* worst = airportHighLow(input, 5).first;
     for (int i = 0; i < 5; i++)
     {
         cout << worst[i] << " ";
     }
     cout << "Top five airports with the lowest delay time for " << input << "delay: ";
     best = airportHighLow(input,5).second;
     for (int i = 0; i < 5; i++)
     {
         cout << best[i] << " ";
     }
     bestApt = best[0];*/
    cout << "Average travel time for " << input << " delay: " << avgTravelTime(correct) << endl;
    //cout << "The best airport to go to avoid " << input << "delay: " << bestApt << endl;
}
void GraphS::Option5(string& input) {
    //Input preferred departure time (example being 0800)
    cout << "Average delay time at " << input << ": " << timeAvgDelay(stoi(input)) << endl;
    cout << "Most common delay for " << input << ": " << timeDelayType(stoi(input)) << endl;
    cout << "Airport to fly out of with the least amount of delay time at " << input << ": " << airportDelayTimes(stoi(input),0) << endl;
    cout << "Airport to not fly out of with most amount of delay time at " << input << ": " << airportDelayTimes(stoi(input),1) << endl;
    cout << "Chance that your flight will be delayed at " << input << ": %" << timePercentDelayed(stoi(input)) << endl;
}

///////////////////////////////////           Option 3        //////////////////////////////////////////////////////////
float GraphS::airAvgDelay(string& airpt)
{
    float num_flights = 0;
    float total_delay = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        num_flights += data[airports[airpt]][i].size();
        for (unsigned int j = 0; j < data[airports[airpt]][i].size(); i++)
        {
            float dept = (float)data[airports[airpt]][i][j].dep_delay;
            float arr = (float)data[airports[airpt]][i][j].arr_delay;

            total_delay = total_delay + dept + arr;
        }
    }

    return num_flights / total_delay;
}


string GraphS::airDelayType(string& airpt)
{
    map<string, int> delay_freqs;
    int cd, wd, nd, sd, lad = 1;

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
                delay_freqs["nas Delay"] = nd++;

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
            comp_freqs[data[airports[airpt]][i][j].carrier] = comp_freqs.count(data[airports[airpt]][i][j].carrier) + 1;
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
        for (unsigned int i = 0; i < data[j][airports[airpt]].size(); j++)
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

float GraphS::airAvgTravelTime(string& airpt)
{
    float total_travel_time = 0;
    float num_flights = 0;


    for (int i = 0; i < WIDTH; i++)
    {
        num_flights += data[airports[airpt]][i].size();
        for (unsigned int j = 0; j < data[airports[airpt]][i].size(); j++)
        {
            total_travel_time += data[airports[airpt]][i][j].air_time;

        }
    }

    return num_flights / total_travel_time;
}

/////////////////////////////							Option 2								//////////////////////////////////////////////////////

float GraphS::ADAvgDelay(string& airpt1, string& airpt2)
{
    float num_flights = (float)data[airports[airpt1]][airports[airpt2]].size();
    float delay_time = 0;

    for (unsigned int i = 0; i < data[airports[airpt1]][airports[airpt2]].size(); i++)
    {

        float dept = (float)data[airports[airpt1]][airports[airpt2]][i].dep_delay;
        float arr = (float)data[airports[airpt1]][airports[airpt2]][i].arr_delay;

        delay_time = delay_time + dept + arr;
    }

    return delay_time / num_flights;
}

string GraphS::ADDelayType(string& airpt1, string& airpt2)
{
    map<string, int> delay_freqs;
    int cd, wd, nd, sd, lad = 1;
    for (unsigned int i = 0; i < data[airports[airpt1]][airports[airpt2]].size(); i++)
    {

        if(data[airports[airpt1]][airports[airpt2]][i].carrier_delay != 0)
        {
            delay_freqs["Carrier Delay"] = cd++;

        }
        if(data[airports[airpt1]][airports[airpt2]][i].weather_delay != 0)
        {
            delay_freqs["Weather Delay"] = wd++;

        }
        if(data[airports[airpt1]][airports[airpt2]][i].nas_delay != 0)
        {
            delay_freqs["nas Delay"] = nd++;

        }
        if(data[airports[airpt1]][airports[airpt2]][i].security_delay != 0)
        {
            delay_freqs["Security Delay"] = sd++;

        }
        if(data[airports[airpt1]][airports[airpt2]][i].late_aircraft_delay != 0)
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




pair<int,int> GraphS::avgTaxiTime(string& airpt1, string& airpt2) {
    int num_flights = 0;
    int in, out = 0;

    for(unsigned int i = 0; i < data[airports[airpt1]][airports[airpt2]].size(); i++)
    {
        in += data[airports[airpt1]][airports[airpt2]][i].taxi_in;
        out += data[airports[airpt1]][airports[airpt2]][i].taxi_out;

        num_flights++;
    }

    return make_pair(in/num_flights, out/num_flights);
}

int GraphS::ADNumLaunched(string& airpt1, string& airpt2) {

    return data[airports[airpt1]][airports[airpt2]].size();
}

int GraphS::ADNumDelayed(string& airpt1, string& airpt2) {

    int num_delayed_flights = 0;
    for (unsigned int i = 0; i < data[airports[airpt1]][airports[airpt2]].size(); i++)
    {
        int delay_count = 0;
        delay_count += data[airports[airpt1]][airports[airpt2]][i].carrier_delay;
        delay_count += data[airports[airpt1]][airports[airpt2]][i].weather_delay;
        delay_count += data[airports[airpt1]][airports[airpt2]][i].nas_delay;
        delay_count += data[airports[airpt1]][airports[airpt2]][i].security_delay;
        delay_count += data[airports[airpt1]][airports[airpt2]][i].weather_delay;

        if(delay_count > 0) num_delayed_flights++;

    }
    return num_delayed_flights;
}

////////////////////////////////////                            Option 1  (Cubic functions)						 ////////////////////////////////////////////////////////////////
float GraphS::comAvgDelay(string& corp)
{
    float num_flights = 0;
    float delay_time = 0;

    for (unsigned int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
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

string GraphS::comDelayType(string& corp)
{
    map<string, int> delay_freqs;

    int cd, wd, nd, sd, lad = 1;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].carrier == corp)
                {
                     if(data[i][j][k].carrier_delay != 0)
                     {
                         delay_freqs["Carrier Delay"] = cd++;

                     }
                    if(data[i][j][k].weather_delay != 0)
                    {
                        delay_freqs["Weather Delay"] = wd++;

                    }
                    if(data[i][j][k].nas_delay != 0)
                    {
                        delay_freqs["nas Delay"] = nd++;

                    }
                    if(data[i][j][k].security_delay != 0)
                    {
                        delay_freqs["Security Delay"] = sd++;

                    }
                    if(data[i][j][k].late_aircraft_delay != 0)
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

float GraphS::comAvgTravelTime(string& corp)
{
    float num_flights = 0;
    float travel_time = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
            {
                num_flights++;

                travel_time += data[i][j][k].air_time;

            }
        }
    }
    return travel_time/num_flights;
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
                num_flights++;
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
                int delay_count = 0;
                delay_count += data[i][j][k].carrier_delay;
                delay_count += data[i][j][k].weather_delay;
                delay_count += data[i][j][k].nas_delay;
                delay_count += data[i][j][k].security_delay;
                delay_count += data[i][j][k].weather_delay;

                if(delay_count > 0) num_delayed_flights++;
            }
        }
    }
    return num_delayed_flights;
}
////////////////////////									Option 4								///////////////////////////////////////////////////////
float GraphS::avgDelay(string& delayType)
{
    float num_flights = 0;
    float delay_time = 0;

    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            for(unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if(delayType == "CARRIER")
                {
                    delay_time += data[i][j][k].carrier_delay;
                    num_flights++;

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

float GraphS::avgTravelTime(string& delayType)
{
    float num_flights = 0;
    float travel_time = 0;

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
float GraphS::timeAvgDelay(int time_of_day)
{
    float num_flights = 0;
    float delay_time = 0;

    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            for(unsigned int k = 0; k < data[i][j].size(); k++)
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

string GraphS::timeDelayType(int time_of_day)
{
    map<string, int> delay_freqs;
    int cd, wd, nd, sd, lad = 1;
    for(int i=0; i < WIDTH; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {

            for(unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].dept_time == time_of_day)
                {
                    if(data[i][j][k].carrier_delay != 0)
                    {
                        delay_freqs["Carrier Delay"] = cd++;

                    }
                    if(data[i][j][k].weather_delay != 0)
                    {
                        delay_freqs["Weather Delay"] = wd++;

                    }
                    if(data[i][j][k].nas_delay != 0)
                    {
                        delay_freqs["nas Delay"] = nd++;

                    }
                    if(data[i][j][k].security_delay != 0)
                    {
                        delay_freqs["Security Delay"] = sd++;

                    }
                    if(data[i][j][k].late_aircraft_delay != 0)
                    {
                        delay_freqs["Late Air Craft Delay"] = lad++;

                    }

                }

            }
        }
    }
    return max_string(delay_freqs, "No Common Delay");
}

string GraphS::airportDelayTimes(int time_of_day, int least_or_most)
{
    //least = 0, most = 1

    map<string, int> time_per_port;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
            {
                if (data[i][j][k].dept_time == time_of_day)
                {
                    if (time_per_port.count(data[i][j][k].carrier) == 0)
                        time_per_port[data[i][j][k].carrier] = data[i][j][k].dep_delay;
                    else time_per_port[data[i][j][k].carrier] += data[i][j][k].dep_delay;

                }

            }
        }
    }

    if (least_or_most == 0)
    {
        int minimum = 2147483647;
        string minString = "No best airport";
        for (auto it = time_per_port.begin(); it != time_per_port.end(); it++)
        {
            if (it->second < minimum)
            {
                minimum = it->second;
                minString = it->first;

            }

        }
        return minString;
    }
    else return max_string(time_per_port, "No worst airport");
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
                if (data[i][j][k].dept_time == time_of_day)
                {
                    num_flights++;

                    int delay_count = 0;
                    delay_count += data[i][j][k].carrier_delay;
                    delay_count += data[i][j][k].weather_delay;
                    delay_count += data[i][j][k].nas_delay;
                    delay_count += data[i][j][k].security_delay;
                    delay_count += data[i][j][k].weather_delay;

                    if (delay_count > 0) num_delayed_flights++;
                }
                else continue;
            }
        }
    }
    return num_delayed_flights/ num_flights;
}
