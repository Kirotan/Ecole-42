#include "Span.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <algorithm>
#include <limits>

Span::Span() : _n(0), _vecInt(0){}

Span::Span(unsigned int n) : _n(n), _vecInt(std::vector<int>()){};

Span::Span(Span const &copy) : _n(copy._n){this->_vecInt.clear(); this->_vecInt = copy._vecInt;}

Span::~Span(){}

Span	&Span::operator=(Span const &other){this->_n = other._n; this->_vecInt = other._vecInt; return *this;}

void	Span::addNumber(int nb){

	if(this->_vecInt.size() < this->_n)
		this->_vecInt.push_back(nb);
	else
		throw SpanFullException();
}

int	Span::shortestSpan() {
	if (_vecInt.size() < 2) {
		throw NotEnoughNumbersException();
	}
	std::vector<int> sorted = _vecInt;
	std::sort(sorted.begin(), sorted.end());

	int shortest = std::numeric_limits<int>::max();
	for (size_t i = 1; i < sorted.size(); ++i) {
		int span = sorted[i] - sorted[i - 1];
		if (span < shortest) {
			shortest = span;
		}
	}
	return shortest;
}

long	Span::longestSpan() {
	if (this->_vecInt.size() < 2)
		throw NotEnoughNumbersException();
	int minVal = *std::min_element(_vecInt.begin(), _vecInt.end());
	int maxVal = *std::max_element(_vecInt.begin(), _vecInt.end());
	return maxVal - minVal;
}

const	char* Span::SpanFullException::what() const throw(){
	return "Span is full.";
}

const	char* Span::NotEnoughNumbersException::what() const throw(){
	return "Not enough numbers to calculate span.";
}
