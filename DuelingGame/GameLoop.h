#pragma once
#include "Player.h"
#include "Enemy.h"

class GameLoop
{
public:
	GameLoop(Player& playerRef, Enemy& enemyRef, std::string level);

	bool StartLoop();
private:
	Player& PlayerRef;
	Enemy& EnemyRef;
	std::string Level;

	void AttackAndDefend(Character& attacker, Character& defender);
	void AttackAndParry(Character& attacker, Character& parrier);
	void DefendAndParry(Character& defender, Character& parrier);
	
	void BothAttack(Character& characterOneRef, Character& characterTwoRef);
	void BothParry(Character& characterOneRef, Character& characterTwoRef);
	void BothDefend(Character& characterOneRef, Character& characterTwoRef);

};

