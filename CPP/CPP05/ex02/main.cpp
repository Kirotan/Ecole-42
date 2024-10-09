#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(){

	Bureaucrat	k("Ki", 1);

	ShrubberyCreationForm	tt("Shrub1");
	ShrubberyCreationForm	dd("Shrub1");

	RobotomyRequestForm		rr;

	PresidentialPardonForm		ww("PPF");

	k.signAForm(tt);
	tt.execute(k);

	k.signAForm(dd);
	dd.execute(k);

	k.signAForm(rr);
	rr.execute(k);
	rr.execute(k);
	rr.execute(k);
	rr.execute(k);

	k.signAForm(ww);
	ww.execute(k);

	return 0;
}
