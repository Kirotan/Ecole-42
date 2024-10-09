#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;
class Bureaucrat;

class PresidentialPardonForm: public AForm {

	public:
	// Constructors
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &copy);

	// Destructor
		virtual ~PresidentialPardonForm();

	// Operator surcharge
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

	// Member function
		void execute(Bureaucrat const &executor)const;

	// Getter
		std::string getTarget(void)const;

	private:
		const std::string _target;
};

//Surcharge operator
std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm a);
