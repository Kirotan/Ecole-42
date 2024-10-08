#include "iter.hpp"
#include <string>
#include <iostream>


void	printInt(int &nb){std::cout << nb << std::endl;}

void	printChar(char &c){std::cout << c << std::endl;}

void	incrementInt(int &nb){nb++;}

void	incrementChar(char &c){c++;}



int	main(){

//test Int

	int	nb[] = {1, 2, 3, 4, 5};
	iter(nb, 5, printInt);
	iter(nb, 5, incrementInt);

	std::cout << std::endl;

	iter(nb, 5, printInt);

//test Char

	char	c[] = {'H', 'w', '!'};
	iter(c, 3, printChar);
	iter(c, 3, incrementChar);
	iter(c, 3, printChar);

	return 0;
}
