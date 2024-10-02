#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(){

	Bureaucrat	k("Kiro", 150);
	ShrubberyCreationForm	tt("toto");

	// k.signAForm(tt);
	tt.execute(k);

	return 0;
}
