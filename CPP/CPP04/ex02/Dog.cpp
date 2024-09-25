#include "Dog.hpp"

// Constructors & Destructor

Dog::Dog() : Animal("Dog"), _brain(new Brain){

	std::cout << "Dog default constructor." << std::endl;
}

Dog::Dog(const Dog &copy) : _brain(new Brain){

	std::cout << "Dog copy constructor." << std::endl;
	*this = copy;
}

Dog::~Dog(){

	std::cout << "Dog destructor." << std::endl;
	delete this->_brain;
}

// Surcharge operator

Dog	&Dog::operator=(const Dog &copy){

	if (this != &copy){
		this->_type = copy._type;
		if (this->_brain != NULL)
			delete this->_brain;
		this->_brain = new Brain(*copy._brain);
	}
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
