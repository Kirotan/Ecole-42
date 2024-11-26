#pragma once
#include <iostream>
#include <string>
#include <netinet/in.h>
#include <sys/epoll.h>
#include "User.hpp"
#include "Operator.hpp"


class Server{

	public :

	//Instance unique
	static Server &getInstance() {
		static Server instance;
		return instance;
	}

	//Setter & Getter
		void			setPort(unsigned short port);
		unsigned short	getPort();

		void			setPassw(std::string port);
		std::string		getPassw();

	//Member functions
		void	initServer();
		int		socketNonBlocking(int fd);
		void	initEpoll();


	private :

	//Constructor
		Server();
		Server(Server const &copy);

	//Destructor
		~Server();

	//Surcharge operator
		Server	&operator=(Server const &other);

	//Variable member
		unsigned short		_port;
		std::string			_passw;
		int					_serverSocket;
		struct sockaddr_in	_serverAddres;
		int					_epollFd;
		struct epoll_event	_event;
		unsigned short		_backLogSize;

	//Array of : Channel, User and Operator


};
