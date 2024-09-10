#include "Cat.hpp"

// Constructors & Destructor

Cat::Cat() : Animal("Cat"), _brain(new Brain()){

	std::cout << "Cat default constructor." << std::endl;
}

Cat::Cat(const Cat &copy){

	std::cout << "Cat copy constructor." << std::endl;
	*this = copy;
}

Cat::~Cat(){

	std::cout << "Cat destructor." << std::endl;
	delete this->_brain;
}

// Surcharge operator

Cat	&Cat::operator=(const Cat &copy){

	this->_type = copy._type;
	return *this;
}

// Cat fonction

void	Cat::makeSound() const{

	std::cout << "Meew MEeW ..." << std::endl;
}

// Getter

std::string	Cat::getType() const{

	return this->_type;
}
