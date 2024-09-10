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

	this->_ideas[100] = copy._ideas[100];
	return *this;
}
