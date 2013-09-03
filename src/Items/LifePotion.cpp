/*
 * LifePotion.cpp
 *
 *  Created on: 2 sept. 2013
 *      Author: jgintrand
 */

#include "LifePotion.h"

LifePotion::LifePotion() {
	m_weight = 0.5;
}

LifePotion::~LifePotion() {
}

void LifePotion::use(LivingBeing* target) {
	target->addLife(10);
}
