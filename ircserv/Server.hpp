#pragma once
#include <iostream>
#include <string>
#include <netinet/in.h>

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

	//Member functions
		void	initServer();

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


};
