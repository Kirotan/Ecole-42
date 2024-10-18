#include<iostream>
#include<string>
#include<vector>
#include<exception>
#include"Span.hpp"

int main(){

	// Span sp = Span(5);

	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);

	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;


	unsigned int N = 1000000;
	Span sp = Span(N);

	try {
		std::vector<int> largeVector(N);

		for (unsigned int i = 0; i < N; ++i) {
			largeVector[i] = i + 1;
		}

		sp.addNumber(largeVector.begin(), largeVector.end());

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		}

	return 0;
}