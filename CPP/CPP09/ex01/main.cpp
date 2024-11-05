#include <iostream>
#include <string>
#include <stack>
#include "RPN.hpp"

int	main(int argc, char **argv){

	if(argc == 1){
		std::cerr << "Not enough argument. Must be 2 arguments." << std::endl;
		return 1;
	}
	else if(argc > 2){
		std::cerr << "Too many arguments. Must be 2 arguments." << std::endl;
		return 1;
	}

	RPN	sum(argv[1]);

	return 0;
}
