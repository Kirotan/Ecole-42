#include <iostream>
#include <string>
#include <map>
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv){

	if (argc != 2){
		std::cerr << "Program must have one argument." << std::endl;
		return 1;
	}

	BitcoinExchange be;

	be.exchangeRate(argv[1]);

	return 0;
}