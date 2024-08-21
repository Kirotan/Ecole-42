#include <iostream>

typedef std::string str;

int	main(void) {

	str	line = "HI THIS IS BRAIN";
	str	*stringPTR = &line;
	str	&stringREF = line;

	std::cout << &line << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << line << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	return (0);
}
