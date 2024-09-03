#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class FragTrap : public ClapTrap {

	public :
	//Constructors & Destructor
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		virtual ~FragTrap();

	//FragTrap functions
		void highFivesGuys(void);

};