#pragma once
#include <iostream>
#include <stdexcept>

class Bureaucrat{

	public :
	//Constructor & Destructor
		Bureaucrat();
		Bureaucrat(const short grade);
		Bureaucrat(const Bureaucrat &copy);
		~Bureaucrat();

	//Getter
		std::string		getName() const;
		short	getGrade() const;

	//Setter
		void	setName(std::string name);
		void	setGrade(short grade);


	//Surcharge operator
		Bureaucrat	&operator=(const Bureaucrat &other);

	//Bureaucrat variables
		std::string		_name;
		short	_grade;

	//Members functions
		void	incrementGrade();
		void	decrementGrade();

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

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &other);
