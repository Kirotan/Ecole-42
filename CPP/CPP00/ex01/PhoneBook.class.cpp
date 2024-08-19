# include <iostream>
# include "Contact.class.hpp"
# include "PhoneBook.class.hpp"

PhoneBook::PhoneBook(void) {

	if (_nbContacts)
		_nbContacts = 0;
	else
		_nbContacts += 1;
	return;
}

PhoneBook::~PhoneBook(void) {
	return;
}

void	PhoneBook::addDarkestSecret() {

	str	line;

	std::cout << "Darkest secret :" << std::endl;
	std::getline(std::cin, line);
	while (line.empty()) {
		std::cout << "Darkest secret need almost one character." << std::endl;
		std::cout << "Darkest secret :" << std::endl;
		std::getline(std::cin, line);
	}
	_contacts[_nbContacts].setDarkestSecret(line);

	return ;
}

void	PhoneBook::addNumberPhone() {

	str		line;
	size_t	i;

	std::cout << "Phone number :" << std::endl;
	std::getline(std::cin, line);
	i = 0;
	while (i < line.size()) {
		if (!std::isdigit(line[i])) {
			std::cout << "Phone number take ONLY number." << std::endl;
			std::cout << "Phone number :" << std::endl;
			std::getline(std::cin, line);
			i = 0;
		}
		i++;
	}
	while (line.size() < 6) {
		std::cout << "Phone number need almost 6 numbers." << std::endl;
		std::cout << "Phone number:" << std::endl;
		std::getline(std::cin, line);
	}
	_contacts[_nbContacts].setPhoneNumber(line);

	return ;
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

	return ;
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

	return ;
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
	if (_nbContacts >= 8)
		_contacts[_nbContacts].setIndex(_nbContacts % 8);
	else
		_contacts[_nbContacts].setIndex(_nbContacts);

	return ;
}

void	PhoneBook::addContact() {

	addFirstName();
	addLastName();
	addNickname();
	addNumberPhone();
	addDarkestSecret();

	return;
}

void	PhoneBook::searchContact() {


}
