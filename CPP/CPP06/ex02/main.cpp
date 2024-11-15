#include <string>
#include <exception>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


//It randomly instanciates A, B or C and returns the instance as a Base pointer.
Base	* generate(void){

	int	random;

	random =rand() % 3;

	if(random == 0)
		return new A();
	else if(random == 1)
		return new B();
	else
		return new C();
}

//It prints the actual type of the object pointed to by p: "A", "B" or "C".
void	identify(Base* p){

	if(dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if(dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if(dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
	else
		return;
}


//It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
//inside this function is forbidden.
void	identify(Base& p){

	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception &e){}

	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception &e){}

	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (const std::exception &e){}
}

int	main(){

	//Initialize random number
	std::srand(std::time(0));

	Base	*q = generate();
	Base	*e = q;
	Base	*w = generate();
	Base	&r = *w;


	identify(q);
	identify(*q);

	identify(e);
	identify(*e);

	std::cout << std::endl;

	identify(w);
	identify(*w);

	identify(r);
	identify(&r);

	delete q;
	delete w;

	return 0;
}

