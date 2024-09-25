#include "Brain.hpp"

// Constructors & Destructor
Brain::Brain(){

	std::cout << "Brain default constructor." << std::endl;
}

Brain::Brain(const Brain &copy) {

	std::cout << "Brain copy constructor." << std::endl;
	*this = copy;
}

Brain::~Brain(){

	std::cout << "Brain destructor." << std::endl;
}

// Surcharge operator

Brain	&Brain::operator=(const Brain &copy){

	for (int i = 0; i < 100; i++)
		this->_ideas[i] = copy._ideas[i];
	return *this;
}

// Getter & Setter

void			Brain::setIdeas(std::string ideas, int index){

	if (index < 0 || index > 100) {

		std::cout << "Bad index. Index must be beetween 0 and 100." << std::endl;
		return;
	}
	this->_ideas[index] = ideas;
}

std::string		Brain::getIdeas(int index){

	if (index < 0 || index > 100) {
		std::cout << "Bad index. Index must be beetween 0 and 100." << std::endl;
		return NULL;
	}
	return this->_ideas[index];
}
