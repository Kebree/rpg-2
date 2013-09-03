/*
 * Main.cpp
 *
 *  Created on: 2 sept. 2013
 *      Author: jgintrand
 */

#include <Character.h>
#include <Foe.h>
#include <LittleLifePotion.h>
#include <LivingBeing.h>
#include <Main.h>
#include <Map.h>
#include <Room.h>
#include <iostream>
#include <memory>
//#include <new>
#include <string>
#include <vector>

using namespace std;

Main::Main() : m_end(false), m_end_turn(false) {

}

Main::~Main() {
	//delete m_hero;
}

void Main::displayHelp(vector<string> args) {
	cout << "- help : display this help"<<endl;
	cout << "- quit : end the game"<<endl;
	cout << "- status : display the hero current status"<<endl;
	cout << "- go <north/south/west/east> : go to the next room"<<endl;
	cout << "- look : examine the current room"<<endl;
	cout << "- hit <number> : hit the foe targeted"<<endl;
	cout << "- spend <charac> <x> : spent <x> points into <charac> "<<endl;
	cout << "- use <x> : use the item number <x> "<<endl;
	cout << "- inventory : display inventory"<<endl;
	m_end_turn = false;
}

void Main::quit(vector<string> args) {
	cout << "Good bye !" <<endl;
	m_end = true;
	m_end_turn = false;
}



void Main::status(vector<string> args){
	cout << m_hero->getStatus() <<endl;
	m_end_turn = false;
}


void Main::changeRoom(std::vector<std::string> args){
	string dir = args.front();
	cout << "go "+dir <<endl;
	try {
		m_hero->changeRoom(dir);
	} catch (string const& error) {
		cout << error <<endl;
	}
	m_end_turn = false;
}

void Main::look(std::vector<std::string> args) {
	m_hero->lookRoom();
	m_end_turn = true;
}

void Main::hit(std::vector<std::string> args){
	if(args.size() < 1) {
		cout << "Missing argument"<<endl;
	}else {
		try {
			string s(args.at(0));
			Foe* f = m_hero->getMap()->getRoom()->getFoe(stoul(s));
			m_hero->hit(f);
			if (f->getLife() <= 0) {
				cout << f->getName() +" is dead, " << f->getXP() << " exp point reward" <<endl;
				m_hero->addXP(f->getXP());
				m_hero->getMap()->getRoom()->removeFoe(f);
			}
		} catch (string const& error) {
			cout << error <<endl;
		}
	}
	m_end_turn = true;
}

void Main::spend(std::vector<std::string> args){
	if(args.size() < 2) {
		cout << "Missing argument"<<endl;
	} else {
		string carac(args.at(0));
		string value(args.at(1));
		try {
			m_hero->spent(carac, stoi(value));
		} catch (string const& error) {
			cout << error <<endl;
		}
	}
}


void Main::useItem(std::vector<std::string> args){
	if(args.size() < 1) {
			cout << "Missing argument"<<endl;
		}else {
			try {
				string s(args.at(0));
				Inventory* i = m_hero->getInventory();
				i->useItem(stoul(s), m_hero);

			} catch (string const& error) {
				cout << error <<endl;
			}
		}
		m_end_turn = true;
	//LittleLifePotion p;
	//p.use(m_hero);
}

void Main::displayInventory(std::vector<std::string> args){
	cout << m_hero->getInventory()->listing() <<endl;
}
