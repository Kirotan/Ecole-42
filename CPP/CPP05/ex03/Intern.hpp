#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

class Intern{

	public :
	//Constructors
		Intern();
		Intern(const Intern &copy);

	//Destructor
		~Intern();

	//Surcharge operator
		Intern	&operator=(const Intern &other);

	//Member function
		AForm	*makeForm(const std::string nameForm, const std::string targetForm);

};
