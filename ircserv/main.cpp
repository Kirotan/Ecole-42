#include <iostream>
#include <string>
#include "Server.hpp"
#include "handleInclude.hpp"

int	main(int argc, char ** argv){

	parsing(argc, argv);

	Server &server = Server::getInstance();
	server.initServer();


	return 0;
}
