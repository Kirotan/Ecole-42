#pragma once
#include <iostream>
#include <string>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <vector>
#include <map>
#include "Channel.hpp"
#include "User.hpp"
#include "Operator.hpp"


class Server{

	public :

	//Instance unique
	static Server &getInstance() {
		static Server instance;
		return instance;
	}

	//Constructor
		Server();
		Server(Server const &copy);

	//Destructor
		~Server();

	//Setter & Getter
		void			setPort(unsigned short port);
		unsigned short	getPort();

		void			setPassw(std::string port);
		std::string		getPassw();

		void			setNeedPasswFalse();
		void			setNeedPasswTrue();
		bool			getNeedPassw();

	//Surcharge operator
		Server	&operator=(Server const &other);

	//Member functions
		void	initServer();
		int		socketNonBlocking(int fd);
		void	initEpoll();
		void	run();

		void	createChannel(Channel &chan);
		void	deleteChannel(std::string &channelName);

		void	createUser(int fd, User &user);
		void	deleteUser(int fd);

		// void	createOperator();
		// void	deleteOperator();


	private :
	//Variable member
		unsigned short		_port;
		std::string			_passw;
		int					_serverSocket;
		struct sockaddr_in	_serverAddres;
		int					_epollFd;
		struct epoll_event	_event;
		unsigned short		_backLogSize;
		bool				_invitationOnly;
		bool				_needPassw;

	//Array of : Channel, User and Operator
		std::vector<Channel>	_arrayChannel;
		std::map<int, User*>		_arrayUser;
		std::vector<Oper>		_arrayOperator;

};
