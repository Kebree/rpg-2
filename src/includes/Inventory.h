/*
 * Inventory.h
 *
 *  Created on: 2 sept. 2013
 *      Author: jgintrand
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <Item.h>
#include <vector>
#include <string>
#include <LivingBeing.h>

class Inventory {
public:
	Inventory();
	void addItem(Item* i);
	void useItem(int index, LivingBeing* target);
	std::string listing();

	virtual ~Inventory();
private:
	std::vector<Item*> m_items;
};

#endif /* INVENTORY_H_ */
