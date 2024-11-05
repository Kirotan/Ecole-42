#include <iostream>
#include <string>
#include <stack>
#include "RPN.hpp"

//Constructors
RPN::RPN(){}
RPN::RPN(RPN const &copy){this->_stack = copy._stack;}

RPN::RPN(const char *line){

	if (checkLine(line) == false)
		return ;
	reversePolishNotation(line);
}


//Destructor
RPN::~RPN(){}

//Surcharger operator
RPN	&RPN::operator=(RPN const &other){
	if(this->_stack == other._stack)
		return *this;
	else
		this->_stack = other._stack;
	return *this;
}


//Member functions
void	RPN::reversePolishNotation(std::string line){

	(void)line;
}

bool	RPN::checkLine(const char *line) const{

	unsigned short	i = 0;

	//first check : digit, signs and space
	while(line[i]){
		if((!(line[i] >= 48 && line[i] <= 57))
		&& line[i] != 43 && line[i] != 45 && line[i] != 47 && line[i] != 42
		&& line[i] != ' '){
			std::cerr << "Input must be a digit, space or  +  -  *  /" << std::endl;
			return false;
		}
		i++;
	}

	//second check : not 2 consecutive spaces
	i = 0;
	while(line[i]){
		if(line[i + 1] && line[i] == ' '){
			if(line[i + 1] == ' '){
				std::cerr << "Consecutive space is forbidden." << std::endl;
				return false;
			}
		}
		i++;
	}

	//third check : numbers between 0 and 9
	i = 0;
	while(line[i]){
		if(line[i + 1] && (line[i] >= 48 && line[i] <= 57)){
			if(line[i + 1] >= 48 && line[i + 1] <= 57){
				std::cerr << "Numbers must be between 0 and 9." << std::endl;
				return false;
			}
		}
		i++;
	}

	return true;
}
