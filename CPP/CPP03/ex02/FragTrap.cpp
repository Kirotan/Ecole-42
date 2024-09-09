#include "FragTrap.hpp"

//Constructors & Destructor

FragTrap::FragTrap() : ClapTrap(){

	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap default constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){

	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;

	std::cout << "FragTrap name constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy){

	*this = copy;
	std::cout << "FragTrap copy constructor called." << std::endl;

}

FragTrap::~FragTrap(){

	std::cout << "FragTrap destructor called." << std::endl;
}


//FragTrap functions

void	FragTrap::highFivesGuys(void){

	if (this->_energyPoints == 0) {
		std::cout << "FragTrap " << this->_name << " doesn't have enought energy for high fives." << std::endl;
		return;
	}
	if (this->_hitPoints > 0) {
		std::cout << "FragTrap " << this->_name << " ask you : ";
		std::cout << "Give me five guys !" << std::endl;
		this->_energyPoints -= 1;
	}
	else
		std::cout << "FragTrap " << this->_name << " can't high five, he's knocked out." << std::endl;

}
