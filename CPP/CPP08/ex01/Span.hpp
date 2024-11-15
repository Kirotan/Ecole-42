#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <exception>

class Span{
	public:
	//Constructors
		Span(unsigned int n);
		Span(Span const &copy);

	//Destructor
		~Span();

	//Surcharge operator
		Span	&operator=(Span const &other);

	//Members functions
		int		shortestSpan();
		long	longestSpan();
		void	addNumber(int nb);

	//Template range of iterators for several call to addNumber
		template<typename InputIterator>
		void	addNumber(InputIterator begin, InputIterator end) {
		if (std::distance(begin, end) + _vecInt.size() > _n)
			throw SpanFullException();
		_vecInt.insert(_vecInt.end(), begin, end);
		}

	//Exceptions
	class SpanFullException : public std::exception {
		const char* what() const throw();
	};

	class NotEnoughNumbersException : public std::exception {
		const char* what() const throw();
	};


	private:
		Span();

		unsigned int		_n;
		std::vector<int>	_vecInt;
};
