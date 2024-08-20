#include "Master.hpp"
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"
#include <cstdlib>

void	which_command(str line, PhoneBook& PB) {

	if (line == "ADD") {
		PB.addContact();
	}
	else if (line == "SEARCH") {
		PB.searchContact();
	}
	else if (line == "EXIT") {
		exit(0);
	}
	else {
		std::cout << "Invalid command" << std::endl;
	}
}
