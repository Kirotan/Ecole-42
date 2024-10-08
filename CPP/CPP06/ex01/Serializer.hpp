#pragma once
#include <string>
#include <iostream>
#include <stdint.h>
#include "Data.hpp"

class Serializer{

	public :
	//Static methods
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private :
	//Constructors & Destructor
		Serializer();
		Serializer(const Serializer &copy);
		~Serializer();

	//Surcharge operator
		Serializer	&operator=(const Serializer &other);

};
