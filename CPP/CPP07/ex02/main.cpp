#include <iostream>
#include <string>
#include "Array.hpp"

int	main(){

	//Subject test
	// int *a = new int();
	// *a = 42;
	// std::cout << a << std::endl;
	// std::cout << *a << std::endl;
	// delete a;


//test int array
	// Array<int> b(3);
	// b[1] = 9;

	// try {
	// 	b[-9] = 12;
	// }
	// catch(Array<int>::IndexException &e){
	// 	std::cerr << e.what() << std::endl;
	// }

	// std::cout << b[1] << std::endl;


//test string array
	// Array<std::string> c(5);
	// c[2] = "Hello !";

	// try {
	// 	c[4] = "Coucou";
	// }
	// catch(Array<std::string>::IndexException &e){
	// 	std::cerr << e.what() << std::endl;
	// }

	// std::cout << c[2] << std::endl;
	// std::cout << c[4] << std::endl;

	return 0;
}
