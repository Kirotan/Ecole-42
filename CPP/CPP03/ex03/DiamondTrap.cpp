#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){

	ClapTrap::_name = "default_clap_name";

	std::cout << "DiamondTrap " << ClapTrap::_name << " constructor called." << std::endl;
}


DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "clap_name"){

	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << ClapTrap::_name << " name constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy){

	*this = copy;
	std::cout << "DiamondTrap copy constructor called." << std::endl;

}

DiamondTrap::~DiamondTrap(){

	std::cout << "DiamondTrap " << this->_name << " destructor called." << std::endl;
}
