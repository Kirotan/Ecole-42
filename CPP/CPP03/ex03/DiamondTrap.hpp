#pragma once
#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {

	public :
	// Constructors & Desctructor
		DiamondTrap();
		DiamondTrap(const DiamondTrap &copy);
		DiamondTrap(std::string name);
		~DiamondTrap();

	// DiamondTrap functions
		void	whoAmI();
		void	attack(const std::string &target);

	private :
		std::string	_name;

};
