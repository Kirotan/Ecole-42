#include <iostream>
#include "Bureaucrat.hpp"

int	main(){

	Bureaucrat	a(9);
	Bureaucrat	b;
	Bureaucrat	c(a);
	Bureaucrat	d(900);
	Bureaucrat	e(-42);




	std::cout << "a : " << a.getGrade() << std::endl;;
	std::cout << "a : " << a.getName() << std::endl;;

	std::cout << "b : " << b.getGrade() << std::endl;;
	std::cout << "b : " << b.getName() << std::endl;;

	std::cout << "c : " << c.getGrade() << std::endl;;
	std::cout << "c : " << c.getName() << std::endl;;

	std::cout << "d : " << d.getGrade() << std::endl;;
	std::cout << "d : " << d.getName() << std::endl;;

	std::cout << "e : " << e.getGrade() << std::endl;;
	std::cout << "e : " << e.getName() << std::endl;;

	return 0;
}
