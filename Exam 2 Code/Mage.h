#pragma once
#include "Character.h"
class Mage :
    public Character
{
public:
    Mage();
    Mage(int, std::string, int, int, int, double);
    virtual void castSpell(Character*);
    int getMana();
    void setMana(int);
    void regainMana();
private:
    int maxMana;
    int curMana;
};

