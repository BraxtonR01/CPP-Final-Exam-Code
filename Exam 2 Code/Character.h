#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

class Character{
		
	public:
		static enum CharacterState{
			DEAD,
			BLOODY,
			NORMAL
		};

		Character();
		Character(std::string, int, int, int, double);
		int takeDamage(int);
		int attack();
		void fullHeal();
		void heal(int);
		int getMaxHealth();
		void setMaxHealth(int);
		int getCurrentHealth();
		void setCurrentHealth(int);
		int getMaxAttackPower();
		void setMaxAttackPower(int);
		double getDefense();
		void setDefense(double);
		std::string getName();
		void setName(std::string);
		CharacterState getState();
		std::string getStateText();
		virtual void castSpell(Character*);

	private:
		void updateCharacterState();
		int maxHealth;
		int currentHealth;
		std::string name;
		CharacterState currentState;
		int maxAttackPower;
		double defense;
};
#endif