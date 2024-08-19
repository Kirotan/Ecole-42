# include "Contact.class.hpp"

Contact::Contact(void) {
	return;
}

Contact::~Contact(void) {
	return;
}

str	Contact::getFirstName(void) {
	return this->_firstName;
}

str	Contact::getLastName(void) {
	return this->_lastName;
}

str	Contact::getNickname(void) {
	return this->_nickname;
}

str	Contact::getPhoneNumber(void) {
	return this->_phoneNumber;
}

str	Contact::getDarkestSecret(void) {
	return this->_darkestSecret;
}

void	Contact::setFirstName(str firstName) {
	this->_firstName = firstName;
}

void	Contact::setLastName(str lastName) {
	this->_lastName = lastName;
}

void	Contact::setNickname(str nickname) {
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(str phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(str darkestSecret) {
	this->_darkestSecret = darkestSecret;
}
