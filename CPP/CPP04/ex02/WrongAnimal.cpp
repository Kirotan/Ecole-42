#include "WrongAnimal.hpp"

// Constructors & destructor

WrongAnimal::WrongAnimal(){

	std::cout << "WrongAnimal default constructor." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){

	std::cout << "WrongAnimal type constructor." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy){

	std::cout << "WrongAnimal copy constructor." << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal(){

	std::cout << "WrongAnimal destructor." << std::endl;
}

// Surcharge d'operateur

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &copy){

	this->_type = copy._type;
	return *this;
}

// WrongAnimal focntion

void	WrongAnimal::makeSound() const{

	std::cout << "*...strange WRONG animal noice...*" << std::endl;
}

// Getter

std::string	WrongAnimal::getType() const{

	return this->_type;
}
