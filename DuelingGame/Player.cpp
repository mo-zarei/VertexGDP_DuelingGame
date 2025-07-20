#include "Player.h"
#include <iostream>

Player::Player(int Health, int MaxHealth, int Stamina, int MaxStamina, std::string Name)
	: Character(Health, MaxHealth, Stamina, MaxStamina, Name)
{
}

CharacterAction Player::ChooseAction()
{
	int action;
	bool IsValidResult = false;

	while (!IsValidResult)
	{
		std::cout << "Choose an Action: 1:Attack, 2:Parry, 3:Defend" << std::endl;
		std::cin >> action;

		IsValidResult = ValidateAction(action);
	}

	switch (action)
	{
	case 1:
		return CharacterAction::Attack;
	case 2:
		return CharacterAction::Parry;
	case 3:
		return CharacterAction::Defend;
	}
}

bool Player::ValidateAction(int ActionInput)
{
	switch (ActionInput)
	{
		//Attack
	case 1:
		if (Stamina < 1)
		{
			std::cout << "Not enogh Stamina for Attack, Stamina: " << Stamina << std::endl;
			return false;
		}
		break;
		//Parry
	case 2:
		if (Stamina < 2)
		{
			std::cout << "Not enogh Stamina for Parry, Stamina: " << Stamina << std::endl;
			return false;
		}
		break;
		//Defend
	case 3:
		return true;
		break;
	default:
		std::cout << "Invalid input, input should be 1, 2 or 3 " << std::endl;
		return false;
		break;
	}

	return true;
}
