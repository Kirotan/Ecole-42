#include "Dog.hpp"

// Constructors & Destructor

Dog::Dog() : Animal("Dog"){

	std::cout << "Dog default constructor." << std::endl;
}

Dog::Dog(const Dog &copy){

	*this = copy;
	std::cout << "Dog copy constructor." << std::endl;
}

Dog::~Dog(){

	std::cout << "Dog destructor." << std::endl;
}

// Surcharge operator

Dog	&Dog::operator=(const Dog &copy){

	this->_type = copy._type;
	return *this;
}

// Dog fonction

void	Dog::makeSound() const{

 std::cout << "WooUf wOouF !." << std::endl;
}

// Getter

std::string	Dog::getType() const{

	return this->_type;
}
