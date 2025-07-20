#include "GameLoop.h"
#include "Player.h"
#include "Enemy.h"
#include <iostream>

GameLoop::GameLoop(Player& playerRef, Enemy& enemyRef, std::string level)
	: PlayerRef(playerRef), EnemyRef(enemyRef), Level(level)
{
}

std::string CharacterActionToString(CharacterAction action)
{
	switch (action)
	{
	case Attack: return "Attack";
	case Parry:  return "Parry";
	case Defend: return "Defend";
	default:     return "Unknown";
	}
}

bool GameLoop::StartLoop()
{
	std::cout << "Starting the Game" << Level << std::endl;

	while (PlayerRef.GetIsAlive() && EnemyRef.GetIsAlive())
	{
		PlayerRef.PrintCharacterInfo();
		EnemyRef.PrintCharacterInfo();

		std::cout << "-------------------------------------" << std::endl;

		CharacterAction playerAction = PlayerRef.ChooseAction();
		std::cout << "Player Action:" << CharacterActionToString(playerAction) << std::endl;

		CharacterAction enemyAction = EnemyRef.ChooseAction();
		std::cout << "Enemy Action:" << CharacterActionToString(enemyAction) << std::endl;

		std::cout << "-------------------------------------" << std::endl;

		if (playerAction == CharacterAction::Attack && enemyAction == CharacterAction::Parry)
		{
			AttackAndParry(PlayerRef, EnemyRef);
		}
		else if (playerAction == CharacterAction::Parry && enemyAction == CharacterAction::Attack)
		{
			AttackAndParry(EnemyRef, PlayerRef);
		}
		else if (playerAction == CharacterAction::Attack && enemyAction == CharacterAction::Defend)
		{
			AttackAndDefend(PlayerRef, EnemyRef);
		}
		else if (playerAction == CharacterAction::Defend && enemyAction == CharacterAction::Attack)
		{
			AttackAndDefend(EnemyRef, PlayerRef);
		}
		else if (playerAction == CharacterAction::Parry && enemyAction == CharacterAction::Defend)
		{
			DefendAndParry(EnemyRef, PlayerRef);
		}
		else if (playerAction == CharacterAction::Defend && enemyAction == CharacterAction::Parry)
		{
			DefendAndParry(PlayerRef, EnemyRef);
		}
		else if (playerAction == CharacterAction::Attack && enemyAction == CharacterAction::Attack)
		{
			BothAttack(PlayerRef, EnemyRef);
		}
		else if (playerAction == CharacterAction::Parry && enemyAction == CharacterAction::Parry)
		{
			BothParry(PlayerRef, EnemyRef);
		}
		else if (playerAction == CharacterAction::Defend && enemyAction == CharacterAction::Defend)
		{
			BothDefend(PlayerRef, EnemyRef);
		}

		std::cout << "-------------------------------------" << std::endl;
	}

	return PlayerRef.GetIsAlive();
}

void GameLoop::AttackAndDefend(Character& attacker, Character& defender)
{
	std::cout << "Nice Attack " << attacker.GetName() << std::endl;
	attacker.UpdateStamina(-1);
	defender.UpdateStamina(1);
	defender.UpdateHealth(-1);
}

void GameLoop::AttackAndParry(Character& attacker, Character& parrier)
{
	std::cout << "Nice Counter Attack!" << parrier.GetName() << std::endl;
	attacker.UpdateStamina(-1);
	parrier.UpdateStamina(-2);
	attacker.UpdateHealth(-2);
}

void GameLoop::DefendAndParry(Character& defender, Character& parrier)
{
	std::cout << "Parry & Defend!" << std::endl;
	parrier.UpdateStamina(-2);
	defender.UpdateStamina(1);
}

void GameLoop::BothAttack(Character& characterOneRef, Character& characterTwoRef)
{
	std::cout << "Both Attaks, Clash" << std::endl;
	characterOneRef.UpdateStamina(-1);
	characterTwoRef.UpdateStamina(-1);
}

void GameLoop::BothParry(Character& characterOneRef, Character& characterTwoRef)
{
	std::cout << "Both Counter Attack, Clash!" << std::endl;
	characterOneRef.UpdateStamina(-2);
	characterTwoRef.UpdateStamina(-2);
}

void GameLoop::BothDefend(Character& characterOneRef, Character& characterTwoRef)
{
	std::cout << "Both Defend!" << std::endl;
	characterOneRef.UpdateStamina(1);
	characterTwoRef.UpdateStamina(1);
}