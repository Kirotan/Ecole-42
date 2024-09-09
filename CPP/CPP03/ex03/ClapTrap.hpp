#pragma once
#include <iostream>

class ClapTrap {

	public :
	// Construtor and destructor
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		~ClapTrap();

	// ClapTrap functions
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	// Surcharge operator
		ClapTrap	&operator=(const ClapTrap &copy);

	protected :
		std::string			_name;
		unsigned short		_hitPoints;
		unsigned short		_energyPoints;
		unsigned short		_attackDamage;
};
