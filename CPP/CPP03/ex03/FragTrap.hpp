#pragma once
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class FragTrap : public virtual ClapTrap {

	public :
	//Constructors & Destructor
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		~FragTrap();

	// SUrcharge operator
		FragTrap	&operator=(const FragTrap &copy);

	//FragTrap functions
		void highFivesGuys(void);

};
