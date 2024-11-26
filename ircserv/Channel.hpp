#pragma once
#include <iostream>
#include <string>
#include "Server.hpp"
#include "User.hpp"
#include "Operator.hpp"

class Channel{

	public :
	//Constructor & Destructor
		Channel();
		Channel(Channel const &copy);
		Channel(std::string name);
		~Channel();

	//Getter
		std::string	getTopic();
		std::string	getName();

	//Setter
		void	setTopic(std::string topic);

	//Member function
		void	mode();

	private :
	//Member variable
		std::string	_name;
		std::string	_topic;

	//Surcharge operator
		Channel	&operator=(Channel const &other);

};
