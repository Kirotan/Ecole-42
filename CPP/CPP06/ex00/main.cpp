#include <iostream>
#include <cstdlib>
#include "ScalarConverter.hpp"

int	main(int argc, char **argv){

	if(argc != 2){
		std::cerr << "Converter must have 1 argument." << std::endl;
		exit (EXIT_FAILURE);
	}

	for (int i = 0; argv[1][i] != '\0'; i++){
		if ((argv[1][i] >= 0 && argv[1][0] <= 31) || argv[1][i] == 127){
			std::cerr << "Non displayable characters shouldn’t be used as inputs." << std::endl;
			exit (EXIT_FAILURE);
		}
	}

	ScalarConverter::convert(argv[1]);

	return 0;
}
