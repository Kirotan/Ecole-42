#include "WrongCat.hpp"

// Constructors & Destructor

WrongCat::WrongCat() : WrongAnimal("WrongCat"){

	std::cout << "WrongCat default constructor." << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy){

	std::cout << "WrongCat copy constructor." << std::endl;
	*this = copy;
}

WrongCat::~WrongCat(){

	std::cout << "WrongCat destructor." << std::endl;
}

// Surcharge operator

WrongCat	&WrongCat::operator=(const WrongCat &copy){

	this->_type = copy._type;
	return *this;
}

// WrongCat fonction

void	WrongCat::makeSound() const{

	WrongAnimal::makeSound();
}

// Getter

std::string	WrongCat::getType() const{

	return this->_type;
}
