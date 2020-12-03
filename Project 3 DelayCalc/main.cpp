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
	cout << "Please select an option from the following menu:" << endl;
	cout << "1. Input a company (via company identification code)" << endl;
	cout << "2. Input an arrival location and a departure location" << endl;
	cout << "3. Input an airport (via three letter identification code)" << endl;
	cout << "4. Input type of delay" << endl;
	cout << "5. Input preferred departure time (example being 16:42)" << endl;
	cout << "6. Help" << endl;
	cout << "7. Exit" << endl;
	cout << endl;
}
bool validate(int input, vector<int> numbers)
{
	for(int i = 0; i < numbers.size(); i++)
	{
		if(input == numbers[i])
			return true;
	}
	cout << "Invalid input" << endl;
	return false;
}
void Option1(){
	// Input a company (via company identification code)
	cout << "Average delay time for X: " << endl;
	cout << "Most common delay issue for X: " << endl;
	cout << "Percentage of flights delayed for X: " << endl;
	cout << "Average travel time for X: " << endl;
	cout << "Number of planes launched by X: " << endl;
	cout << "Number of planes delayed by X: " << endl;
}
void Option2() {
	//Input and arrival location and a departure location
	cout << "Average delay time between X and Y: " << endl;
	cout << "Most common delay issue between X and Y: " << endl;
	cout << "Percentage of flights delayed between X and Y: " << endl;
	cout << "Average taxi-out time at airport X: " << endl;
	cout << "Average taxi-in time at airport Y: " << endl;
	cout << "Number of planes launched between X and Y: " << endl;
	cout << "Number of planes delayed between X and Y: " << endl;
}
void Option3() {
	//Input an airport (via three letter identification code)
	cout << "Average delay time at X: " << endl;
	cout << "Most common delay issue at X: " << endl;
	cout << "Most common airline flown at X: " << endl;
	cout << "Percentage of flights delayed at X: " << endl;
	cout << "Number of flights to X: " << endl;
	cout << "Number of flights from X: " << endl;
}
void Option4() {
	//Input type of delay


}
void Option5() {
	//Input preferred departure time (example being 16:42)


}
int main() {
	Display();
	bool valid = false;
	int year, structure, menuOption;
	while(!valid)
	{
		cout << "Please enter a year between 2016 and 2018: " << endl;
		cin >> year;
		valid = validate(year, {2016, 2017, 2018});
	}
	valid = false;
	while(!valid)
	{
		cout << "Please select a data structure to test: " << endl;
		cout << "1. Map" << endl;
		cout << "2. Directed Graph" << endl;
		cin >> structure;
		valid = validate(structure, {1,2});
	}
	valid = false;
	if (structure == 1) {
		clock_t t = clock();
		MapS m(year);
		while (menuOption != 8) {
			MenuSelect();
			cin >> menuOption;
			t = clock() - t;
			cout << "Run time: " << t / 100 << " seconds" << endl;
		}
		return 0;
	}
	else if (structure == 2) {
		clock_t t = clock();
		GraphS g(year);
		while (menuOption != 8) {
			MenuSelect();
			cin >> menuOption;
			t = clock() - t;
			cout << "Run time: " << t / 100 << " seconds" << endl;
		}
		return 0;
	}
}
