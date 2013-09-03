#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include "Item.h"


class Weapon : public Item
{
    public:
         int getDamages();
         std::string getStatus();
         virtual void use(LivingBeing* target);
    protected:
         int m_minDamages;
         int m_maxDamages;
         std::string m_name;
    private:
};

#endif // WEAPON_H
