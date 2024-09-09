#include "ClapTrap.hpp"

//Constructor & Destructor

ClapTrap::ClapTrap() : _name("default"), _hitPoints(10), _energyPoints(10), _attackDamage(0){

	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){

	std::cout << "Name constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){

	std::cout << "Copy constructor called." << std::endl;

	*this = copy;
}

ClapTrap::~ClapTrap(){

	std::cout << "Destructor called." << std::endl;

}

// ClapTrap fonctions

void ClapTrap::attack(const std::string& target){

	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " can't attack any ennemy, he's knocked out." << std::endl;
		return;
	}
	if (this->_energyPoints > 1) {
	std::cout << "ClapTrap " << this->_name << " attack " << target << ", ";
	std::cout << "causing " << this->_attackDamage << " points of damage !" << std::endl;
	this->_energyPoints -= 1;
	}
	else
		std::cout << "ClapTrap " << this->_name << " doesn't have enought point energy for attacking " << target << "." << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount){

	if (this->_hitPoints <= 0){
		std::cout << "Stop hiting ClapTrap " << this->_name << ", he's dead !!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " take " << amount << " damage points !" << std::endl;
	if (amount >= this->_hitPoints) {
		this->_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " is out ! Please be care of ClapTrap <3 " << std::endl;
		return;
	}
	this->_hitPoints -= amount;
	if (this->_hitPoints <= 0)
		std::cout << "ClapTrap " << this->_name << " is out ! Please be care of ClapTrap <3 " << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount){

	if (this->_hitPoints == 0) {
		std::cout << "ClapTrap " << this->_name << " can't repair anything, he's knocked out." << std::endl;
		return;
	}
	if (this->_energyPoints > 1) {
		std::cout << "ClapTrap " << this->_name << " auto repaired " << amount << " life points !" << std::endl;
		this->_energyPoints -= 1;
		this->_hitPoints += amount;
	}
	else
		std::cout << "ClapTrap " << this->_name << " doesn't have enought point energy for repairing himself." << std::endl;
}

// Surcharge operator

ClapTrap	&ClapTrap::operator=(const ClapTrap &copy){

	this->_name = copy._name;
	this->_hitPoints = copy._hitPoints;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;

	return *this;
}
