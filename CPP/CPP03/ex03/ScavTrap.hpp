#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap {

	public :
	//Constructors & Destructor
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		~ScavTrap();

	//ScavTrap functions
		void attack(const std::string& target);
		void guardGate();

	protected :
		bool	_isGuardingGate;

};
