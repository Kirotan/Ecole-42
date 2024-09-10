#pragma once
#include <iostream>

class WrongAnimal {

	public :
	// Constructors & Destructor
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal();

	// Surchage operator
		WrongAnimal	&operator=(const WrongAnimal &copy);

	// Animal fonctions
		virtual void	makeSound() const;

	//Getter
		std::string	getType() const;


	protected :
		std::string _type;

};
