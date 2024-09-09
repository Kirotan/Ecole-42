#include "DiamondTrap.hpp"

// Constructors & Desctructor

DiamondTrap::DiamondTrap(){

	ClapTrap::_name = "default_clap_name";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << ClapTrap::_name << " constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"){

	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << ClapTrap::_name << " name constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), FragTrap(copy), ScavTrap(copy){

	*this = copy;
	std::cout << "DiamondTrap copy constructor called." << std::endl;

}

DiamondTrap::~DiamondTrap(){

	std::cout << "DiamondTrap " << this->_name << " destructor called." << std::endl;
}

// DiamondTrap functions

void	DiamondTrap::whoAmI(){

	if (this->_hitPoints == 0) {
		std::cout << "DiamondTrap " << this->_name << " can't know who is he, he's knocked out." << std::endl;
		return;
	}
	if (this->_energyPoints > 1) {
	std::cout << "DiamondTrap" << this->_name << " is " << ClapTrap::_name << " !" << std::endl;
	this->_energyPoints -= 1;
	}
	else
		std::cout << "DiamondTrap " << this->_name << " doesn't have enought point energy for knowing who is he." << std::endl;
}

void	DiamondTrap::attack(const std::string &target){

	ScavTrap::attack(target);
}
