#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(){

	Bureaucrat	k("Kiro", 1);

	// ShrubberyCreationForm	tt("toto");
	// ShrubberyCreationForm	dd("dede");

	RobotomyRequestForm		rr("die");

	// k.signAForm(tt);
	// tt.execute(k);

	// k.signAForm(dd);
	// dd.execute(k);

	k.signAForm(rr);
	rr.execute(k);
	rr.execute(k);
	rr.execute(k);
	rr.execute(k);


	return 0;
}
