#include "ScalarConverter.hpp"

//Constructors & Destructor
ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &copy){(void)copy;}
ScalarConverter::~ScalarConverter(){}

//Surcharge operator
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other){(void)other; return *this;}


//Convert functions
void	ScalarConverter::convert(const std::string &str){

	if (isItChar(str) == true)
		convertChar(str);
	if (isItInt(str) == true)
		convertInt(str);
	if (isItDouble(str) == true)
		convertDouble(str);
	if (isItFloat(str) == true)
		convertFloat(str);
}


//Char
bool	isItChar(const std::string &str){

	(void)str;
	return false;
}

void	convertChar(const std::string &str){

	(void)str;
}


//Integer
bool	isItInt(const std::string &str){

	(void)str;
	return false;
}

void	convertInt(const std::string &str){

	(void)str;
}


//Double
bool	isItDouble(const std::string &str){

	(void)str;
	return false;
}

void	convertDouble(const std::string &str){

	(void)str;
}


//Floating
bool	isItFloat(const std::string &str){

	(void)str;
	return false;
}

void	convertFloat(const std::string &str){

	(void)str;
}
