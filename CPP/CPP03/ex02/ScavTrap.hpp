#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

	public :
	//Constructors & Destructor
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();

	//ScavTrap functions
		void attack(const std::string& target);
		void guardGate();

	// Surcharge operator
		ScavTrap	&operator=(const ScavTrap &copy);

	protected :
		bool	_isGuardingGate;

};
