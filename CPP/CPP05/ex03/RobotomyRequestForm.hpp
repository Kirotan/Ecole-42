#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class AForm;
class Bureaucrat;

class RobotomyRequestForm: public AForm {

	public:
	// Constructors
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &copy);

	// Destructor
		virtual ~RobotomyRequestForm();

	// Operator surcharge
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

	// Member function
		void execute(Bureaucrat const &executor)const;

	// Getter
		std::string getTarget(void)const;

	private:
		const std::string _target;
};

//Surcharge operator
std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm a);
