/*
 * Room.h
 *
 *  Created on: 29 août 2013
 *      Author: jgintrand
 */

#ifndef ROOM_H_
#define ROOM_H_

#include <Foe.h>
#include <vector>
//#include <Character.h>

class Character;

class Room {
public:
	Room();
	Room(int x, int y);
	int getX() {return m_x;};
	int getY() {return m_y;};
	void addFoe(Foe f) { foes.push_back(f);};
	void removeFoe(Foe* f);
	void describe();
	void populate();
	int tier();
	Foe* getFoe(unsigned int index);
	void cpuPlay(Character* c);
	virtual ~Room();
private:
	const int _SIZE_TIER = 6;
	int m_x;
	int m_y;
	std::vector<Foe> foes;
};

#endif /* ROOM_H_ */
