# include <iostream>
# include "Contact.class.hpp"
# include "PhoneBook.class.hpp"
# include "Master.hpp"
# include <cstdlib>

PhoneBook::PhoneBook(void) {

		_nbContacts = 0;
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
	_contacts[_nbContacts % 8].setDarkestSecret(line);

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
	_contacts[_nbContacts % 8].setPhoneNumber(line);

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
	_contacts[_nbContacts % 8].setNickname(line);

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
	_contacts[_nbContacts % 8].setLastName(line);

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
	_contacts[_nbContacts % 8].setFirstName(line);
	_contacts[_nbContacts % 8].setIndex(_nbContacts % 8);

	return ;
}

void	PhoneBook::addContact() {

	addFirstName();
	addLastName();
	addNickname();
	addNumberPhone();
	addDarkestSecret();

	_nbContacts++;
	std::cout << "_nbContacts : " << _nbContacts << std::endl;

	return;
}

void	PhoneBook::displayMiniContact(int i) {

	std::cout << "Index : " << _contacts[i].getIndex();
	std::cout << " | ";
	std::cout << "First name : " << _contacts[i].getFirstName();
	std::cout << " | ";
	std::cout << " Last name : " << _contacts[i].getLastName();
	std::cout << " | ";
	std::cout << "Nickname : " << _contacts[i].getNickname() << std::endl;

	return ;
}

void	PhoneBook::displayContact(int i) {

	std::cout << "First name : " << _contacts[i].getFirstName() << std::endl;
	std::cout << "Last name : " << _contacts[i].getLastName() << std::endl;
	std::cout << "Nickname : " << _contacts[i].getNickname() << std::endl;
	std::cout << "Phone number : " << _contacts[i].getPhoneNumber() << std::endl;
	std::cout << "Darkest secret : " << _contacts[i].getDarkestSecret() << std::endl << std::endl;

	return ;
}

void	PhoneBook::searchContact() {

	int	i;
	str	line;

	if (_nbContacts == 0) {
		std::cout << "No contact available." << std::endl;
		return ;
	}
	i = 0;
	while (i < 8 && i < _nbContacts) {
		displayMiniContact(i);
		i++;
	}
	i = 0;
	std::cout << "Enter the index of the contact you want to see." << std::endl;
	std::getline(std::cin, line);
	i = atoi(line.c_str());
	while (check_if_number(line) == 0) {
		std::cout << "Enter a valid index." << std::endl;
		std::getline(std::cin, line);
	}
	if (i < 8 && i >= 0 && i <= (_nbContacts - 1)) {
		displayContact(i);
		}
	else {
		while (1) {
			std::cout << "Enter a valid index." << std::endl;
			std::getline(std::cin, line);
			while (check_if_number(line) == 0) {
				std::cout << "Enter a valid index." << std::endl;
				std::getline(std::cin, line);
			}
			i = atoi(line.c_str());
			if (i < 8 && i >= 0 && i <= (_nbContacts - 1)) {
				displayContact(i);
				break ;
			}
		}
	}
	return ;
}
