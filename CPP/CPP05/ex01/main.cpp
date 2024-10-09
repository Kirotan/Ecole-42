#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

int	main(){

	Form	e("form1", 0, 150);
	Form	i("form2", 140, 151);

	Bureaucrat	p("Terry", 141);
	p.incrementGrade();
	p.signForm(i);
	p.signForm(i);
	p.signForm(e);

	return 0;
}
