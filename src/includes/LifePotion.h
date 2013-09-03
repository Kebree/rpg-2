/*
 * LifePotion.h
 *
 *  Created on: 2 sept. 2013
 *      Author: jgintrand
 */

#ifndef LIFEPOTION_H_
#define LIFEPOTION_H_

#include <Character.h>
#include <Item.h>
#include <memory>
#include <string>

class LifePotion : public Item {
public:
	LifePotion();
	virtual ~LifePotion();
	virtual void use(LivingBeing* target);
};

#endif /* LIFEPOTION_H_ */
