#pragma once
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

class Bureaucrat{

	public :
	//Constructor & Destructor
		Bureaucrat();
		Bureaucrat(const short grade);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, const short grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

	//Getter
		std::string		getName() const;
		short			getGrade() const;

	//Surcharge operator
		Bureaucrat	&operator=(const Bureaucrat &other);

	//Bureaucrat variables
		const std::string		_name;
		short					_grade;

	//Members functions
		void		incrementGrade();
		void		decrementGrade();
		void		signAForm(AForm &a);
		void 		executeForm(AForm &form);

	//Handle exception
		class GradeTooHighException : public std::exception {

			public :
				const char*	what() const throw();
		};

		class GradeTooLowException : public std::exception {

			public :
				const char*	what() const throw();
		};

	private :
	//Setter
		void	setGrade(short grade);

};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &other);
