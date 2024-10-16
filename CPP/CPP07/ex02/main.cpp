#include <iostream>
#include <string>
#include "Array.hpp"

int	main(){

	//Subject test
	// int *a = new int();
	// std::cout << a << std::endl;

	// Array<int> b(3);
	Array<std::string> c(5);


//test int array
	// b[1] = 9;

	// try {
	// 	b[-9] = 12;
	// }
	// catch(Array<int>::IndexException &e){
	// 	std::cerr << e.what() << std::endl;
	// }

	// std::cout << b[1] << std::endl;

//test string array
	c[2] = "Hello !";

	try {
		c[4] = "Coucou";
	}
	catch(Array<std::string>::IndexException &e){
		std::cerr << e.what() << std::endl;
	}

	std::cout << c[2] << std::endl;
	std::cout << c[4] << std::endl;

	return 0;
}
