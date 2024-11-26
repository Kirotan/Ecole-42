#include <iostream>
#include <string>
#include "User.hpp"

//Constructor & Destructor
	User::User(){}
	User::User(User const &copy){(void)copy;}
	User::User(unsigned int fd) : _fd(fd){}
	User::~User(){}

//Surcharge operator
	User	&User::operator=(User const &other){(void)other; return (*this);}

// Getter
	int			User::getFd(){return this->_fd;}
	std::string	User::getNickname(){return this->_nickname;}
	std::string	User::getUsername(){return this->_username;}

//Setter
	void	User::setFd(unsigned int fd){this->_fd = fd;}
	void	User::setNickname(std::string nickname){this->_nickname = nickname;}
	void	User::setUsername(std::string username){this->_username = username;}
