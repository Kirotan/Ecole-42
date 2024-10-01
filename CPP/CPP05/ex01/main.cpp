#include <iostream>
#include "Bureaucrat.hpp"

int	main(){

	// Form	e("form1", 0, 150);
	Form	i("form2", 140, 151);

	Bureaucrat	p("Allan", 141);
	p.incrementGrade();
	p.signForm(i);
	p.signForm(i);

	// std::cout << e.getName() << std::endl;


	return 0;
}
