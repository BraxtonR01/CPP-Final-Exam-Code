#include <string>
#include <iomanip>
#include <iostream>
#include <array>
#include "Character.h"
#include "MapTile.h"
#include <fstream>
#include "Mage.h"

/*
Pointers *
Classes (separating interface from implementation) *
Inheritance *
Polymorphism *
Operator Overloading *
File Processing *
Function Template *
Arrays/Vectors *
*/

using namespace std;

template <typename T>
std::string getCharacterType(T checkType) {
	return typeid(checkType).name();
}

Mage inputMage() {
	Mage character;
	int attack;
	int health;
	string name;

	Character* charptr = &character;
	ifstream iFile("Mage.txt", ios::in);

	if (!iFile) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	while (iFile >> name >> health >> attack) {
	}

	int mana = 50;
	double defense = .1;
	cout << "Enter 'a' to upgrade attack or 'h' to upgrade your health: " << endl;
	char up1;
		cin >> up1;
	switch (up1) {
	case 'a':
		attack += 150;
		break;
	case 'h':
		health += 350;
		break;
	default:
		break;
	}
	charptr->setName(name);
	charptr->setCurrentHealth(health);
	charptr->setMaxHealth(health);
	charptr->setMaxAttackPower(attack);
	charptr->setDefense(defense);
	character.setMana(mana);
	return character;
}

Character inputCharacter() {

	Character character;
	int attack;
	int health;
	string name;

	ifstream iFile("Character.txt", ios::in);

	if(!iFile) {
		cerr << "File could not be opened" << endl;
		exit(1);
	}

	while(iFile >> name >> health >> attack) {
	}

	double defense = .1;
	cout << "Enter 'a' to upgrade attack or 'h' to upgrade your health: " << endl;

	char up1;
		cin >> up1;
	switch (up1) {
		case 'a':
			attack += 150;
			break;
		case 'h':
			health += 350;
			break;
		default:
			break;
	}
	character.setName(name);
	character.setCurrentHealth(health);
	character.setMaxHealth(health);
	character.setMaxAttackPower(attack);
	character.setDefense(defense);
	return character;
}

void showStats(Character c) {
	cout << endl;
	cout << "Your Character" << endl;
	cout << "~~~~~~~~~~~~~~~~~" << endl;
	cout << "Name: " << c.getName() << endl;
	cout << "Maximum Health: " << c.getMaxHealth() << endl;
	cout << "Current Health: " << c.getCurrentHealth() << endl;
	cout << "Current Defense: " << c.getDefense() << endl;
	cout << "Max Attack Power: " << c.getMaxAttackPower() << endl;
	cout << "Current State: " << c.getStateText() << endl;
	cout << endl;
}
void attack(Character& c, Character& e, bool player, int dmg) {
	//if true, player is attacking; if false, player is being attacked
	if (player == true) {
		cout << c.getName() << " attacked a " << e.getName() << " for " << c.attack() << "damage!" << endl;
			e.takeDamage(dmg);
	}
	else {
		cout << c.getName() << " was attacked for " << c.takeDamage(dmg) << " damage by a" << e.getName() << "!" << endl;
	}
}


int changePosition(int p, char d) {
	if (p < 0 && d == 'w') {
		cout << "You have reached the end of this path, select a different option." << endl;
		return p;
	}
	if (d == 'w') {
		cout << "You moved west" << endl;
		return p-1;
	}
	if (p > 2 && d == 'e') {
		cout << "You have reached the end of this path, select a different option." << endl;
		return p;
	}
	if (d == 'e') {
		cout << "You moved east" << endl;
		return p+1;
	}
}

void displayMenu() {

	cout << "1. Move West" << endl;
	cout << "2. Move East" << endl;
	cout << "3. Heal" << endl;
	cout << "0. End game" << endl;
}

int tileMenu() {
	int input = -1;
	cout << "1. Attack" << endl;
	cout << "2. Heal"<< endl;
	cout << "Enter your choice: ";
	cin >> input;
	return input;

}

void tileInteract(MapTile m, Character* c) {
	cout << m.getDescription() << endl;
	cout << "There are " << m.numEnemiesLeft() << " enemies on this tile." << endl;
	int input = -1;

	while (input != 0) {
		do {
			input = tileMenu();
			if (input == 1) {
				if (getCharacterType(c) == "class Mage") {
					Mage* derivedPtr = dynamic_cast<Mage*>(c);
					if (derivedPtr != nullptr) {
						c->castSpell(m.getNextEnemy());
					}
				}
				else {
					int dmg = c->attack();
					m.getNextEnemy()->takeDamage(dmg);
					cout << "You dealt " << dmg << " damage!" << endl;
					if (m.hasEnemiesLeft()) {
						dmg = m.getNextEnemy()->attack();
						c->takeDamage(dmg);
						cout << "The enemy retaliated and did " << dmg << " damage." << endl;
					}
					else {
						return;
					}

				}
				cout << "Your health is currently : " << c->getCurrentHealth() << endl;
				cout << "The current enemy's health is : " << m.getNextEnemy()->getCurrentHealth() << endl;
				cout << "There are currently " << m.numEnemiesLeft() << " total enemies left." << endl;
			}
			if (input == 2) {
				c->heal(150);
				cout << "You just healed for 150";
				cout << "Your health is currently : " << c->getCurrentHealth() << endl;
			}

		} while (m.hasEnemiesLeft());
		cout << "There are no enemies left and you can move on!" << endl;
		return;
	}
}


int main()
{
	string pChoice;
	cout << "Would you like to play as a mage or a brute? (Enter 'm' for mage and 'b' for brute): " << endl;
	cin >> pChoice;
	cout << "test" << endl;
	Character enemy1{ "Zombie", 1000, 1000, 100, .05 };
	Character enemy2{ "Zombie", 1000, 1000, 100, .05 };
	Character enemy3{ "Zombie", 1000, 1000, 100, .05 };
	Character enemy4{ "Zombie", 1000, 1000, 100, .05 };
	Character enemy5{ "Skeleton", 700, 700, 150, .05 };
	Character enemy6{ "Skeleton", 700, 700, 150, .05 };
	Character enemy7{ "Zombie Boss", 1500, 1500, 200, .1 };

	Character* ptr1;
	Character* ptr2;
	Character* ptr3;
	Character* ptr4;
	Character* ptr5;
	Character* ptr6;
	Character* ptr7;

	ptr1 = &enemy1;
	ptr2 = &enemy2;
	ptr3 = &enemy3;
	ptr4 = &enemy4;
	ptr5 = &enemy5;
	ptr6 = &enemy6;
	ptr7 = &enemy7;

	vector<Character*> v1 = { ptr1, ptr2, ptr3 };
	vector<Character*> v2 = { ptr4 };
	vector<Character*> v3 = { ptr5, ptr6 };
	vector<Character*> v4 = { ptr7 };

	MapTile e1("A small cave with some enemies inside", v1, 3);
	MapTile w1("A river with a bridge over the top", v2, 1);
	MapTile w2("A hill with skeletons on either side", v3, 2);
	MapTile w3("A chest being guarded by a huge zombie", v4, 1);

	bool posE1 = false;
	bool posW1 = false;
	bool posW2 = false;
	bool posW3 = false;

	if (pChoice == "b") {
		Character c = inputCharacter();
		showStats(c);
		int position = 0;
		int input = -1;
		Character* charptr = &c;
		while (input != 0) {
			cout << "Your position is : " << position << endl;
			displayMenu();
			cout << "What would you like to do now: ";
			cin >> input;
			switch (input) {
			case 1:
				position = changePosition(position, 'w');
				break;
			case 2:
				position = changePosition(position, 'e');
				break;
			case 3:
				c.fullHeal();
				break;
			case 0:
				cout << "Thank you for playing!";
			}

			switch (position) {
			case -1:
				if (!posE1) {
					posE1 = true;
					tileInteract(e1, charptr);
				}
				break;
			case 1:
				if (!posW1) {
					posW1 = true;
					tileInteract(w1, charptr);
				}
				break;
			case 2:
				if (!posW2) {
					posW2 = true;
					tileInteract(w2, charptr);
				}
				break;
			case 3:
				if (!posW3) {
					posW3 = true;
					tileInteract(w3, charptr);
				}
				break;
			}

		}
	}
	else	{
		cout << "test" << endl;
		Mage m = inputMage();
		showStats(m);
		int position = 0;
		int input = -1;
		Mage* mageptr = &m;
		while (input != 0) {
			cout << "Your position is : " << position << endl;
			displayMenu();
			cout << "What would you like to do now: ";
			cin >> input;
			switch (input) {
			case 1:
				position = changePosition(position, 'w');
				break;
			case 2:
				position = changePosition(position, 'e');
				break;
			case 3:
				m.fullHeal();
				break;
			case 0:
				cout << "Thank you for playing!";
			}

			switch (position) {
			case -1:
				if (!posE1) {
					posE1 = true;
					tileInteract(e1, mageptr);
				}
				break;
			case 1:
				if (!posW1) {
					posW1 = true;
					tileInteract(w1, mageptr);
				}
				break;
			case 2:
				if (!posW2) {
					posW2 = true;
					tileInteract(w2, mageptr);
				}
				break;
			case 3:
				if (!posW3) {
					posW3 = true;
					tileInteract(w3, mageptr);
				}
				break;
			}

		}
	}
}


	
