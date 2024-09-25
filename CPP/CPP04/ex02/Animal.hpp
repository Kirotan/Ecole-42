#pragma once
#include <iostream>
#include "Brain.hpp"

class Animal {

	public :
	// Constructors & Destructor
		Animal();
		Animal(std::string type);
		Animal(const Animal &copy);
		virtual ~Animal();

	// Surchage operator
		Animal	&operator=(const Animal &copy);

	// Animal fonctions
		virtual void	makeSound() const = 0;

	//Getter
		std::string	getType() const;


	protected :
		std::string _type;

};
