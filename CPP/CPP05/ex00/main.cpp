#include <iostream>
#include "Bureaucrat.hpp"

int	main(){

	Bureaucrat	a(9);
	Bureaucrat	b;
	Bureaucrat	c(a);
	Bureaucrat	d(900);
	Bureaucrat	e(-42);
	Bureaucrat	f("Lyl");
	Bureaucrat	g("Harry", -33);
	Bureaucrat	h("Meg", 33);
	Bureaucrat	i("Incr", 1);
	Bureaucrat	j("Decr", 150);

	std::cout << "-------------------------------------" << std::endl;

	std::cout << "a : " << a.getGrade() << std::endl;;
	std::cout << "a : " << a.getName() << std::endl;;

	std::cout << "-------------------------------------" << std::endl;

	std::cout << "b : " << b.getGrade() << std::endl;;
	std::cout << "b : " << b.getName() << std::endl;;

	std::cout << "-------------------------------------" << std::endl;

	std::cout << "c : " << c.getGrade() << std::endl;;
	std::cout << "c : " << c.getName() << std::endl;;

	std::cout << "-------------------------------------" << std::endl;

	std::cout << "d : " << d.getGrade() << std::endl;;
	std::cout << "d : " << d.getName() << std::endl;;

	std::cout << "-------------------------------------" << std::endl;

	std::cout << "e : " << e.getGrade() << std::endl;;
	std::cout << "e : " << e.getName() << std::endl;;

	std::cout << "-------------------------------------" << std::endl;

	std::cout << "f : " << f.getGrade() << std::endl;;
	std::cout << "f : " << f.getName() << std::endl;;

	std::cout << "-------------------------------------" << std::endl;

	std::cout << "g : " << g.getGrade() << std::endl;;
	std::cout << "g : " << g.getName() << std::endl;;

	std::cout << "-------------------------------------" << std::endl;

	std::cout << "h : " << h.getGrade() << std::endl;;
	std::cout << "h : " << h.getName() << std::endl;;

	std::cout << "-------------------------------------" << std::endl;

	std::cout << "i : " << i.getGrade() << std::endl;;
	i.incrementGrade();
	std::cout << "i : " << i.getGrade() << std::endl;;
	i.decrementGrade();
	std::cout << "i : " << i.getGrade() << std::endl;;
	std::cout << "i : " << i.getName() << std::endl;;

	std::cout << "-------------------------------------" << std::endl;

	std::cout << "j : " << j.getGrade() << std::endl;;
	j.decrementGrade();
	j.incrementGrade();
	std::cout << "j : " << j.getGrade() << std::endl;;
	std::cout << "j : " << j.getName() << std::endl;;

	std::cout << "-------------------------------------" << std::endl;

	return 0;
}
