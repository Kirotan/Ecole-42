# include <iostream>
# include <cstdlib>
# include "Master.hpp"

void	check_argc(int argc) {

	if (argc != 1) {
		std::cout << "PhoneBook does not require an argument." << std::endl;
		exit (1);
	}
}

int	check_if_number(str line) {

	for (size_t i = 0; i < line.size(); i++) {
		if (!isdigit(line[i])) {
			return (0);
		}
	}
	return (1);
}

void	check_eof() {

	if (std::cin.eof()) {
		std::cout << "EOF detected." << std::endl;
		exit (1);
	}
}
