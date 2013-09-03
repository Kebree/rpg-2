#include "Weapon.h"
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
int Weapon::getDamages() {
    int rd = rand() % (m_maxDamages - m_minDamages + 1) + m_minDamages;
    return rd;
}

string Weapon::getStatus() {
    stringstream sout;
    sout << m_name + " (" << m_minDamages << "-" << m_maxDamages << ") - " << m_weight << "kg" <<endl;
    return sout.str();
}

void Weapon::use(LivingBeing* target) {
	throw string("You can not use this item");
}

