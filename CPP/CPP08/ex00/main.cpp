#include <iostream>
#include <string>
#include <vector>
#include "easyfind.hpp"

int	main(){

//test int
	std::vector<int>	vecInt(5);
	vecInt[0] = 1;
	vecInt[1] = 2;
	vecInt[2] = 3;
	vecInt[3] = 4;
	vecInt[4] = 5;

	int	i = 1;
	int	j = 90;

	try{
		easyfind(vecInt, i);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;

	}

	std::cout << std::endl;

	try{
		easyfind(vecInt, j);
	}
	catch(std::exception &e){
		std::cerr << e.what() << std::endl;

	}

	return 0;
}
