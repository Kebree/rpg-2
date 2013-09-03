/*
 * Main.h
 *
 *  Created on: 2 sept. 2013
 *      Author: jgintrand
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <map>
#include <string>
#include <vector>
#include <Character.h>


class Main {
public:
	Main();
	virtual ~Main();

	void Initialize();
	void displayHelp(std::vector<std::string> args);
	void quit(std::vector<std::string> args);
	void status(std::vector<std::string> args);
	void changeRoom(std::vector<std::string> args);
	void look(std::vector<std::string> args);
	void hit(std::vector<std::string> args);
	void spend(std::vector<std::string> args);
	void useItem(std::vector<std::string> args);
	void displayInventory(std::vector<std::string> args);
	void setHero(Character* hero) {m_hero = hero;};
	Character* getHero(){return m_hero;};
	bool isEnded() {return m_end;};
	bool turnEnd() {return m_end_turn;};
private:
	Character* m_hero;
	bool m_end;
	bool m_end_turn;
};

#endif /* MAIN_H_ */
