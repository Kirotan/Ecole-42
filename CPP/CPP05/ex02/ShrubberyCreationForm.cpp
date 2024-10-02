#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include <fstream>

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), _target("default"){
	std::cout << "Shrubbery default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target){
	std::cout << "Shrubbery target constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy): AForm("ShrubberyCreationForm_copy", 145, 137), _target(copy.getTarget()){
	std::cout << "Shrubbery copy constructor called." << std::endl;

	*this = copy;
}

// Destructors
ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "Shrubbery destructor called." << std::endl;
}

// Surcharge operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
	std::cout << "Shrubbery surcharge operator called" << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

// Members functions
void	ShrubberyCreationForm::execute(Bureaucrat const &executor)const{
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

	std::cout << executor.getName() << " bureaucrat creates "
	<< this->getTarget().append("_shrubbery").c_str() << " and draws a ASCII tree." << std::endl;

	std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());

		outfile <<
		"888" << std::endl <<
		"888" << std::endl <<
		"888" << std::endl <<
		"888888888d888 .d88b.  .d88b." << std::endl <<
		"888   888P'  d8P  Y8bd8P  Y8b" << std::endl <<
		"888   888    8888888888888888" << std::endl <<
		"Y88b. 888    Y8b.    Y8b." << std::endl <<
		" 'Y888888     'Y8888  'Y8888" << std::endl << std::endl;

	outfile.close();

}


// Getter
std::string	ShrubberyCreationForm::getTarget(void)const{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm other){
	out << other.getName() << " ShrubberyCreationForm with " << other.getGradeSigned()
	<< " in grade signed and " << other.getGradeExecuted() << " in grade executed "
	<< "have one target : " << other.getTarget() << std::endl;
	return out;
}