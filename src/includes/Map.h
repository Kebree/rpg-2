/*
 * Map.h
 *
 *  Created on: 29 août 2013
 *      Author: jgintrand
 */

#ifndef MAP_H_
#define MAP_H_

#include <Room.h>
#include <map>

class Map {
public:
	Map();
	Room* getRoom();
	bool existsRoom(int x, int y);
	void generateRoom(int x, int y);
	void changeRoom(int x,int y);
	int getX() { return m_cur_x;};
	int getY() { return m_cur_y;};
	std::string getCoordinate();
	virtual ~Map();
private:
	std::map<std::string, Room*> roomList;
	int m_cur_x;
	int m_cur_y;
};

#endif /* MAP_H_ */
