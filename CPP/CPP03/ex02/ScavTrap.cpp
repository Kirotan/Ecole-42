#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

//Constructors & Destructor

ScavTrap::ScavTrap() : ClapTrap(){

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_isGuardingGate = false;

	std::cout << "ScavTrap default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){

	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	this->_isGuardingGate = false;

	std::cout << "ScavTrap name constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy){

	this->_isGuardingGate = copy._isGuardingGate;
}

ScavTrap::~ScavTrap(){

	std::cout << "ScavTrap destructor called." << std::endl;
}


//ScavTrap functions

void	ScavTrap::attack(const std::string& target){

	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " can't attack any ennemy, he's knocked out." << std::endl;
		return;
	}
	if (this->_energyPoints > 1) {
	std::cout << "ScavTrap " << this->_name << " attack " << target << ", ";
	std::cout << "causing " << this->_attackDamage << " points of damage !" << std::endl;
	this->_energyPoints -= 1;
	}
	else
		std::cout << "ScavTrap " << this->_name << " doesn't have enought point energy for attacking " << target << "." << std::endl;
}

void	ScavTrap::guardGate(){

	if (this->_hitPoints == 0) {
		std::cout << "ScavTrap " << this->_name << " can't turn on Gate keeper mode, he's knocked out." << std::endl;
		return;
	}
	if (this->_isGuardingGate == false) {
		this->_isGuardingGate = true;
		std::cout << "ScavTrap " << this->_name << " turn on Gate keeper mode !" << std::endl;
	}
	else {
		this->_isGuardingGate = false;
		std::cout << "ScavTrap " << this->_name << " turn off Gate keeper mode." << std::endl;

	}
}
