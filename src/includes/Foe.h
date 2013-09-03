/*
 * Foe.h
 *
 *  Created on: 29 août 2013
 *      Author: jgintrand
 */

#ifndef FOE_H_
#define FOE_H_

#include <LivingBeing.h>
#include <string>
#include <Character.h>


class Foe : public LivingBeing {
public:
	Foe();
	std::string getName() {return m_name;};
	int getXP() { return m_expGiven;};
	int getAttackDamage() { return m_attack_damage;};
	virtual void useLifePotion(int life) { throw std::string("Invalid target");};
	void attack(Character* c);
	virtual ~Foe();
protected:
	int m_expGiven;
	int m_attack_damage;
	std::string m_name;
};

#endif /* FOE_H_ */
