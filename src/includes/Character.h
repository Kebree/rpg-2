#ifndef CHARACTER_H
#define CHARACTER_H

#include <LivingBeing.h>
//#include "Weapon.h"
#include <string>
#include <Inventory.h>

class Weapon;

class Foe;
class Map;

class Character :public LivingBeing
{
    public:
        Character(std::string name);
        virtual ~Character();
        void setWeapon(Weapon *w);
        void hit(Foe* target);
        std::string getStatus();
        void levelUp();
        void lookRoom();
        void addXP(int xp);
    	virtual void useLifePotion(int life);
        void spent(std::string carac, int value);
        void changeRoom(std::string direction);
        Map* getMap();
        Inventory* getInventory() {return m_inventory;};
        static unsigned int levelStep(int n);
    protected:
    private:
        Weapon* m_weapon;
        unsigned int m_level;
        unsigned int m_experience;
        short m_unspent;
        Map* m_map;
        Inventory* m_inventory;
};

#endif // CHARACTER_H
