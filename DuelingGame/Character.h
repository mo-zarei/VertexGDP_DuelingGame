#pragma once
#include <string>
#include "CharacterAction.h"

class Character
{

public:
	Character(int Health, int MaxHealth, int Stamina, int MaxStamina, std::string Name);

	bool GetIsAlive() const { return Health > 0; }
	int GetHealth() const { return Health; }
	int GetStamina() const { return Stamina; }
	std::string GetName() const { return Name; }

	void UpdateHealth(int Amount);
	void UpdateStamina(int Amount);
	void PrintCharacterInfo();

	virtual CharacterAction ChooseAction() = 0;

protected:
	int Health;
	int MaxHealth;
	int Stamina;
	int MaxStamina;
	std::string Name;
};

