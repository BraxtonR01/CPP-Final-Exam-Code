#pragma once
#include <string>
#include "Character.h"
#include <vector>


using namespace std;

class MapTile {

public:
	void setDescription(string);
	string getDescription() const;
	bool hasEnemiesLeft();
	int numEnemiesLeft() const;
	Character* getNextEnemy();
	vector<Character*> getEnemyArray();
	void setEnemyArray(vector<Character*>, int);
	int getArraySize();
	MapTile();
	MapTile(string);
	MapTile(string, vector<Character*>, int);
	~MapTile();

	friend ostream& operator<<(ostream& output, const MapTile& m1);
private:
	int arraySize;
	string description;
	vector<Character*> enemies;
	int enemiesKilled;
};