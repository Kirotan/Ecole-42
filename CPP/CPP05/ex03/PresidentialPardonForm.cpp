#include <iostream>
#include <string>
#include <stdexcept>
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"


// Constructors
PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), _target("default"){
	std::cout << "Presidential default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target){
	std::cout << "Presidential target constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy): AForm("PresidentialPardonForm_copy", 25, 5), _target(copy.getTarget()){
	std::cout << "Presidential copy constructor called." << std::endl;

	*this = copy;
}

// Destructors
PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "Presidential destructor called." << std::endl;
}

// Surcharge operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other){
	std::cout << "Presidential surcharge operator called" << std::endl;
	if (this == &other)
		return *this;
	return *this;
}


// Members functions
void	PresidentialPardonForm::execute(Bureaucrat const &executor)const{
	try {
		if (this->getSigned() == false)
			throw AForm::FormNotSignedException();
	}
	catch (const AForm::FormNotSignedException& e){
		std::cerr << e.what() << std::endl;
		return;
	}

	try {
		if ((int)executor.getGrade() > this->getGradeExecuted())
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const Bureaucrat::GradeTooLowException& e){
		std::cerr << e.what() << std::endl;
		return;
	}
	std::cout << executor.getName() << " bureaucrat executed "
	<< this->getName() << " form." << std::endl;

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;

}


// Getter
std::string	PresidentialPardonForm::getTarget(void)const{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm other){
	out << other.getName() << " PresidentialPardonForm with " << other.getGradeSigned()
	<< " in grade signed and " << other.getGradeExecuted() << " in grade executed "
	<< "have one target : " << other.getTarget() << std::endl;
	return out;
}
