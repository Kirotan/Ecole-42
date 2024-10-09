#include <iostream>
#include <string>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


//Constructors
Intern::Intern(){
	std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern &copy){
	std::cout << "Intern copy constructor called." << std::endl;
	*this= copy;
}


//Destructor
Intern::~Intern(){
	std::cout << "Intern destructor called." << std::endl;
}


//Surcharge operator
Intern	&Intern::operator=(const Intern &other){
	if (this == &other)
		return *this;
	return *this;
}


//Member function
static AForm	*createShrubbery(std::string target){
	return new ShrubberyCreationForm(target);
}

static AForm	*createRobotomy(std::string target){
	return new RobotomyRequestForm(target);
}

static AForm	*createPresidential(std::string target){
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm(const std::string nameForm, const std::string targetForm){

	std::string	wichForm[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	AForm *(*typeForm[])(const std::string target) = {&createShrubbery, &createRobotomy, &createPresidential};

	for(int i = 0; i < 3; i++)
		if(nameForm == wichForm[i]){
			std::cout << "Intern creates form " << nameForm << std::endl;
			return (typeForm[i](targetForm));
		}

	std::cout << "Creation of " << nameForm << " form is impossible for intern." << std::endl;
	return NULL;

}
