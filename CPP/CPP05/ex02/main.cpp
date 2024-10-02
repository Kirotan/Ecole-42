#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(){

	Bureaucrat	k("Kiro", 1);
	ShrubberyCreationForm	tt("toto");
	ShrubberyCreationForm	dd("dede");


	k.signAForm(tt);
	tt.execute(k);

	k.signAForm(dd);
	dd.execute(k);

	return 0;
}
