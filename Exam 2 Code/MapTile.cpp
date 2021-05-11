#pragma once
#include <string>
#include "Character.h"
#include "MapTile.h"
#include <iomanip>
#include <iostream>
#include <array>

using namespace std;

MapTile::MapTile() {
	setDescription("N/A");
	vector<Character*> t; 
	
	Character enemy1{ "Zombie", 1000, 1000, 100, .05 };
	Character enemy2{ "Zombie", 1000, 1000, 100, .05 };
	Character enemy3{ "Zombie", 1000, 1000, 100, .05 };

	Character* ptr1;
	Character* ptr2;
	Character* ptr3;

	ptr1 = &enemy1;
	ptr2 = &enemy2;
	ptr3 = &enemy3;

	t.push_back(ptr1);
	t.push_back(ptr2);
	t.push_back(ptr3);

	setEnemyArray(t, 3);
	enemiesKilled = 0;
}

MapTile::~MapTile()
{

}

MapTile::MapTile(string desc) {
	setDescription(desc);
}

MapTile::MapTile(string desc, vector <Character*> arr, int sze)
{
	setDescription(desc);
	arraySize = sze;
	setEnemyArray(arr, sze);
	enemiesKilled = 0;
}

void MapTile::setDescription(string desc) {
	description = desc;
}

string MapTile::getDescription() const {
	return description;
}

bool MapTile::hasEnemiesLeft() {
	if (numEnemiesLeft() < 1) {
		return false;
	}
	else {
		return true;
	}
}

int MapTile::numEnemiesLeft() const{

	int counter = 0;
	for (int x = 0; x < enemies.size(); x++) {
		Character* temp = enemies.at(x);
		if (temp->getCurrentHealth() > 0) {
			counter++;
		}
	}
	return counter;
}

Character* MapTile::getNextEnemy() {
	try {
		for (Character* enemy : enemies) {
			if (enemy->getCurrentHealth() > 0) {
				return enemy;
			}
		}
	}
	catch(int e){
		cout << "There are no enemies left" << endl;
	}
}

vector<Character*> MapTile::getEnemyArray() {
	return enemies;
}

void MapTile::setEnemyArray(vector<Character*> arr, int sze) {
	enemies = arr;
}

int MapTile::getArraySize() {
	return arraySize;
}

std::ostream& operator<<(std::ostream& output, const MapTile& m1)
{
	output << m1.getDescription() << " - Enemies left: " << m1.numEnemiesLeft();
	return output;
}