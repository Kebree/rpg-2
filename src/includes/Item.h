#ifndef ITEM_H
#define ITEM_H

#include <LivingBeing.h>
#include <string>

class Item
{
    public:
        Item();
        virtual ~Item();
        unsigned int Getweight() { return m_weight; }
        std::string getName() {return m_name;};
        std::string getDescription() { return m_description;};
        void Setweight(unsigned int val) { m_weight = val; }
    	virtual void use(LivingBeing* target) = 0;
    protected:
        float m_weight;
        std::string m_name;
        std::string m_description;
    private:
};

#endif // ITEM_H
