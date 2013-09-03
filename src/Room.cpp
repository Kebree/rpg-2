/*
 * Room.cpp
 *
 *  Created on: 29 août 2013
 *      Author: jgintrand
 */

#include <Foe.h>
#include <FoeCatalog.h>
#include <LivingBeing.h>
#include <Room.h>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

class Character;

using namespace std;
Room::Room(int x, int y) {
	m_x = x;
	m_y = y;
}

Room::~Room() {
	// TODO Auto-generated destructor stub
}

void Room::describe() {
	if(foes.size() == 0)
		cout << "There is  no  foe  in this room" <<endl;
	else {
		int i=1;
		for(vector<Foe>::iterator it = foes.begin(); it != foes.end(); ++it) {
			cout << "There is a " + (*it).getName() + "(" << i++ << ") - " << (*it).getLife() << " hp" << endl;
		}
	}
}

Foe* Room::getFoe(unsigned int index){
	if(index < 1 || index > foes.size()) {
		throw string("Invalid index !");
	}
	return &foes.at(index-1);
}

void Room::removeFoe(Foe* f) {
	for (unsigned i=0; i<foes.size(); ++i) {
		if (&(foes[i]) == f)
			foes.erase(foes.begin() + i);
	}
}

void Room::cpuPlay(Character* c) {
	for(Foe f : foes) {
		try {
			f.attack(c);
		} catch (string const& error) {
			cout << error <<endl;
		}
	}
}

int Room::tier() {
	return (m_x + m_y) / _SIZE_TIER;
}

void Room::populate() {
    int rd = (rand() % 3)  + 1;
    FoeCatalog fc;
    for(int i=0; i<rd; i++) {
    	Foe f = fc.getTier1();
    	Foe f2(f);
    	foes.push_back(f2);
    }
}

