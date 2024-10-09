#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

	public :
	//Constructor
		Form();
		Form(const Form &copy);
		Form (std::string name, const short gradeSigned, const short gradeExecuted);

	//Destructor
		~Form();

	//Surcharge operator
		Form	&operator=(const Form &other);


	//Getter
		std::string		getName() const;
		bool			getSigned() const;
		short			getGradeSigned() const;
		short			getGradeExecuted() const;

	//Setter
		void	setSigned(Bureaucrat &a);


	//Members functions
		void	beSigned(Bureaucrat &a);


	private :
		const std::string	_name;
		bool				_signed;
		const short			_gradeSigned;
		const short			_gradeExecuted;


	//Handle exception
	class GradeTooHighException : public std::exception {

		public :
			const char*	what() const throw();

	};

	class GradeTooLowException : public std::exception {

		public :
			const char*	what() const throw();

	};

};

std::ostream	&operator<<(std::ostream &out, const Form &other);
