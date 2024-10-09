#pragma once
#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	public :
	//Constructor
		AForm();
		AForm(const AForm &copy);
		AForm (std::string name, const short gradeSigned, const short gradeExecuted);

	//Destructor
		virtual ~AForm();

	//Surcharge operator
		AForm	&operator=(const AForm &other);


	//Getter
		std::string		getName() const;
		bool			getSigned() const;
		short			getGradeSigned() const;
		short			getGradeExecuted() const;

	//Setter
		void	setSigned(Bureaucrat &a);


	//Members functions
		void			beSigned(Bureaucrat &a);
		virtual void 	execute(Bureaucrat const &executor)const = 0;

	//Handle exception
	class GradeTooHighException : public std::exception {

		public :
			virtual const char*	what() const throw();

	};

	class GradeTooLowException : public std::exception {

		public :
			virtual const char*	what() const throw();

	};

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	private :
		const std::string	_name;
		bool				_signed;
		const short			_gradeSigned;
		const short			_gradeExecuted;

};

std::ostream	&operator<<(std::ostream &out, const AForm &other);
