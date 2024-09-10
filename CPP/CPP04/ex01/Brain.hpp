#pragma once
#include "Animal.hpp"

class Brain{

	public :

	//Constructors & destructor
		Brain();
		Brain(const Brain &copy);
		~Brain();

	// Surcharge operator
		Brain	&operator=(const Brain &copy);

	private :
		std::string	_ideas[100];
};
