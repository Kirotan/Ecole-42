#pragma once
#include <iostream>

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
		virtual void	makeSound() const;

	//Getter
		std::string	getType() const;


	protected :
		std::string _type;

};
