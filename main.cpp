/*
 * main.cpp
 *
 *  Created on: 29 août 2013
 *      Author: jgintrand
 */

#include <Character.h>
#include <LivingBeing.h>
#include <Main.h>
#include <Map.h>
#include <Room.h>
#include <RustedIronBlade.h>
#include <sys/types.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <map>
#include <new>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#define _MAX_PATH 100

using namespace std;



void StringExplode(string str, string separator, vector<string>* results);
static void Initialize();

typedef void(Main::*f_ptr)(std::vector<std::string>);

static std::map<std::string, f_ptr> mapString;

int main()
{
	srand (time(NULL));
    Character hero("Kebree");
    hero.setWeapon(new RustedIronBlade());
    Main m;
    m.setHero(&hero);
	Initialize();
	while(!m.isEnded()) {
		cout << "# ";
		char action[_MAX_PATH];
		cin.getline(action, _MAX_PATH);
		string s(action);
		vector<string> commandLine;
		StringExplode(action, " ", &commandLine);
		vector<string> args;
		for(unsigned int i=1; i<commandLine.size(); i++){
			args.push_back(commandLine[i]);
		}
		try {
			if(mapString.count(commandLine.front()) > 0)
				(m.*(mapString[commandLine.front()]))(args);
			else
				cout << "Command not found" << endl;;
		} catch (const out_of_range& oor) {
			cout << "Command not found" << endl;
		} catch (const std::exception& e) {
			cerr << e.what() <<endl;
		}
		if(m.turnEnd()){
			hero.getMap()->getRoom()->cpuPlay(&hero);
			if(hero.is_dead()) {
				cout << "You are dead !" <<endl;
				cout << hero.getStatus() <<endl;
				return 0;
			}
		}

	}
}

static void Initialize()
{
	mapString["help"] = &Main::displayHelp;
	mapString["quit"] = &Main::quit;
	mapString["status"] = &Main::status;
	mapString["go"] = &Main::changeRoom;
	mapString["look"] = &Main::look;
	mapString["hit"] = &Main::hit;
	mapString["spend"] = &Main::spend;
	mapString["use"] = &Main::useItem;
	mapString["inventory"] = &Main::displayInventory;
}

void StringExplode(string str, string separator, vector<string>* results){
    unsigned int found;
    found = str.find_first_of(separator);
    while(found != string::npos){
        if(found > 0){
            results->push_back(str.substr(0,found));
        }
        str = str.substr(found+1);
        found = str.find_first_of(separator);
    }
    if(str.length() > 0){
        results->push_back(str);
    }
}

