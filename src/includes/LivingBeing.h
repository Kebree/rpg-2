/*
 * LivingBeing.h
 *
 *  Created on: 29 août 2013
 *      Author: jgintrand
 */

#ifndef LIVINGBEING_H_
#define LIVINGBEING_H_

#include <string>

class LivingBeing {
public:
    enum tryHitResult {NO_HIT, HIT, CRITICAL_HIT};
	LivingBeing();
	std::string getName() {return m_name;};
	bool is_dead() { return m_dead;};
	void takeDamages(int damages);
    void addLife(int life);
	virtual void useLifePotion(int life) = 0;
	int getLife() {return m_life;};
	tryHitResult hasHit();
	virtual ~LivingBeing();
protected:
    std::string m_name;
    int m_life;
    int m_maxLife;
    int m_mana;
    int m_maxMana;
    bool m_dead;
    unsigned int m_strength;
    unsigned int m_intelligence;
    unsigned int m_constitution;
    unsigned int m_spirit;
    unsigned int m_agility;
};

#endif /* LIVINGBEING_H_ */
