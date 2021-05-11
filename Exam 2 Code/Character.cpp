#include "Character.h"
#include <string>
#include <random>
#include <iostream>

using namespace std;
Character::Character()
{
	setName("Gerard");
	setMaxHealth(500);
	setCurrentHealth(500);
	setMaxAttackPower(500);
	setDefense(0.1);
	srand(123456);
}

Character::Character(std::string n, int mh, int h, int ma, double d)
{
	setName(n);
	setMaxHealth(mh);
	setCurrentHealth(h);
	setMaxAttackPower(ma);
	setDefense(d);
	srand(123456);
}

int Character::takeDamage(int theDamage)
{
	int damageToTake = (theDamage - (defense * theDamage));
	setCurrentHealth(getCurrentHealth() - damageToTake);
	return damageToTake;
}

int Character::attack()
{
	int attackPercent = 75 + (rand() % (25 + 1));
	int attackPower = getMaxAttackPower() * (attackPercent/100.0);
	return attackPower;
}

void Character::fullHeal()
{
	setCurrentHealth(getMaxHealth());
	cout << "Your health is now: " << getCurrentHealth() << endl;
}

void Character::heal(int amountToHeal)
{
	if (getCurrentHealth() < 0 && amountToHeal > 0)
	{
		setCurrentHealth(0);
	}
	if (getCurrentHealth() + amountToHeal > getMaxHealth())
	{
		setCurrentHealth(getMaxHealth());
	}
	else
	{
		setCurrentHealth(getCurrentHealth() + amountToHeal);
	}
}

int Character::getMaxHealth()
{
	return maxHealth;
}

void Character::setMaxHealth(int health)
{
	maxHealth = health;
}

int Character::getMaxAttackPower()
{
	return maxAttackPower;
}

void Character::setMaxAttackPower(int ap)
{
	maxAttackPower = ap;
}

double Character::getDefense()
{
	return defense;
}

void Character::setDefense(double newDefense)
{
	defense = newDefense;
}

std::string Character::getName()
{
	return name;
}

void Character::setName(std::string newname)
{
	name = newname;
}

Character::CharacterState Character::getState()
{
	return currentState;
}

int Character::getCurrentHealth()
{
	return currentHealth;
}

std::string Character::getStateText()
{
	switch (getState())
	{
	case BLOODY:
		return "Bloody";
	case DEAD:
		return "Dead";
	case NORMAL:
		return "Normal";
	default:
		return "";
	}
}

void Character::castSpell(Character*)
{
}

void Character::setCurrentHealth(int newHealth)
{
	currentHealth = newHealth;
	updateCharacterState();
}

void Character::updateCharacterState()
{
	if (getCurrentHealth() < (getMaxHealth() / 2) && getCurrentHealth() > 0)
	{
		currentState = Character::BLOODY;
	}
	else if(getCurrentHealth() <= 0)
	{
		currentState = Character::DEAD;
	}
	else
	{
		currentState = Character::NORMAL;
	}
}