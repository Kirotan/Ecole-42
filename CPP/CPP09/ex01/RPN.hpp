#include <iostream>
#include <string>
#include <stack>

class RPN{

	public :
	//Member function
		void	reversePolishNotation(std::string line);
		RPN(const char *line);

	//Destructor
		~RPN();

	private :
		std::stack<double>	_stack;

	// Constructors
		RPN();
		RPN(RPN const &copy);

	//Surcharger operator
		RPN	&operator=(RPN const &other);

	//Member functions
		bool		checkLine(const char *line) const;
		void		addNumber();
		void		subtractNumber();
		void		multiplyNumber();
		void		diviseNumber();

};
