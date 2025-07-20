#pragma once
#include "Character.h"

class Player : public Character
{
public:
	Player(int Health, int MaxHealth, int Stamina, int MaxStamina, std::string Name);

	CharacterAction ChooseAction() override;

private:
	bool ValidateAction(int ActionInput);

};