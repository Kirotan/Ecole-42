#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

//Constructor
Form::Form() : _name("random"), _signed(false), _gradeSigned(150), _gradeExecuted(150){
	std::cout << "Default form constructor called." << std::endl;
}

Form::Form(const Form &copy) : _name(copy._name + "_copy"), _signed(copy._signed), _gradeSigned(copy._gradeSigned), _gradeExecuted(copy._gradeExecuted){
	std::cout << "Copy form constructor called." << std::endl;
}

Form::Form (std::string name, const short gradeSigned, const short gradeExecuted) : _name(name), _gradeSigned(gradeSigned), _gradeExecuted(gradeExecuted){
	std::cout << "Whole form constructor called." << std::endl;

	try {
		if (this->getGradeSigned() < 1)
			throw	Form::GradeTooHighException();
		else if (this->getGradeSigned() > 150)
			throw	Form::GradeTooLowException();
		else if (this->getGradeExecuted() < 1)
			throw	Form::GradeTooHighException();
		else if (this->getGradeExecuted() > 150)
			throw	Form::GradeTooLowException();
	}
	catch (Form::GradeTooHighException &e) {
		std::cerr << "Impossible to set grade of " << this->_name << std::endl;
		std::cerr << e.what() << std::endl;
		std::cerr << "Default form grade initialization to 1." << std::endl;
	}
	catch (Form::GradeTooLowException &e) {
		std::cerr << "Impossible to set grade of " << this->_name << std::endl;
		std::cerr << e.what() << std::endl;
		std::cerr << "Default form grade initialization to 150." << std::endl;
	}
}



//Destructor
Form::~Form(){
	std::cout << "Destructor called." << std::endl;
}


//Surcharge operator
Form	&Form::operator=(const Form &other){
	this->_signed = other._signed;
	return *this;
}


//Getter
std::string	Form::getName() const{
	return this->_name;
}

bool	Form::getSigned() const{
	return this->_signed;
}

short	Form::getGradeSigned() const{
	return this->_gradeSigned;
}

short	Form::getGradeExecuted() const{
	return this->_gradeExecuted;
}


//Setter
void	Form::setSigned(Bureaucrat &a){
	if (this->_signed == true){
		std::cerr << "Form already signed." << std::endl;
		return;
	}
	if (a.getGrade() > this->getGradeSigned())
		throw Form::GradeTooHighException();
	else {
		std::cout << "Bureaucrat " << this->_name << " signed form " << a.getName() << "." << std::endl;
		this->_signed = true;
	}
}


//Members functions
void	Form::beSigned(Bureaucrat &a){

	try{
		std::cout << a.getName() <<" bureaucrat trying to signe " << this->_name << " form." << std::endl;
		this->setSigned(a);
	}
	catch(Form::GradeTooHighException &e) {
		std::cerr << a.getName() << " can't signe " << this->getName() << " form because grade is too high." << std::endl;
		std::cerr << e.what() << std::endl;
	}
	catch(Form::GradeTooLowException &e) {
		std::cerr << a.getName() << " can't signe " << this->getName() << " form because grade is too low." << std::endl;
		std::cerr << e.what() << std::endl;
	}
}


//Exception
const char*	Form::GradeTooHighException::what() const throw(){
	return "Grade too high.";
}

const char*	Form::GradeTooLowException::what() const throw(){
	return "Grade too low.";
}
