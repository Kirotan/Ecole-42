# include <iostream>
# include "Contact.class.hpp"
# include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {

	_nbContacts = 0;
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

void	PhoneBook::addNumberPhone() {

	str	line;

	std::cout << "Phone number :" << std::endl;
	std::getline(std::cin, line);
	while (line.size() < 6) {
		for (size_t i = 0; i < line.size(); i++) {
			if (!std::isdigit(line[i])) {
				std::cout << "Phone number take ONLY number." << std::endl;
				break ;
			}
		}
		std::cout << "Phone number need almost 6 numbers." << std::endl;
		std::cout << "Phone number:" << std::endl;
		std::getline(std::cin, line);
	}
	_contacts[_nbContacts].setPhoneNumber(line);
}

void	PhoneBook::addNickname() {

	str	line;

	std::cout << "Nickname :" << std::endl;
	std::getline(std::cin, line);
	while (line.empty()) {
		std::cout << "Nickname need almost one character." << std::endl;
		std::cout << "Nickname :" << std::endl;
		std::getline(std::cin, line);
	}
	_contacts[_nbContacts].setNickname(line);
}

void	PhoneBook::addLastName() {

	str	line;

	std::cout << "Last name :" << std::endl;
	std::getline(std::cin, line);
	while (line.empty()) {
		std::cout << "Last name need almost one character." << std::endl;
		std::cout << "Last name :" << std::endl;
		std::getline(std::cin, line);
	}
	_contacts[_nbContacts].setLastName(line);
}

void	PhoneBook::addFirstName() {

	str	line;

	std::cout << "First name :" << std::endl;
	std::getline(std::cin, line);
	while (line.empty()) {
		std::cout << "First name need almost one character." << std::endl;
		std::cout << "First name :" << std::endl;
		std::getline(std::cin, line);
	}
	_contacts[_nbContacts].setFirstName(line);
}

void	PhoneBook::addContact() {

	addFirstName();
	addLastName();
	addNickname();
	addNumberPhone();
	if (_nbContacts < 8)
		_nbContacts += 1;

	return;
}
