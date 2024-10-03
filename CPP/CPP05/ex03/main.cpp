#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(){

	Intern	*ii = new Intern;

	ii->makeForm("nul", "target_nul");
	ii->makeForm("ShrubberyCreationForm", "plant it");
	ii->makeForm("RobotomyRequestForm", "die !");
	ii->makeForm("PresidentialPardonForm", "Wash");

	delete ii;

	return 0;
}
