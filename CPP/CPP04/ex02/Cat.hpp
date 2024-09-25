# pragma once
#include "Animal.hpp"

class Cat : public Animal {

	public :
	// Constructors & Destructor
		Cat();
		Cat(const Cat &copy);
		virtual ~Cat();

	// Surcharge operator
		Cat	&operator=(const Cat &copy);

	// Fonction membre
		virtual void	makeSound() const;

	// Getter
		std::string	getType() const;

	protected :
		std::string	_type;
		Brain		*_brain;

};
