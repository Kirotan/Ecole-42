#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include "RPN.hpp"

//Constructors
RPN::RPN(){}
RPN::RPN(RPN const &copy){this->_stack = copy._stack;}

RPN::RPN(const char *line){

	std::string	str(line);

	if (checkLine(line) == false)
		return ;
	reversePolishNotation(str);
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

	//fourth check : enough signs for numbers
	unsigned short	nb = 0;
	unsigned short	sign = 0;

	i = 0;

	while(line[i]){
		if(isdigit(line[i]))
			nb++;
		else if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/')
			sign++;
		i++;
	}

	if(sign != nb - 1){
		std::cerr << "Number of signs is not ok." << std::endl;
		return false;
	}

	//fifth check : not space between each character
	i = 0;
	while(line[i] && line[i + 1]){
		if((((line[i] >= 48 && line[i] <= 57))
		|| line[i] == 43 || line[i] == 45 || line[i] == 47 || line[i] == 42)
		&& line[i + 1] != ' '){
			std::cerr << "Need one space between each character." << std::endl;
			return false;
		}
		i++;
	}

	return true;
}

void	RPN::addNumber(){

	double	nb1 = _stack.top();
	_stack.pop();
	_stack.top() += nb1;

}

void	RPN::subtractNumber(){

	double	nb1 = _stack.top();
	_stack.pop();
	_stack.top() -= nb1;
}

void	RPN::multiplyNumber(){

	double	nb1 = _stack.top();
	_stack.pop();
	_stack.top() *= nb1;
}

void	RPN::diviseNumber(){

	double	nb1 = _stack.top();
	_stack.pop();
	_stack.top() /= nb1;
}

bool	RPN::checkSize(){

	if(_stack.size() < 2){
		std::cerr << "Need 2 numbers before one sign." << std::endl;
		return false;
	}
	return true;
}

void	RPN::reversePolishNotation(std::string line){

	size_t	i = 0;

	while(line[i]){

		if(isdigit(line[i])){
			_stack.push(atol(&line[i]));
		}
		else if(line[i] == '+'){
			if(checkSize() == false)
				return ;
			addNumber();
		}
		else if(line[i] == '-'){
			if(checkSize() == false)
				return ;
			subtractNumber();
		}
		else if(line[i] == '*'){
			if(checkSize() == false)
				return ;
			multiplyNumber();
		}
		else if(line[i] == '/'){
			if(checkSize() == false)
				return ;
			diviseNumber();
		}
		i++;
	}
	std::cout << _stack.top() << std::endl;
}
