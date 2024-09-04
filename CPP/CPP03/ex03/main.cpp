#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(){

	FragTrap	Kiro("bebere");
	
	Kiro.highFivesGuys();
	Kiro.attack("dragon");
	Kiro.takeDamage(95);
	// Kiro.takeDamage(5);
	Kiro.takeDamage(1);
	Kiro.attack("zombie");
	for (int i = 0; i < 100; i++)
		Kiro.highFivesGuys();
	Kiro.attack("chicken");
	
	
}