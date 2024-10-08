#include <string>
#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int	main(){

	Data	tt;
	Data	*dd;

	tt.nb = 42.191f;
	tt.sunnyOrNot = true;


	std::cout << "Adress of tt : " << &tt << std::endl;
	std::cout << "nb tt : " << tt.nb << " Sunny tt : " << tt.sunnyOrNot << std::endl;


	uintptr_t test = Serializer::serialize(&tt);
	std::cout << "uintptr_t : " << test << std::endl;

	dd = Serializer::deserialize(test);
	std::cout << "Adress of dd : " << dd << std::endl;

	std::cout << "nb dd : " << tt.nb << " Sunny dd : " << tt.sunnyOrNot << std::endl;

	return 0;
}
