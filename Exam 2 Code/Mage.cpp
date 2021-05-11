#include "Mage.h"
#include "Character.h"
#include <iostream>
#include <string>

using namespace std;
Mage::Mage()
{
}
Mage::Mage(int mana, std::string n, int mh, int h, int ma, double d) : Character(n, mh, h, ma, d){
	setMana(mana);
}

void Mage::setMana(int ma) {
	maxMana = ma;
	curMana = ma;
}

int Mage::getMana() {
	return curMana;
}

void Mage::regainMana() {
	curMana += 15;
	if (curMana > maxMana) {
		curMana = maxMana;
	}
	cout << "15 Mana regained!" << endl;
}

void Mage::castSpell(Character* target) {
	if (curMana > 0) {
		int dmg = attack();
		target->takeDamage(dmg);
		cout << "You dealt " << dmg << " damage with a spell and lost 10 mana." << endl;
		curMana -= 10;
		takeDamage(target->attack());
	}
	else {
		cout << "You do not have enough mana." << endl;
	}
}