/*
 * Worm.cpp
 *
 *  Created on: 30 août 2013
 *      Author: jgintrand
 */

#include "Worm.h"

Worm::Worm() {
	m_life = 7;
	m_maxLife = 5;
	m_maxMana = 0;
	m_expGiven = 6;
	m_name = "worm";
	m_attack_damage = 1;
	m_strength = 0;
	m_agility = 0;
	m_intelligence = 0;
	m_constitution = 0;
	m_spirit = 0;

}

Worm::~Worm() {
	// TODO Auto-generated destructor stub
}

