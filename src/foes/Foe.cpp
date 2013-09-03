/*
 * Foe.cpp
 *
 *  Created on: 29 août 2013
 *      Author: jgintrand
 */

#include <Character.h>
#include <Foe.h>
#include <LivingBeing.h>
#include <iostream>
#include <memory>
#include <string>

using namespace std;
Foe::Foe() {
	// TODO Auto-generated constructor stub

}

Foe::~Foe() {
	// TODO Auto-generated destructor stub
}

void Foe::attack(Character* c) {
	LivingBeing::tryHitResult res = this->hasHit();
	if(res == LivingBeing::tryHitResult::NO_HIT)
		throw string(this->m_name+" missed !");
	int damages = m_attack_damage;
	if(res == LivingBeing::tryHitResult::CRITICAL_HIT) {
		cout << "Critical hit ! ";
		damages *= 2;
	}
	cout<< m_name + " hits "+ c->getName() +" for " << damages << " damages" <<endl;
	c->takeDamages(damages);
}
