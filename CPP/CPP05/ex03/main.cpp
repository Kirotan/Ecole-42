#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(){

	Intern someRandomIntern;
	AForm* rrf;

	rrf = someRandomIntern.makeForm("nul", "target_nul");
	delete rrf;

	rrf = someRandomIntern.makeForm("ShrubberyCreationForm", "plant it");
	delete rrf;

	rrf = someRandomIntern.makeForm("RobotomyRequestForm", "die !");
	delete rrf;

	rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Wash");
	delete rrf;

	return 0;
}
