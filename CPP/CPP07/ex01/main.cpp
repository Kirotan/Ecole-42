#include "iter.hpp"
#include <string>
#include <iostream>


void	printInt(int &nb){std::cout << nb << std::endl;}

void	printChar(char &c){std::cout << c << std::endl;}

void	printString(std::string &str){std::cout << str << std::endl;}

void	printDouble(double &d){std::cout << d << std::endl;}

void	incrementInt(int &nb){nb++;}

void	decrementChar(char &c){c++;}

void	appendString(std::string &str){str.append("_test");}

void	multiDouble(double &d){d *= 2;}


int	main(){

//test Int

	std::cout << "Int test" << std::endl;
	std::cout << std::endl;

	int	nb[] = {1, 2, 3, 4, 5};
	iter(nb, 5, printInt);
	iter(nb, 5, incrementInt);

	std::cout << std::endl;

	iter(nb, 5, printInt);

	std::cout << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << std::endl;


//test Char

	std::cout << "Char test" << std::endl;
	std::cout << std::endl;

	char	c[] = {'H', 'w', '!'};
	iter(c, 3, printChar);
	iter(c, 3, decrementChar);
	std::cout << std::endl;
	iter(c, 3, printChar);

	std::cout << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << std::endl;

//test std::string

	std::cout << "String test" << std::endl;
	std::cout << std::endl;

	std::string	str[] = {"Hello", "world", "!"};
	iter(str, 3, printString);
	std::cout << std::endl;
	iter(str, 3, appendString);
	iter(str, 3, printString);


	std::cout << std::endl;
	std::cout << "--------------" << std::endl;
	std::cout << std::endl;

//test double

	std::cout << "Double test" << std::endl;
	std::cout << std::endl;

	double	d[] = {42.40, 19.12, 08.25};
	iter(d, 3, printDouble);
	std::cout << std::endl;
	iter(d, 3, multiDouble);
	iter(d, 3, printDouble);

	return 0;
}
