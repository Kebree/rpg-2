/*
 * LittleLifePotion.cpp
 *
 *  Created on: 2 sept. 2013
 *      Author: jgintrand
 */

#include "LittleLifePotion.h"

LittleLifePotion::LittleLifePotion() {
	m_weight = 0.2;
	m_name = "Little potion of life";
	m_description = "Restore a small amount of life (5hp)";
}

LittleLifePotion::~LittleLifePotion() {
	// TODO Auto-generated destructor stub
}

void LittleLifePotion::use(LivingBeing* target) {
	target->useLifePotion(5);
}
