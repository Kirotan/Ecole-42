#pragma once
#include "ScavTrap.hpp"

class FragTrap : public ClapTrap {

	public :
	//Constructors & Destructor
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		~FragTrap();

	//FragTrap functions
		void highFivesGuys(void);

	// Surcharge operator
		FragTrap	&operator=(const FragTrap &copy);

};
