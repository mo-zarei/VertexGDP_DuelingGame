#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "GameLoop.h"

int main()
{
    std::cout << "Hello World!\n";

	// Initialize player and enemy characters
	Player player(5, 5, 3, 3, "Hero");
	Enemy enemy(4, 4, 3, 3, "Villain");
	// Create game loop instance
	GameLoop gameLoop(player, enemy, "Level 1");
	// Start the game loop
	if (gameLoop.StartLoop())
	{
		std::cout << "You Won! Thanks for playing!" << std::endl;
	}
	else
	{
		std::cout << "You Lost! Thanks for playing!" << std::endl;
	}

	return 0;
}


