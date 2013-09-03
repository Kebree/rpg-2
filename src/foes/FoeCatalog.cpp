/*
 * FoeCatalog.cpp
 *
 *  Created on: 30 août 2013
 *      Author: jgintrand
 */

#include <Beetle.h>
#include <Foe.h>
#include <FoeCatalog.h>
#include <Rat.h>
#include <Worm.h>
#include <cstdlib>
//#include <iostream>
//#include <string>
#include <vector>

FoeCatalog::FoeCatalog() {
	Rat r;
	Worm w;
	Beetle b;
	Foe f = r;
	Foe f2 = w;
	Foe f3 = b;
	tier1.push_back(f);
	tier1.push_back(f2);
	tier1.push_back(f3);

}

FoeCatalog::~FoeCatalog() {
	// TODO Auto-generated destructor stub
}

Foe FoeCatalog::getTier1() {
	int rank = rand() % tier1.size();
	return tier1.at(rank);
}

