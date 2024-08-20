#include "Master.hpp"
#include "Contact.class.hpp"
#include "PhoneBook.class.hpp"

void	loop(void) {

	str	line;
	PhoneBook	PB;

	while (1) {
		std::cout << "Enter one of following commands" << std::endl;
		std::cout << "ADD || SEARCH || EXIT" << std::endl;
		std::getline(std::cin, line);
		check_eof();
		which_command(line, PB);
	}
}
