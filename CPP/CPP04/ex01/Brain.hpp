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

	// Getter & Setter
		void			setIdeas(std::string ideas, int index);
		std::string		getIdeas(int index);

	private :
		std::string	_ideas[100];
};
