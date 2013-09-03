/*
 * LittleLifePotion.h
 *
 *  Created on: 2 sept. 2013
 *      Author: jgintrand
 */

#ifndef LITTLELIFEPOTION_H_
#define LITTLELIFEPOTION_H_

#include <LivingBeing.h>
#include <Item.h>
#include <memory>
#include <string>


class LittleLifePotion: public Item {
public:
	LittleLifePotion();
	virtual ~LittleLifePotion();
	virtual void use(LivingBeing* target);
};

#endif /* LITTLELIFEPOTION_H_ */
