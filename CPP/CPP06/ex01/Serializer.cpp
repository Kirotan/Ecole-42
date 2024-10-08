#include <string>
#include <iostream>
#include <stdint.h>
#include "Serializer.hpp"

//Constructors & Destructor
		Serializer::Serializer(){}
		Serializer::Serializer(const Serializer &copy){(void)copy;}
		Serializer::~Serializer(){}


//Surcharge operator
		Serializer	&Serializer::operator=(const Serializer &other){(void)other; return *this;}


//Static methods
uintptr_t	Serializer::serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));
}
