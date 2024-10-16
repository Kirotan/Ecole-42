#pragma once

#include <iostream>

class ScalarConverter{

	public :
	//Static method
	static void	convert(const std::string &str);


	private :
	//Constructors
	ScalarConverter();
	ScalarConverter(const ScalarConverter &copy);

	//Destructor
	~ScalarConverter();

	//Surcharge operator
	ScalarConverter	&operator=(const ScalarConverter &other);

};

bool	isItChar(const std::string &str);
void	convertChar(const std::string &str);

bool	isItInt(const std::string &str);
void	convertInt(const std::string &str);

bool	isItDouble(const std::string &str);
void	convertDouble(const std::string &str);

bool	isItFloat(const std::string &str);
void	convertFloat(const std::string &str);

bool	infinityOrNotANumb(const std::string &str);
void	convertInfOrNotNumb(const std::string &str);
