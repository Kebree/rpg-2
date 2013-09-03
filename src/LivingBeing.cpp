/*
 * LivingBeing.cpp
 *
 *  Created on: 29 août 2013
 *      Author: jgintrand
 */

#include <LivingBeing.h>
#include <sys/types.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <random>

using namespace std;
LivingBeing::LivingBeing(): m_dead(false) {
	// TODO Auto-generated constructor stub

}

LivingBeing::~LivingBeing() {
	// TODO Auto-generated destructor stub
}

void LivingBeing::takeDamages(int damages) {
	m_life -= damages;
	if(m_life <= 0) {
		m_dead = true;
	}
}

LivingBeing::tryHitResult LivingBeing::hasHit() {
	int min = 100 - m_agility;
	int max = 950 - m_agility;
	int rd = rand() % 1000;
    if(rd < min)
    	return 	LivingBeing::tryHitResult::NO_HIT;
    if(rd >= max)
    	return 	LivingBeing::tryHitResult::CRITICAL_HIT;
    return LivingBeing::tryHitResult::HIT;
}

void LivingBeing::addLife(int life) {
	m_life += life;
	if(m_life > m_maxLife) {
		m_life = m_maxLife;
	}
}
