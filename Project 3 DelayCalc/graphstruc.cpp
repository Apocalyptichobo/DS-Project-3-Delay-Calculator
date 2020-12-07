#include "graphstruc.h"
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


///////////////////////////////////           Option 3        //////////////////////////////////////////////////////////
float GraphS::avgDelayTime(string& corp)
{
    float num_delayed_flights = 0;
    float total_delay = 0;

    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < data[airports[corp]][i].size(); i++)
        {
            float delay_time = 0;

            if(data[airports[corp]][i][j].carrier_delay != -1)
            {
                delay_time += (float)data[airports[corp]][i][j].carrier_delay;
            }
            else if(data[airports[corp]][i][j].weather_delay != -1)
            {
                delay_time += (float)data[airports[corp]][i][j].weather_delay;
            }
            else if(data[airports[corp]][i][j].nas_delay != -1)
            {
                delay_time += (float)data[airports[corp]][i][j].nas_delay;
            }
            else if(data[airports[corp]][i][j].security_delay != -1)
            {
                delay_time += (float)data[airports[corp]][i][j].security_delay;
            }
            else if(data[airports[corp]][i][j].late_aircraft_delay != -1)
            {
                delay_time += (float)data[airports[corp]][i][j].late_aircraft_delay;
            }

            if(delay_time != 0)
            {
                total_delay = total_delay + delay_time;
                num_delayed_flights++;
            }
        }
    }

    return total_delay/num_delayed_flights;
}


string GraphS::commonDelay(string& corp)
{
    map<string, int> delay_freqs;

    for(int i= 0; i < WIDTH; i++)
    {

        for(int j = 0; j < data[airports[corp]][i].size(); j++)
        {

            if (data[airports[corp]][i][j].carrier_delay != -1) {
                delay_freqs["Carrier Delay"] = delay_freqs.count("Carrier Delay") + 1;
            }
            if (data[airports[corp]][i][j].weather_delay != -1) {
                delay_freqs["Weather Delay"] = delay_freqs.count("Weather Delay") + 1;
            }
            if (data[airports[corp]][i][j].nas_delay != -1) {
                delay_freqs["nas Delay"] = delay_freqs.count("nas Delay") + 1;
            }
            if (data[airports[corp]][i][j].security_delay != -1) {
                delay_freqs["Security Delay"] = delay_freqs.count("Security Delay") + 1;
            }
            if (data[airports[corp]][i][j].late_aircraft_delay != -1) {
                delay_freqs["Late Air Craft Delay"] = delay_freqs.count("Late Air Craft Delay") + 1;
            }
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

string GraphS::commonAirline(string& corp)
{
    map<string, int> comp_freqs;

    for(int i= 0; i < WIDTH; i++)
    {
        for(int j = 0; j < data[airports[corp]][i].size(); j++)
        {
            comp_freqs[data[airports[corp]][i][j].carrier] = comp_freqs.count(data[airports[corp]][i][j].carrier) + 1;
        }

    }
    int maximum = 0; //we will have at least one airline with a greater freq than 0, or there are no entries in the matrix
    string maxString = " ";
    for(auto it = comp_freqs.end(); it != comp_freqs.end(); it++)
    {
        if(it->second > maximum)
        {
            maximum = it->second;
            maxString = it->first;

        }
    }
    return maxString;
}

float GraphS::airPercentDelayed(string& corp) {
    float num_delayed_flights = 0;
    float num_flights = 0;

    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < data[airports[corp]][i].size(); j++)
        {
            if (data[airports[corp]][i][j].date != -1) {
                num_flights++;
            } else continue;

            if (data[airports[corp]][i][j].carrier_delay != -1)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].weather_delay != -1)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].nas_delay != -1)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].security_delay != -1)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].late_aircraft_delay != -1)
            {
                num_delayed_flights++;
                continue;
            }
        }
    }
    float pct = num_delayed_flights / num_flights;
    return pct;
}

int GraphS::toX(string &corp)
{
    int num_flights = 0;
    for(int j = 0; j < WIDTH; j++)
    {
        for (int i = 0; i < data[j][airports[corp]].size(); j++)
        {
            if (data[j][airports[corp]][i].date != -1)
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

    for(int i = 0; i < WIDTH; i ++)
    {
        for (int j = 0; j < data[airports[corp]][i].size(); j++)
        {
            if (data[airports[corp]][i][j].date != -1)
            {
                num_flights++;
            }
            else continue;
        }
    }

    return num_flights;
}

/////////////////////////////              Option 2            //////////////////////////////////////////////////////

float GraphS::avgDelayTimeXY(string &corp1, string &corp2)
{
    float num_flights = data[airports[corp1]][airports[corp2]].size();
    float delay_time = 0;

    for(int i = 0; i < data[airports[corp1]][airports[corp2]].size(); i++)
    {
        //if()
        float dept = (float)data[airports[corp1]][airports[corp2]][i].dep_delay;
        float arr = (float)data[airports[corp1]][airports[corp2]][i].arr_delay;

        delay_time = delay_time + dept + arr;
    }

    return delay_time/num_flights;
}

string GraphS::commonDelayXY(string &corp1, string &corp2)
{
    map<string, int> delay_freqs;
    for(int i = 0; i < data[airports[corp1]][airports[corp2]].size(); i++)
    {
        if (data[airports[corp1]][airports[corp2]][i].carrier_delay != -1) {
            delay_freqs["Carrier Delay"] = delay_freqs.count("Carrier Delay") + 1;
        }
        if (data[airports[corp1]][airports[corp2]][i].weather_delay != -1) {
            delay_freqs["Weather Delay"] = delay_freqs.count("Weather Delay") + 1;
        }
        if (data[airports[corp1]][airports[corp2]][i].nas_delay != -1) {
            delay_freqs["nas Delay"] = delay_freqs.count("nas Delay") + 1;
        }
        if (data[airports[corp1]][airports[corp2]][i].security_delay != -1) {
            delay_freqs["Security Delay"] = delay_freqs.count("Security Delay") + 1;
        }
        if (data[airports[corp1]][airports[corp2]][i].late_aircraft_delay != -1) {
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

float GraphS::airPercentDelayedXY(string &corp1, string &corp2)
{
    float num_delayed_flights = 0;
    float num_flights = 0;

    for(int i = 0; i < data[airports[corp1]][airports[corp2]].size(); i++)
    {
        if (data[airports[corp1]][airports[corp2]][i].date != -1) {
            num_flights++;
        } else continue;

        if (data[airports[corp1]][airports[corp2]][i].carrier_delay != -1)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].weather_delay != -1)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].nas_delay != -1)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].security_delay != -1)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].late_aircraft_delay != -1)
        {
            num_delayed_flights++;
            continue;
        }

    }

    float pct = num_delayed_flights / num_flights;
    return pct;
}

float GraphS::avgTaxiOutTime(string &corp) {
    float num_flights = 0;
    float total_taxi_time = 0;

    for(int i = 0; i < WIDTH; i++)
    {
        for(int j = 0; j < data[airports[corp]][i].size(); i++)
        {
            if (data[airports[corp]][i][j].date != -1)
            {
                num_flights++;
            }
            else continue;
            total_taxi_time += (float)data[airports[corp]][i][j].taxi_out;

        }
    }
    return total_taxi_time/num_flights;
}

int GraphS::noPlanesFlown(string &corp1, string &corp2) {

    return data[airports[corp1]][airports[corp2]].size();
}

int GraphS::noPlanesDelayed(string &corp1, string &corp2) {

    int num_delayed_flights = 0;
    for(int i =0; i < data[airports[corp1]][airports[corp2]].size(); i++)
    {
        if (data[airports[corp1]][airports[corp2]][i].carrier_delay != -1)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].weather_delay != -1)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].nas_delay != -1)
        {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].security_delay != -1) {
            num_delayed_flights++;
            continue;
        }
        else if (data[airports[corp1]][airports[corp2]][i].late_aircraft_delay != -1)
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

            if (data[airports[corp]][i][j].carrier_delay != -1)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].weather_delay != -1)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].nas_delay != -1)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].security_delay != -1)
            {
                num_delayed_flights++;
                continue;
            }
            else if (data[airports[corp]][i][j].late_aircraft_delay != -1)
            {
                num_delayed_flights++;
                continue;
            }
        }

    }
    return num_delayed_flights;
}

float GraphS::avgDelayTimeCorp(string &corp)
{
    float num_flights = 0;
    float delay_time = 0;

    for(int i = 0; i <WIDTH; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            for(int k = 0; k < data[i][j].size(); k++)
            {
                if(data[i][j][k].carrier == corp)
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
    return delay_time/num_flights;
}

string GraphS::commonDelayCorp(string &corp)
{
    map<string, int> delay_freqs;

    for(int i = 0; i <WIDTH; i++)
    {
        for(int j = 0; j < WIDTH; j++)
        {
            for(int k = 0; k < data[i][j].size(); k++)
            {
                if(data[i][j][k].carrier == corp)
                {
                    //do something
                }
                else continue;
            }
        }
    }

}

float GraphS::airPercentDelayedCorp(string &corp)
{
    return 0;
}

float GraphS::travelTime(string &corp)
{
    return 0;
}

float GraphS::noPlanesFlownCorp(string &corp)
{
    return 0;
}

float GraphS::noPlanesDelayedCorp(string &corp)
{
    return 0;
}