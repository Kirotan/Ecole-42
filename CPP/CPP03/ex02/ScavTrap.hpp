#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

class ScavTrap : public ClapTrap {

	public :
	//Constructors & Destructor
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		virtual ~ScavTrap();

	//ScavTrap functions
		void attack(const std::string& target);
		void guardGate();

	protected :
		bool	_isGuardingGate;
		
};