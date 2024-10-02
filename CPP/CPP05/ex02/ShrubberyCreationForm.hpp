#pragma once

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;
class Bureaucrat;

class ShrubberyCreationForm: public AForm {
		
	public:
	// Constructors
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &copy);

	// Destructor
		~ShrubberyCreationForm();

	// Operator surcharge
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

	// Member function
		void execute(Bureaucrat const &executor)const;

	// Getter
		std::string getTarget(void)const;

	private:
		const std::string _target;
};

//Surcharge operator
std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm a);