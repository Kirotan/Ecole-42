# pragma once
#include "Animal.hpp"

class Dog : public Animal {

	public :
	// Constructors & Destructor
		Dog();
		Dog(const Dog &copy);
		virtual ~Dog();

	// Surcharge operator
		Dog	&operator=(const Dog &copy);

	// Fonction membre
		virtual void	makeSound() const;

	// Getter
		std::string	getType() const;

	protected :
		std::string	_type;
		Brain		*_brain;

};
