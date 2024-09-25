#include "Animal.hpp"

// Constructors & destructor

Animal::Animal(){

	std::cout << "Animal default constructor." << std::endl;
}

Animal::Animal(std::string type) : _type(type){

	std::cout << "Animal type constructor." << std::endl;
}

Animal::Animal(const Animal &copy){

	std::cout << "Animal copy constructor." << std::endl;
	*this = copy;
}

Animal::~Animal(){

	std::cout << "Animal destructor." << std::endl;
}

// Surcharge d'operateur

Animal	&Animal::operator=(const Animal &copy){

	this->_type = copy._type;
	return *this;
}

// Animal focntion

void	Animal::makeSound() const{

	std::cout << "*...strange animal noice...*" << std::endl;
}

// Getter

std::string	Animal::getType() const{

	return this->_type;
}
