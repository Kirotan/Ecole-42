# pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public :
	// Constructors & Destructor
		WrongCat();
		WrongCat(const WrongCat &copy);
		virtual ~WrongCat();

	// Surcharge operator
		WrongCat	&operator=(const WrongCat &copy);

	// Fonction membre
		virtual void	makeSound() const;

	// Getter
		std::string	getType() const;

	protected :
		std::string	_type;

};
