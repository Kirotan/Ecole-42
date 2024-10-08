#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include "ScalarConverter.hpp"

//Constructors & Destructor
ScalarConverter::ScalarConverter(){}
ScalarConverter::ScalarConverter(const ScalarConverter &copy){(void)copy;}
ScalarConverter::~ScalarConverter(){}

//Surcharge operator
ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &other){(void)other; return *this;}


//Convert functions
void	ScalarConverter::convert(const std::string &str){

	if (isItInt(str) == true)
		convertInt(str);
	else if (isItChar(str) == true)
		convertChar(str);
	else if (isItDouble(str) == true)
		convertDouble(str);
	else if (isItFloat(str) == true)
		convertFloat(str);
	else if (infinityOrNotANumb(str))
		convertInfOrNotNumb(str);
	else
		std::cout << "Please, enter a correct input.\nYour options :\nChar\nInteger\nDouble\nFloat\nThank you." << std::endl;
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

	char c;

	if(str[0] == '\'' && str[2] == '\'')
		c = str[1];
	else
		c = str[0];

	if (static_cast<int> (c) < 32 || static_cast<int> (c)  > 126)
		std::cout << "char:\t Non displayable" << std::endl;
	else
		std::cout << "char:\t " << static_cast<char>(c) << std::endl;
	std::cout << "int:\t " << static_cast<int>(c) << std::endl;
	std::cout << "float:\t " << std::fixed << std::setprecision(1)
	<< static_cast<float>(c) << "f" << std::endl;
	std::cout << "double:\t " << static_cast<double>(c) << std::endl;
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

	//strtod convert string to double
	double d = strtod(str.c_str(), NULL);

	if ( d < 0. || d >= 128.)
		std::cout << "char:\t overflow" << std::endl;
	else if (d < 32. || d == 127.)
		std::cout << "char:\t Non displayable" << std::endl;
	else
		std::cout << "char:\t " << static_cast<char>(d) << std::endl;

	if ( d < static_cast<double> (INT_MIN) || d > static_cast<double> (INT_MAX))
		std::cout << "int:\t overflow" << std::endl;
	else
		std::cout << "int:\t " << static_cast<int>(d) << std::endl;

	std::cout << "float:\t " << std::fixed << std::setprecision(1)
	<< static_cast<float>(d) << "f" << std::endl;
	std::cout << "double:\t " << static_cast<double>(d) << std::endl;
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

	//Dynamique handle of precision
	size_t	dotPos = str.find('.');
	size_t	precision = 1; //default value

	if(dotPos != std::string::npos){
		precision = str.length() - dotPos -1;
		if(str[str.length() - 1] == 'f')
			precision--;
	}


	double d = strtod(str.c_str(), NULL);

	if ( d < 0. || d >= 128.)
		std::cout << "char:\t overflow" << std::endl;
	else if (d < 32. || d == 127.)
		std::cout << "char:\t Non displayable" << std::endl;
	else
		std::cout << "char:\t " << static_cast<char>(d) << std::endl;

	if ( d < static_cast<double> (INT_MIN) || d > static_cast<double> (INT_MAX))
		std::cout << "int:\t overflow" << std::endl;
	else
		std::cout << "int:\t " << static_cast<int>(d) << std::endl;

	std::cout << "float:\t " << std::fixed << std::setprecision(precision)
	<< static_cast<float>(d) << "f" << std::endl;
	std::cout << "double:\t " << std::fixed << std::setprecision(precision)
	<< static_cast<double>(d) << std::endl;
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

	//Dynamique handle of precision
	size_t	dotPos = str.find('.');
	size_t	precision = 1; //default value

	if(dotPos != std::string::npos){
		precision = str.length() - dotPos -1;
		if(str[str.length() - 1] == 'f')
			precision--;
	}


	double f = strtod(str.c_str(), NULL);

	if ( f < 0. || f >= 128.)
		std::cout << "char:\t overflow" << std::endl;
	else if (f < 32. || f == 127.)
		std::cout << "char:\t Non displayable" << std::endl;
	else
		std::cout << "char:\t " << static_cast<char>(f) << std::endl;

	if ( f < static_cast<double> (INT_MIN) || f > static_cast<double> (INT_MAX))
		std::cout << "int:\t overflow" << std::endl;
	else
		std::cout << "int:\t " << static_cast<int>(f) << std::endl;

	std::cout << "float:\t " << std::fixed << std::setprecision(precision)
	<< static_cast<float>(f) << "f" << std::endl;
	std::cout << "double:\t " << std::fixed << std::setprecision(precision)
	<< static_cast<double>(f) << std::endl;
}


//Infinity or Not A Number
bool	infinityOrNotANumb(const std::string &str){

	const std::string	infiniTab[] = { "-inff", "+inff", "nanf", "-inf", "+inf", "nan" };

	for (int i = 0; i < 6; i++)
	{
		if (str == infiniTab[i])
			return (true);
	}
	return (false);
}

void	convertInfOrNotNumb(const std::string &str)
{
	std::cout << "char:\t " << "impossible" << std::endl;
	std::cout << "int:\t " << "impossible" << std::endl;

	if (str == "-inff" || str == "+inff" || str == "nanf")
	{
		std::cout << "float:\t " << str << std::endl;
		std::string newStr = str.substr(0, str.size() - 1);
		std::cout << "double:\t " << newStr << std::endl;
	}
	else
	{
		std::cout << "float:\t " << str << "f" << std::endl;
		std::cout << "double:\t " << str << std::endl;
	}
}
