#include <Foe.h>
#include <Inventory.h>
#include <LittleLifePotion.h>
#include <LivingBeing.h>
#include <Room.h>

#include <Weapon.h>
#include <memory>
#include <new>
#include <string>

#include "Character.h"
#include <iostream>
#include <sstream>
#include "Map.h"

using namespace std;
Character::Character(string name)
{
    m_name = name;
    m_maxLife = 20;
    m_life = 20;
    m_mana = 10;
    m_maxMana = 10;
    m_level = 1;
    m_experience = 0;
    m_strength = 0;
    m_agility = 0;
    m_intelligence = 0;
    m_constitution = 0;
    m_spirit = 0;
    m_unspent = 0;
    m_map = new Map;
    m_inventory = new Inventory;
    m_inventory->addItem(new LittleLifePotion);
    m_inventory->addItem(new LittleLifePotion);
}

Character::~Character(){
    delete m_weapon;
    delete m_map;
    delete m_inventory;
}

void Character::setWeapon(Weapon *w) {
    m_weapon = w;
}

void Character::hit(Foe* target){
	LivingBeing::tryHitResult res = this->hasHit();
	if(res == LivingBeing::tryHitResult::NO_HIT)
		throw string("You missed !");
	int damages = m_weapon->getDamages();
	if(res == LivingBeing::tryHitResult::CRITICAL_HIT) {
		cout << "Critical hit ! ";
		damages *= 2;
	}
	cout<< m_name + " hits " + target->getName() + " for " << damages << " damages" <<endl;
	target->takeDamages(damages);
}

void Character::addXP(int xp) {
	m_experience += xp;
	if(m_experience >= Character::levelStep(m_level)) {
		this->levelUp();
	}
}

void Character::levelUp() {
	cout << "You leveled up ! You have some points to spent" <<endl;
    m_maxLife += 5;
    m_maxMana += 5;
    m_life = m_maxLife;
    m_mana = m_maxMana;
    m_unspent = 5;
    m_level += 1;
}

string Character::getStatus() {
	stringstream sout;
	sout << "Name : " + m_name <<endl;
	sout << "Level : " << m_level << " (" << m_experience << "/" << Character::levelStep(m_level) << ")" <<endl;
	stringstream s;
	s << "Life : ";
	(m_life > 0)? s << m_life << "/" << m_maxLife:s<<"dead";
	sout << s.str()  <<endl;
	sout << "Mana : " << m_mana << "/" << m_maxMana <<endl;
	sout << "STR : " << m_strength <<endl;
	sout << "AGI : " << m_agility <<endl;
	sout << "INT : " << m_intelligence <<endl;
	sout << "CON : " << m_constitution <<endl;
	sout << "SPI : " << m_spirit << endl;
    if(m_unspent > 0) {
    	sout << "** Unspent points : " << m_unspent << " **" <<endl;
    }
    sout << "Equipped weapon : " << m_weapon->getStatus();
    sout <<endl;
    return sout.str();
}

Map* Character::getMap() {
	return m_map;
}

void Character::lookRoom() {
	m_map->getRoom()->describe();
}

unsigned int Character::levelStep(int n) {
	int u = 10;
	int v = 20;
	int i, t;

	for(i = 2; i <= n; i++)
	{
		t = u + v;
		u = v;
		v = t;
	}
	return v-10;
}

void Character::spent(string carac, int value) {
	if(value > m_unspent) {
		throw string("You don't have enough point to spend");
	}
	if (carac == "STR") {
		m_strength += value;
	} else if (carac == "AGI") {
		m_agility += value;
	}else if (carac == "SPI") {
		m_spirit += value;
		m_maxMana += value;
		m_mana += value;
	}else if (carac == "CON") {
		m_constitution += value;
		m_maxLife += value;
		m_life += value;
	}else if (carac == "INT") {
		m_intelligence += value;
	} else {
		throw string("Characteristic not found");
	}

	m_unspent -= value;
}

void Character::changeRoom(std::string direction) {
	int x = m_map->getX();
	int y = m_map->getY();
	if(direction == "north") {
		x += 1;
	} else if(direction == "south") {
		x -= 1;
	} else if(direction == "west") {
		y -= 1;
	} else if(direction == "east") {
		y += 1;
	} else {
		throw string("Unvalaible direction !");
	}
	if(!m_map->existsRoom(x,y)) {
		m_map->generateRoom(x,y);
	}
	m_map->changeRoom(x,y);
}

void Character::useLifePotion(int life) {
	m_life += life;
	if(m_life > m_maxLife)
		m_life = m_maxLife;
}
