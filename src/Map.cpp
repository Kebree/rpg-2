/*
 * Map.cpp
 *
 *  Created on: 29 août 2013
 *      Author: jgintrand
 */

#include <Map.h>
#include <Rat.h>
#include <Room.h>
#include <map>
#include <memory>
#include <new>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

string createKey(int x, int y) {
	stringstream sout;
	sout << x << "-" << y;
	return sout.str();
}

Map::Map() {
	Room* firstRoom = new Room(0,0);
	roomList[createKey(0,0)] = firstRoom;
	m_cur_x = 0;
	m_cur_y = 0;
	Rat r;
	firstRoom->addFoe(r);
	Rat r2;
	firstRoom->addFoe(r2);
}

Room* Map::getRoom() {
	return roomList.at(createKey(m_cur_x,m_cur_y));
}
Map::~Map() {
	roomList.clear();
}

bool Map::existsRoom(int x, int y) {
	return roomList.count(createKey(x,y))>0;
}

void Map::generateRoom(int x, int y) {
	Room* r = new Room(x,y);
	r->populate();
	roomList[createKey(x,y)] = r;
}

void Map::changeRoom(int x, int y) {
	m_cur_x = x;
	m_cur_y = y;
}

string Map::getCoordinate() {
	stringstream sout;
	sout << m_cur_x << " - " << m_cur_y<<endl;
	return sout.str();
}
