#pragma once
#include <iostream>
#include <string>

class User{

	public :

	//Constructor & Destructor
		User(unsigned int fd);
		~User();

	//Surcharge operator
		User	&operator=(User const &other);

	// Getter
		int			getFd();
		std::string	getNickname();
		std::string	getUsername();

	//Setter
		void	setFd(unsigned int fd);
		void	setNickname(std::string nickname);
		void	setUsername(std::string username);


	private :
	//Constructor
		User();
		User(User const &copy);

	//Variable member
		unsigned int	_fd;
		std::string		_nickname;
		std::string		_username;

};
