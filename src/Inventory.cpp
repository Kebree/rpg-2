/*
 * Inventory.cpp
 *
 *  Created on: 2 sept. 2013
 *      Author: jgintrand
 */

#include <Inventory.h>
#include <Item.h>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

class LivingBeing;

using namespace std;

Inventory::Inventory() {
	// TODO Auto-generated constructor stub

}

Inventory::~Inventory() {
	// TODO Auto-generated destructor stub
}

void Inventory::addItem(Item* i) {
	m_items.push_back(i);
}

void Inventory::useItem(int index, LivingBeing* target) {
	if(index >= m_items.size() || index < 0)
		throw string("Invalid item");
	Item* it = m_items[index];
	it->use(target);
	m_items.erase(m_items.begin()+index);
}

string Inventory::listing() {
	int i = 0;
	stringstream sout;
	for(Item* item : m_items) {
		sout << i++ << " : " + item->getName() << " : " + item->getDescription()<< endl;
	}
	return sout.str();
}

