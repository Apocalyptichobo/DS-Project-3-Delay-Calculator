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

void GraphS::readData(int year, int h)
{
    int airport_id = 0;

    string dataset;
    if (year == 2016 && h == 1) dataset = "Input/2016p1.csv";
    else if (year == 2016 && h == 2) dataset = "Input/2017p2.csv";
    else if (year == 2017 && h == 1) dataset = "Input/2018p1.csv";
    else if (year == 2017 && h == 2) dataset = "Input/2017p2.csv";
    else if (year == 2018 && h == 1) dataset = "Input/2018p1.csv";
    else if (year == 2018 && h == 2) dataset = "Input/2017p2.csv";

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
    }
    file.close();
}
void GraphS::Option1(string& input) {
    // Input a company (via company identification code) vf or DL (carrier)
    cout << "Average delay time for " << input << ": " << comAvgDelay(input) << endl;
    cout << "Most common delay issue for " << input << ": " << comDelayType(input) << endl;
    cout << "Percentage of flights delayed for " << input << ": " << comPerDelayed(input) << endl;
    cout << "Average travel time for " << input << ": " << comAvgTravelTime(input) << endl;
    cout << "Number of planes launched by " << input << ": " << comNumLaunched(input) << endl;
    cout << "Number of planes delayed by " << input << ": " << comNumDelayed(input) << endl;
}
void GraphS::Option2(string& input, string& input2) {
    //Input an arrival location and a departure location
    cout << "Average delay time between " << input <<  " and " << input2 << ": " << ADAvgDelay(input, input2) << endl;
    cout << "Most common delay issue between " << input << " and " << input2 << ": " << ADDelayType(input, input2) << endl;
    cout << "Percentage of flights delayed between " << input << " and " << input2 << ": %" << ADPerDelayed(input, input2) << endl;
    cout << "Average taxi-out time between " << input << " and " << input2 << ": " << avgTaxiTime(input, input2,0) << endl;
    cout << "Average taxi-in time between " << input << " and " << input2 << ": " << avgTaxiTime(input, input2,1) << endl;
    cout << "Number of planes launched between " << input << " and " << input2 << ": " << ADNumLaunched(input, input2) << endl;
    cout << "Number of planes delayed between " << input << " and " << input2 << ": " << ADNumDelayed(input, input2) << endl;
}
void GraphS::Option3(string& input) {
    //Input an airport (via three letter identification code) Atlanta = ATL (origin)
    cout << "Average delay time at " << input << ": " << airAvgDelay(input) << endl;
    cout << "Most common delay issue at " << input << ": " << airDelayType(input) << endl;
    cout << "Most common airline flown at " << input << ": " << airCarrier(input) << endl;
    cout << "Percentage of flights delayed at " << input << ": %" << airPercentDelayed(input) << endl;
    cout << "Number of flights to " << input << ": " << airNumFlownTo(input) << endl;
    cout << "Number of flights from " << input << ": " << airNumFlownFrom(input)<< endl;
    cout << "Number of flights delayed at " << input << ": " << airNumDelayed(input) << endl;
    cout << "Average travel time at " << input << ": " << airAvgTravelTime(input) << endl;
}
void GraphS::Option4(string& input) {
    vector<string> best, worst;
    string bestApt;
    //Input type of delay (from a given list of delays)
    cout << "Average delay time for " << input << "delay: " << avgDelay(input) << endl;
    cout << "Bottom five airports with the highest delay time for " << input << "delay: ";
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
    cout << "Average travel time for " << input << "delay: " << avgTravelTime(input) << endl;
    //cout << "The best airport to go to avoid " << input << "delay: " << bestApt << endl;
}
void GraphS::Option5(string& input) {
    //Input preferred departure time (example being 0800)
    cout << "Average delay time at " << input << "time: " << timeAvgDelay(stoi(input)) << endl;
    cout << "Most common delay for " << input << "time: " << timeDelayType(stoi(input)) << endl;
    cout << "Airport to fly out of with the least amount of delay time at " << input << "time: " << airportDelayTimes(stoi(input),0) << endl;
    cout << "Airport to not fly out of with most amount of delay time at " << input << "time: " << airportDelayTimes(stoi(input),1) << endl;
    cout << "Chance that your flight will be delayed at " << input << "time: %" << timePercentDelayed(stoi(input)) << endl;
}

///////////////////////////////////           Option 3        //////////////////////////////////////////////////////////
float GraphS::airAvgDelay(string& airpt)
{
    float num_delayed_flights = 0;
    float total_delay = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (unsigned int j = 0; j < data[airports[airpt]][i].size(); i++)
        {
            float dept = (float)data[airports[airpt]][i][j].dep_delay;
            float arr = (float)data[airports[airpt]][i][j].arr_delay;

            total_delay = dept + arr;
        }
    }

    return total_delay / num_delayed_flights;
}


string GraphS::airDelayType(string& airpt)
{
    map<string, int> delay_freqs;

    for (int i = 0; i < WIDTH; i++)
    {

        for (unsigned int j = 0; j < data[airports[airpt]][i].size(); j++)
        {

            if (data[airports[airpt]][i][j].carrier_delay != 0) {
                delay_freqs["Carrier Delay"] = delay_freqs.count("Carrier Delay") + 1;
            }
            if (data[airports[airpt]][i][j].weather_delay != 0) {
                delay_freqs["Weather Delay"] = delay_freqs.count("Weather Delay") + 1;
            }
            if (data[airports[airpt]][i][j].nas_delay != 0) {
                delay_freqs["nas Delay"] = delay_freqs.count("nas Delay") + 1;
            }
            if (data[airports[airpt]][i][j].security_delay != 0) {
                delay_freqs["Security Delay"] = delay_freqs.count("Security Delay") + 1;
            }
            if (data[airports[airpt]][i][j].late_aircraft_delay != 0) {
                delay_freqs["Late Air Craft Delay"] = delay_freqs.count("Late Air Craft Delay") + 1;
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
    float num_delayed_flights = 0;
    float num_flights = 0;

    for (int i = 0; i < WIDTH; i++) {
        for (unsigned int j = 0; j < data[airports[airpt]][i].size(); j++)
        {
            
            num_flights++;
         
            if (data[airports[airpt]][i][j].carrier_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[airpt]][i][j].weather_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[airpt]][i][j].nas_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[airpt]][i][j].security_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[airpt]][i][j].late_aircraft_delay != 0)
            {
                num_delayed_flights++;
                continue;
            }
        }
    }
    float pct = num_delayed_flights / num_flights;
    return pct;
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
        for (unsigned int j = 0; j < data[airports[airpt]][i].size(); j++)
        {
            total_travel_time += data[airports[airpt]][i][j].air_time;

        }
    }

    return total_travel_time / num_flights;
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
    for (unsigned int i = 0; i < data[airports[airpt1]][airports[airpt2]].size(); i++)
    {
        if (data[airports[airpt1]][airports[airpt2]][i].carrier_delay != 0) {
            delay_freqs["Carrier Delay"] = delay_freqs.count("Carrier Delay") + 1;
        }
        if (data[airports[airpt1]][airports[airpt2]][i].weather_delay != 0) {
            delay_freqs["Weather Delay"] = delay_freqs.count("Weather Delay") + 1;
        }
        if (data[airports[airpt1]][airports[airpt2]][i].nas_delay != 0) {
            delay_freqs["nas Delay"] = delay_freqs.count("nas Delay") + 1;
        }
        if (data[airports[airpt1]][airports[airpt2]][i].security_delay != 0) {
            delay_freqs["Security Delay"] = delay_freqs.count("Security Delay") + 1;
        }
        if (data[airports[airpt1]][airports[airpt2]][i].late_aircraft_delay != 0) {
            delay_freqs["Late Air Craft Delay"] = delay_freqs.count("Late Air Craft Delay") + 1;
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
        num_flights++;


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




float GraphS::avgTaxiTime(string& airpt1, string& airpt2, int in_or_out) {
    float num_flights = 0;
    float total_taxi_time = 0;

    for(unsigned int i = 0; i < data[airports[airpt1]][airports[airpt2]].size(); i++)
    {
        if (in_or_out == 0) total_taxi_time += data[airports[airpt1]][airports[airpt2]][i].taxi_in;
        else total_taxi_time += data[airports[airpt1]][airports[airpt2]][i].taxi_out;
    }

    return total_taxi_time / num_flights;
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
        else if (data[airports[airpt1]][airports[airpt2]][i].security_delay != 0) {
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

    return max_string(delay_freqs, "No Common Delays");
}

float GraphS::comPerDelayed(string& corp)
{

    float num_delayed_flights = 0;
    float num_flights = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
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

//pair<vector<string>,vector<string>> GraphS::airportHighLow(string& delayType, int how_many)
//{
//    map<string, int> delay_times;
//
//	for (int i = 0; i < WIDTH; i++)
//    {
//        for (int j = 0; j < WIDTH; j++)
//        {
//            for (unsigned int k = 0; k < data[i][j].size(); k++)
//            {
//
//                int a = data[i][j][k].carrier_delay;
//                int b = data[i][j][k].weather_delay;
//                int c = data[i][j][k].nas_delay;
//                int d = data[i][j][k].security_delay;
//                int e = data[i][j][k].late_aircraft_delay;
//                int sum = a + b + c + d + e;
//
//				if (delay_times.count(data[i][j][k].origin) == 0) { delay_times[data[i][j][k].origin] = sum; }
//				else delay_times[data[i][j][k].origin] += sum;
//
//            }
//        }
//    }
//
//	string desc = "Descending";
//	string asc = "Ascending";
//    vector<string> worst;//    vector<string> best;
//	// we want to print the keys having the lowest/highest values
//	SortbyValue(delay_times,desc);
//    worst = fillVector(delay_times, 5);
//    SortbyValue(delay_times,asc);
//    best = fillVector(delay_times, 5);
//
//    return(make_pair(worst, best));
//}


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
        for (auto it = time_per_port.end(); it != time_per_port.end(); it++)
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
    float flights_delayed = 0;

    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            for (unsigned int k = 0; k < data[i][j].size(); k++)
            {
                bool lower_bound = data[i][j][k].dept_time >= (time_of_day - 5) % 2400;
                bool upper_bound = data[i][j][k].dept_time <= (time_of_day + 5) % 2400;
                if (upper_bound && lower_bound)
                {
                    num_flights++;
                    if (data[i][j][k].carrier_delay != 0)
                    {
                        flights_delayed++;
                        continue;
                    }
                    else if (data[i][j][k].weather_delay != 0)
                    {
                        flights_delayed++;
                        continue;
                    }
                    else if (data[i][j][k].nas_delay != 0)
                    {
                        flights_delayed++;
                        continue;
                    }
                    else if (data[i][j][k].security_delay != 0)
                    {
                        flights_delayed++;
                        continue;
                    }
                    else if (data[i][j][k].late_aircraft_delay != 0)
                    {
                        flights_delayed++;
                        continue;
                    }
                }
            }
        }
        return flights_delayed / num_flights;
    }
}