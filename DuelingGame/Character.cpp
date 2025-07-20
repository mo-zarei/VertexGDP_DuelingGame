#include "Character.h"
#include <iostream>

Character::Character(int Health, int MaxHealth, int Stamina, int MaxStamina, std::string Name)
{
	this->Health = Health;
	this->MaxHealth = MaxHealth;
	this->Stamina = Stamina;
	this->MaxStamina = MaxStamina;
	this->Name = Name;
}


void Character::UpdateHealth(int Amount)
{
	Health = Health + Amount;
	if (Health < 0)
		Health = 0;
	else if (Health > MaxHealth)
		Health = MaxHealth;
}

void Character::UpdateStamina(int Amount)
{
	Stamina = Stamina + Amount;
	if (Stamina < 0)
		Stamina = 0;
	else if (Stamina > MaxStamina)
		Stamina = MaxStamina;
}

void Character::PrintCharacterInfo()
{
	std::cout << "Name: " << Name << " Health: " << Health << " Stamina: " << Stamina << std::endl;
}
