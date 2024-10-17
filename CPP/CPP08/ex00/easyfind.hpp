#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


// //template function
template<typename T>
void	easyfind(T &haystack, int needle){

	//exception
	class ExceptionIterator : public std::exception{

		public :
			const char*	what() const throw(){
				return "No occurence.";
			}
	};

	typename T::iterator	iter = std::find(haystack.begin(), haystack.end(), needle);
	if(iter == haystack.end())
		throw	ExceptionIterator();
	else
		std::cout << "Found : " << *iter << std::endl;

}

