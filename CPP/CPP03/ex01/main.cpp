#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(){

	ScavTrap	Kiro("bebere");

	Kiro.guardGate();
	Kiro.attack("dragon");
	Kiro.takeDamage(95);
	// Kiro.takeDamage(5);
	Kiro.takeDamage(1);
	Kiro.attack("zombie");
	Kiro.guardGate();
	// for (int i = 0; i < 50; i++)
	// 	Kiro.attack("plante");
	Kiro.guardGate();
	Kiro.attack("chou");

}
