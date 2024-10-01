#include <iostream>
#include "Bureaucrat.hpp"


//Constructor && Destructor
Bureaucrat::Bureaucrat(){

	std::cout << "Bureaucrat default constructor." << std::endl;
	this->_name = "default";
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy){

	std::cout << "Bureaucrat copy constructor." << std::endl;
	this->_grade = copy._grade;
	this->_name = copy._name + "_copy";
}

Bureaucrat::Bureaucrat(const short grade) : _name("default"){

	std::cout << "Bureaucrat grade constructor." << std::endl;

	try {
		std::cout << "Trying to set grade." << std::endl;
		this->setGrade(grade);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Impossible to set grade of " << this->_name << std::endl;
		std::cerr << e.what() << std::endl;
		std::cerr << "Default grade initialization to 1." << std::endl;
		this->_grade = 1;
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Impossible to set grade of " << this->_name << std::endl;
		std::cerr << e.what() << std::endl;
		std::cerr << "Default grade initialization to 150." << std::endl;
		this->_grade = 150;
	}
}

Bureaucrat::~Bureaucrat(){

	std::cout << "Bureaucrat destructor." << std::endl;
}


//Surcharge operator
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other){
	this->_grade = other._grade;
	return *this;
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &other){

	out << other.getName() << ", bureaucrat grade " << other.getGrade() << "." << std::endl;
	return out;
}


//Getter
std::string		Bureaucrat::getName() const{
	return this->_name;
}

short	Bureaucrat::getGrade() const{
	return this->_grade;
}


//Setter
void	Bureaucrat::setName(std::string name){
	this->_name = name;
}

void	Bureaucrat::setGrade(short grade){
	if (grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
}


//Members functions
void	Bureaucrat::incrementGrade(){
	try {
		std::cout << "Trying to increment grade." << std::endl;
		this->setGrade(this->_grade - 1);
	}
	catch (Bureaucrat::GradeTooHighException &e) {
		std::cerr << "Impossible to increment grade of " << this->_name << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

void	Bureaucrat::decrementGrade(){
	try {
		std::cout << "Trying to decrement grade." << std::endl;
		this->setGrade(this->_grade + 1);
	}
	catch (Bureaucrat::GradeTooLowException &e) {
		std::cerr << "Impossible to decrement grade of " << this->_name << std::endl;
		std::cerr << e.what() << std::endl;
	}
}


//Exception
const char*	Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high.";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low.";
}
