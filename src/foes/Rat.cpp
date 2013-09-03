/*
 * Rat.cpp
 *
 *  Created on: 29 août 2013
 *      Author: jgintrand
 */

#include "Rat.h"

Rat::Rat() {
	m_life = 5;
	m_maxLife = 5;
	m_maxMana = 0;
	m_expGiven = 5;
	m_name = "rat";
	m_attack_damage = 1;
	m_strength = 0;
	m_agility = 0;
	m_intelligence = 0;
	m_constitution = 0;
	m_spirit = 0;
}

Rat::~Rat() {
	// TODO Auto-generated destructor stub
}

