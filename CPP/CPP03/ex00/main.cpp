#include "ClapTrap.hpp"

int	main(){

	ClapTrap	Kiro("Kiro");
	ClapTrap	Def;
	
	Kiro.attack("zombie");
	Kiro.takeDamage(5);
	// Kiro.takeDamage(6);
	Kiro.takeDamage(1);
	// for (int i = 0; i <= 10; i++)
	// 	Kiro.attack("dragon");
	Kiro.beRepaired(2);
	Kiro.attack("dragon");

}