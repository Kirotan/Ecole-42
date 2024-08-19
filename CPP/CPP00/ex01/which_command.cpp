#include "Master.hpp"
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <cstdlib>

void	which_command(str line, PhoneBook& PB) {

	if (line == "ADD") {
		PB.addContact();
	}
	else if (line == "SEARCH") {
		std::cout << "SEARCH" << std::endl;
	}
	else if (line == "EXIT") {
		std::cout << "EXIT" << std::endl;
		exit(0);
	}
	else {
		std::cout << "Invalid command" << std::endl;
	}
}
