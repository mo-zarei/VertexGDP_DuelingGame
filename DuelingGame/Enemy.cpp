#include "Enemy.h"
#include <iostream>
#include <random>
#include <vector>

Enemy::Enemy(int Health, int MaxHealth, int Stamina, int MaxStamina, std::string Name)
	: Character(Health, MaxHealth, Stamina, MaxStamina, Name)
{
}

CharacterAction Enemy::ChooseAction()
{
	// Build a list of possible actions based on current Stamina
	std::vector<CharacterAction> possibleActions;
	possibleActions.push_back(CharacterAction::Defend);

	// If Stamina is more than 1, the enemy can Attack 
	if (Stamina >= 1)
	{
		possibleActions.push_back(CharacterAction::Attack);
	}
	// If Stamina is more than 2, the enemy can Parry 
	if (Stamina >= 2)
	{
		possibleActions.push_back(CharacterAction::Parry);
	}

	// Randomly select one of the possible actions
	int idx = GetRandomInt(0, possibleActions.size() - 1);
	return possibleActions[idx];
}


int Enemy::GetRandomInt(int LowerRange, int HigherRange)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(LowerRange, HigherRange);
	return distrib(gen);
}
