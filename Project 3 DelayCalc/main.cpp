
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <ctime>
#include <random>
#include <utility>
#include "graphstruc1.h"
#include "mapstruc.h"
using namespace std;

void Display() {
	cout << "###################################################################################################" << endl;
	cout << "#                    _                                                                            #" << endl;
	cout << "#                  -=\\`\\                                                                          #" << endl;
	cout << "#              |\\ ____\\_\\__                                                                       #" << endl;
	cout << "#            -=\\c`\"\"\"\"\"\"\" \"`)                                                                     #" << endl;
	cout << "#               `~~~~~/ /~~`\                                                                      #" << endl;
	cout << "#                 -==/ /                                                                          #" << endl;
	cout << "#                   '-'                                                                           #" << endl;
	cout << "#                  _  _                                                                           #" << endl;
	cout << "#                 ( `   )_                                                                        #" << endl;
	cout << "#                (    )    `)                                                                     #" << endl;
	cout << "#              (_   (_ .  _) _)                                                                   #" << endl;
	cout << "#                                             _                                                   #" << endl;
	cout << "#                                            (  )                                                 #" << endl;
	cout << "#             _ .                         ( `  ) . )                                              #" << endl;
	cout << "#           (  _ )_                      (_, _(  ,_)_)                                            #" << endl;
	cout << "#         (_  _(_ ,)                                                                              #" << endl;
	cout << "###################################################################################################" << endl;
	cout << endl;
	cout << ".:+yyyysoosso+:`      :/yyysoooooosys  `:/yyyy/:.                 .h.         ./yyyyy/-     -+yyy+:" << endl;
	cout << "   dMM`    `:sNNh:      oMM/      `:d     yMM:                   `dMd`          `yMMh`       `Ny.  " << endl;
	cout << "   hMM        `yMMs     +MM/        :     sMM.                   yhNMy            +MMh`     .d+    " << endl;
	cout << "   hMM          hMMo    +MM/      /.      sMM.                  od`/MMo            :mMm-   :d:     " << endl;
	cout << "   hMM          /MMN    +MMo-----/m.      sMM.                 /m.  oMM/            .hMN+ +h.      " << endl;
	cout << "   hMM          :MMM`   +MMs::::/oN.      sMM.                :m-    yMN-            `oMMdy`       " << endl;
	cout << "   hMM          oMMh    +MM/      +.      sMM.               .myo++++oNMm.             hMM`        " << endl;
	cout << "   hMM         -NMm-    +MM/         ``   sMM.         -`   `d+```````-mMd`            hMM         " << endl;
	cout << "   hMM       `+NMy.     +MM/        -y`   sMM.        :s   `hs         :MMy            hMM         " << endl;
	cout << "`.:NMM+/::/+shho-     .-hMMy//:::/+yN: `.-dMMh+////+ohN- .:hM+.`      .-NMMh:.      `.:mMM+..      " << endl;
	cout << "`.----------.`        ..-------------  `..-------------  `----.`      `.-----.      `.-----.`      " << endl;
	cout << endl;
	cout << "              .:+oooo+/:.+-          `s.          :/osso/:-             `./+ooo++/-.s              " << endl;
	cout << "            -yms:.`  `./hM/          sMd`           oMMs`             `/hd+-`   `-omM`             " << endl;
	cout << "          `sMN:         `ss         +mNMy           /MM/             .hMh.         .d-             " << endl;
	cout << "          sMM+            :        /m./MMo          /MM/            `mMN.           ..             " << endl;
	cout << "         .MMN`                    -m:  oMM/         /MM/            oMMh                           " << endl;
	cout << "         :MMm                    .m/    yMN-        /MM/            yMMs                           " << endl;
	cout << "         -MMN`                  `dd+++++oNMm.       /MM/            oMMh                           " << endl;
	cout << "          yMMo            `     yy```````-NMd`      /MM/         `. .mMN-            `             " << endl;
	cout << "          `yMM+`         :+    od`        :MMy      /MM/        `y.  .dMm:         `+-             " << endl;
	cout << "            -yNms/.``.:++-   `oM+         `dMMy.   `sMMh:----:/sm+    `/dNh+:.``.:++`              " << endl;
	cout << "              `-/oooo/-`    .////:.      .://///: -://///////////        .:+ooo+/.                 " << endl;
	cout << endl;
}
void MenuSelect() {
	cout << endl;
	cout << "Please select an option from the following menu:" << endl;
	cout << "1. Input a company (via company identification code)" << endl;
	cout << "2. Input an arrival location and a departure location" << endl;
	cout << "3. Input an airport (via three letter identification code)" << endl;
	cout << "4. Input type of delay" << endl;
	cout << "5. Input preferred departure time (example being 16:42)" << endl;
	cout << "6. Exit" << endl;
	cout << endl;
}
bool validateN(int input, vector<int> numbers)
{
	for(unsigned int i = 0; i < numbers.size(); i++)
	{
		if(input == numbers[i])
			return true;
	}
	cout << "Invalid input" << endl;
	return false;
}
bool validateS(string input, vector<string> strings)
{
	for (unsigned int i = 0; i < strings.size(); i++)
	{
		if (input == strings[i])
			return true;
	}
	cout << "Invalid input" << endl;
	return false;
}
int main() {
	Display();
	bool valid = false;
	int year, structure{};
	string s;
	map<pair<int, string>, string> set{ {make_pair(2016, "JAN"), "Input/air2016p_jan.csv"}, {make_pair(2016, "FEB"), "Input/air2016p_feb.csv"}, {make_pair(2016, "MAR"), "Input/air2016p_mar.csv"} ,
	{make_pair(2016, "APR"), "Input/air2016p_apr.csv"} , {make_pair(2016, "MAY"), "Input/air2016p_may.csv"} , {make_pair(2016, "JUN"), "Input/air2016p_june.csv"} ,
	{make_pair(2016, "JUL"), "Input/air2016p_july.csv"} , {make_pair(2016,"AUG"), "Input/air2016p_aug.csv"} , {make_pair(2016, "SEP"), "Input/air2016p_sep.csv"} ,
	{make_pair(2016, "OCT"), "Input/air2016p_oct.csv"} , {make_pair(2016, "NOV"), "Input/air2016p_nov.csv"} , {make_pair(2016, "DEC"), "Input/air2016p_dec.csv"} ,
	{make_pair(2017, "JAN"), "Input/air2017p_jan.csv"} , {make_pair(2017, "FEB"), "Input/air2017p_feb.csv"} , {make_pair(2017, "MAR"), "Input/air2017p_mar.csv"} ,
	{make_pair(2017, "APR"), "Input/air2017p_apr.csv"} , {make_pair(2017, "MAY"), "Input/air2017p_may.csv"} , {make_pair(2017, "JUN"), "Input/air2017p_june.csv"} ,
	{make_pair(2017, "JUL"), "Input/air2017p_july.csv"} , {make_pair(2017, "AUG"), "Input/air2017p_aug.csv"} , {make_pair(2017, "SEP"), "Input/air2017p_sep.csv"} ,
	{make_pair(2017, "OCT"), "Input/air2017p_oct.csv"} , {make_pair(2017, "NOV"), "Input/air2017p_nov.csv"} , {make_pair(2017, "DEC"), "Input/air2017p_dec.csv"} ,
	{make_pair(2018, "JAN"), "Input/air2018p_jan.csv"} , {make_pair(2018, "FEB"), "Input/air2018p_jan.csv"} , {make_pair(2018, "MAR"), "Input/air2018p_mar.csv"} ,
	{make_pair(2018, "APR"), "Input/air2018p_apr.csv"} , {make_pair(2018, "MAY"), "Input/air2018p_may.csv"} , {make_pair(2018, "JUN"), "Input/air2016p_june.csv"} ,
	{make_pair(2018, "JUL"), "Input/air2018p_july.csv"} , {make_pair(2018, "AUG"), "Input/air2018p_aug.csv"} , {make_pair(2018, "SEP"), "Input/air2018p_sep.csv"} ,
	{make_pair(2018, "OCT"), "Input/air2018p_oct.csv"} , {make_pair(2018, "NOV"), "Input/air2018p_nov.csv"} , {make_pair(2018, "DEC"), "Input/air2016p_dec.csv"} ,
	};
	//user enters year
	while(!valid)
	{
		cout << "Please enter a year between 2016 and 2018: ";
		cin >> year;
		valid = validateN(year, {2016, 2017, 2018});
	}
	cout << endl;
	valid = false;
	while (!valid)
	{
		cout << "Please select a month to test using uppercase, three letter codes: " << endl;
		cout << "Example: JUN" << endl;;
		cin >> s;
		valid = validateS(s, { "JAN","FEB","MAR","APR","MAY","JUN","JUL","AUG","SEP","OCT","NOV","DEC" });
	}
	valid = false;
	//user enters which structure to use
	while(!valid)
	{
		cout << endl;
		cout << "Please select a data structure to test: " << endl;
		cout << "1. Map" << endl;
		cout << "2. Directed Graph" << endl;
		cin >> structure;
		valid = validateN(structure, {1,2});
	}
	valid = false;
	//if they chose option 1,map
	if (structure == 1) {
		int menuOption = 0;
		MapS m(set[make_pair(year, s )]);
		while (menuOption != 6) {
			string input, input2;
			MenuSelect();
			cin >> menuOption;
			bool help = true;
			if (menuOption == 1) 
			{
					cout << "Input a company (via company two letter identification code)" << endl;
					cout << "Example: DL" << endl;
					cout << "Type 'help' for a list of valid company identification codes" << endl;
					bool v = false;
					while(!v)
					{
						cin >> input;
						string fix = "\"";
						string correct = fix + input;
						correct = correct.append(fix);
						//here is where you would append
						if (input == "help") {
							//help
							v = false;
						}
						else if (!m.carrier.count(correct)) 
						{
							cout << "Invalid carrier, type 'help' for a list of valid codes" << endl;
							v = false;
						}
						else {
							input = correct;
							v = true; //valid
						} 
					}
					clock_t t = clock();
					m.Option1(input);
					t = clock() - t;
					cout << "Run time: " << (float)t / CLOCKS_PER_SEC << " seconds" << endl;
			}
			else if (menuOption == 2) 
			{
					cout << "Input an origin airport and destination airport (via airport three letter identification code)" << endl;
					cout << "Example: ATL" << endl;
					cout << "Type 'help' for a list of valid airport identification codes" << endl;
					cout << "Origin: ";
					bool v = false;
					while (!v)
					{
						cin >> input;
						string fix = "\"";
						string correct = fix + input;
						correct = correct.append(fix);
						//here is where you would append
						if (input == "help") {
							//make list
							v = false;
						}
						else if (!m.airports.count(correct))
						{
							cout << "Invalid airport, type 'help' for a list of valid codes" << endl;
							v = false;
						}
						else
						{
							input = correct;
							v = true; //valid
						}
					}

					//enter destination
					cout << "Destination: ";
	
					bool v2 = false;
					while (!v2)
					{
						cin >> input2;
						string fix = "\"";
						string correct2 = fix + input2;
						correct2 = correct2.append(fix);
						//here is where you would append
						if (input2 == "help") {
							//make list
							v = false;
						}
						else if (!m.airports.count(correct2))
						{
							cout << "Invalid airport, type 'help' for a list of valid codes" << endl;
							v2 = false;
						}
						else 
						{
							input2 = correct2;
							v2 = true; //valid
						}
					}
					clock_t t = clock();
					m.Option2(input, input2);
					t = clock() - t;
					cout << "Run time: " << (float)t / CLOCKS_PER_SEC << " seconds" << endl;
			}
			else if (menuOption == 3)
			{
					cout << "Input an airport (via three letter identification code)" << endl;
					cout << "Example: ATL" << endl;
					cout << "Type 'help' for a list of valid three letter identification codes" << endl;
					bool v = false;
					while (!v)
					{
						cin >> input;
						string fix = "\"";
						string correct = fix + input;
						correct = correct.append(fix);
						//here is where you would append
						if (input == "help") {
							//make list
							v = false;
						}
						if (!m.airports.count(correct))
						{
							cout << "Invalid airport, type 'help' for a list of valid codes" << endl;
							v = false;
						}
						else 
						{
							v = true; //valid
							input = correct;
						}
							
					}
					clock_t t = clock();
					m.Option3(input);
					t = clock() - t;
					cout << "Run time: " << (float)t / CLOCKS_PER_SEC << " seconds" << endl;
			}
			else if (menuOption == 4) 
			{
					cout << "Input type of delay (from a given list of delays)" << endl;
					cout << "Example: CARRIER" << endl;
					cout << "Type 'help' for a list of possible delays" << endl;
					bool v = false;
					while (!v)
					{
						cin >> input;
						//here is where you would append
						if (input == "help") {
							//help
							v = false;
						}
						else if (!validateS(input, m.delays))
						{
							cout << "Invalid carrier, type 'help' for a list of valid codes" << endl;
							v = false;
						}
						else {
							v = true; //valid
						}
					}
					clock_t t = clock();
					m.Option4(input);
					t = clock() - t;
					cout << "Run time: " << (float)t / CLOCKS_PER_SEC << " seconds" << endl;
			}
			else if (menuOption == 5)
			{
				cout << "Input a departure time (in military standard time)" << endl;
				cout << "Example: 0800" << endl;
				cout << "Times can be between 0000 and 2359" << endl;
				cin >> input;
				clock_t t = clock();
				m.Option5(input); //check to see if the input is correct/numeric
				t = clock() - t;
				cout << "Run time: " << (float)t / CLOCKS_PER_SEC << " seconds" << endl;
			}
			else if (menuOption < 1 || menuOption > 6)
			{
				cout << "Invalid input" << endl;
			}
		}
	}
	if (structure == 2) { //if they chose option 2, graph
		int menuOption = 0;
		GraphS g;
		g.readData(set[make_pair(year, s)]);
		while (menuOption != 6) {
			string input, input2;
			MenuSelect();
			cin >> menuOption;
			bool help = true;
			if (menuOption == 1)
			{
				while (help) {
					cout << "Input a company (via company two letter identification code)" << endl;
					cout << "Example: DL" << endl;
					cout << "Type 'help' for a list of company identification codes" << endl;
					cin >> input;
					clock_t t = clock();
					if (input == "help") {
						//make list
	
					}
					else {
						g.Option1(input);
						help = false;
						t = clock() - t;
						cout << "Run time: " << t / 100 << " seconds" << endl;
					}
				}
			}
			else if (menuOption == 2)
			{
				while (help) {
					cout << "Input an origin airport and destination airport (via airport three letter identification code)" << endl;
					cout << "Example: ATL" << endl;
					cout << "Type 'help' for a list of airport identification codes" << endl;
					cin >> input;
					if (input == "help") {
						//make list
	
					}
					cout << endl;
					cout << "Destination: ";
					cin >> input2;
					clock_t t = clock();
					if (input2 == "help") {
						//make list
	
					}
					else {
						g.Option2(input, input2);
						help = false;
						t = clock() - t;
						cout << "Run time: " << t / 100 << " seconds" << endl;
					}
				}
			}
			else if (menuOption == 3)
			{
				while (help) {
					cout << "Input an airport (via three letter identification code)" << endl;
					cout << "Example: ATL" << endl;
					cout << "Type 'help' for a list of three letter identification codes" << endl;
					cin >> input;
					clock_t t = clock();
					if (input == "help") {
						//make list
	
					}
					else {
						g.Option3(input);
						help = false;
						t = clock() - t;
						cout << "Run time: " << t / 100 << " seconds" << endl;
					}
				}
			}
			else if (menuOption == 4)
			{
				while (help) {
					cout << "Input type of delay (from a given list of delays)" << endl;
					cout << "Example: CARRIER" << endl;
					cout << "Type 'help' for a list of possible delays" << endl;
					cin >> input;
					clock_t t = clock();
					if (input == "help") {
						//make list
	
					}
					else {
						g.Option4(input);
						help = false;
						t = clock() - t;
						cout << "Run time: " << t / 100 << " seconds" << endl;
					}
				}
			}
			else if (menuOption == 5)
			{
				cout << "Input a departure time (in military standard time)" << endl;
				cout << "Example: 0800" << endl;
				cout << "Times can be between 0000 and 2359" << endl;
				cin >> input;
				clock_t t = clock();
				g.Option5(input); //check to see if the input is correct/numeric
				t = clock() - t;
				cout << "Run time: " << t / 100 << " seconds" << endl;
			}
			else if (menuOption < 1 || menuOption > 6)
			{
				cout << "Invalid input" << endl;
			}
		}
	}
	return 0;
}
