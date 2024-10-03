#include <iostream>
#include <string>
#include <iomanip>
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

	if(str.length() == 1){
			return true;
	}

	if(str.length() == 3){
		if (str[0] == '\'' && str[2] == '\'')
			return true;
	}
	return false;
}

void	convertChar(const std::string &str){

	(void)str;
}


//Integer
bool	isItInt(const std::string &str){

	size_t	index = 0;

	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return (false);
	while (index < str.length() && std::isspace(str[index]))
		index++;
	if (index == str.length())
		return (false);
	if (str[index] == '+' || str[index] == '-')
		index++;
	for (size_t i = index; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	return true;
}

void	convertInt(const std::string &str){

	(void)str;
}


//Double
bool	isItDouble(const std::string &str){

	size_t	index = 0;
	bool	doubleOrnNot = false;

	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return (false);
	while (index < str.length() && std::isspace(str[index]))
		index++;
	if (index == str.length())
		return (false);
	if (str[index] == '+' || str[index] == '-')
		index++;
	for (size_t i = index; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (str[i] == '.')
			{
				if (doubleOrnNot)
					return (false);
				doubleOrnNot = true;
			}
			else
				return (false);
		}
	}

	return true;
}

void	convertDouble(const std::string &str){

	(void)str;
}


//Floating
bool	isItFloat(const std::string &str){

	size_t	index = 0;
	bool	floatOrNot = false;

	if ((str[0] == '+' || str[0] == '-') && str.length() <= 1)
		return (false);
	while (index < str.length() && std::isspace(str[index]))
		index++;
	if (index == str.length())
		return (false);
	if (str[index] == '+' || str[index] == '-')
		index++;
	for (size_t i = index; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
		{
			if (i == str.length() - 1)
				return (str[i] == 'f');
			if (str[i] == '.')
			{
				if (floatOrNot)
					return (false);
				floatOrNot = true;
			}
			else
				return (false);
		}

	}
	return true;
}

void	convertFloat(const std::string &str){

	(void)str;
}
