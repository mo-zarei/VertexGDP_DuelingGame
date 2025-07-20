#pragma once
#include "Character.h"

class Enemy :public Character
{
public:
	Enemy(int Health, int MaxHealth, int Stamina, int MaxStamina, std::string Name);

	CharacterAction ChooseAction() override;

private:
	int GetRandomInt(int LowerRange, int HigherRange);
};