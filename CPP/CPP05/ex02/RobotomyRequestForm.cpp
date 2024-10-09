#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), _target("default"){
	std::cout << "Robotomy default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target){
	std::cout << "Robotomy target constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy): AForm("RobotomyRequestForm_copy", 72, 45), _target(copy.getTarget()){
	std::cout << "Robotomy copy constructor called." << std::endl;

	*this = copy;
}

// Destructors
RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "Robotomy destructor called." << std::endl;
}

// Surcharge operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other){
	std::cout << "Robotomy surcharge operator called" << std::endl;
	if (this == &other)
		return *this;
	return *this;
}

static short	kill_robot = 0;

// Members functions
void	RobotomyRequestForm::execute(Bureaucrat const &executor)const{
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
	if (kill_robot++ % 2)
		std::cout << "*Drill execution* " << this->getTarget() << " has been robotomized." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;

}


// Getter
std::string	RobotomyRequestForm::getTarget(void)const{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm other){
	out << other.getName() << " RobotomyRequestForm with " << other.getGradeSigned()
	<< " in grade signed and " << other.getGradeExecuted() << " in grade executed "
	<< "have one target : " << other.getTarget() << std::endl;
	return out;
}
