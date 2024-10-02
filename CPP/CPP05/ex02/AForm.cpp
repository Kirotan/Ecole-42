#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

//Constructor
AForm::AForm() : _name("random"), _signed(false), _gradeSigned(150), _gradeExecuted(150){
	std::cout << "Default AForm constructor called." << std::endl;
}

AForm::AForm(const AForm &copy) : _name(copy._name + "_copy"), _signed(copy._signed), _gradeSigned(copy._gradeSigned), _gradeExecuted(copy._gradeExecuted){
	std::cout << "Copy AForm constructor called." << std::endl;
}

AForm::AForm (std::string name, const short gradeSigned, const short gradeExecuted) : _name(name), _signed(false), _gradeSigned(gradeSigned), _gradeExecuted(gradeExecuted){
	std::cout << "Whole AForm constructor called." << std::endl;

	try {
		if (this->getGradeSigned() < 1)
			throw	AForm::GradeTooHighException();
		else if (this->getGradeSigned() > 150)
			throw	AForm::GradeTooLowException();
		else if (this->getGradeExecuted() < 1)
			throw	AForm::GradeTooHighException();
		else if (this->getGradeExecuted() > 150)
			throw	AForm::GradeTooLowException();
	}
	catch (AForm::GradeTooHighException &e) {
		std::cerr << "Impossible to set grade of " << this->_name << std::endl;
		std::cerr << e.what() << std::endl;
		std::cerr << "Default AForm grade initialization to 1." << std::endl;
	}
	catch (AForm::GradeTooLowException &e) {
		std::cerr << "Impossible to set grade of " << this->_name << std::endl;
		std::cerr << e.what() << std::endl;
		std::cerr << "Default AForm grade initialization to 150." << std::endl;
	}
}



//Destructor
AForm::~AForm(){
	std::cout << "AForm destructor called." << std::endl;
}


//Surcharge operator
AForm	&AForm::operator=(const AForm &other){
	this->_signed = other._signed;
	return *this;
}

std::ostream	&operator<<(std::ostream &out, const AForm &other){
	
	out << other.getName() << " form with " << other.getGradeSigned()
	<< " in grade signed and " << other.getGradeExecuted() << " in grade executed." << std::endl;
	return out;
}



//Getter
std::string	AForm::getName() const{
	return this->_name;
}

bool	AForm::getSigned() const{
	return this->_signed;
}

short	AForm::getGradeSigned() const{
	return this->_gradeSigned;
}

short	AForm::getGradeExecuted() const{
	return this->_gradeExecuted;
}


//Setter
void	AForm::setSigned(Bureaucrat &a){
	if (this->_signed == true){
		std::cerr << "AForm already signed." << std::endl;
		return;
	}
	if (a.getGrade() > this->getGradeSigned())
		throw AForm::GradeTooHighException();
	else {
		std::cout << "Bureaucrat " << a._name << " signed AForm " << this->getName() << "." << std::endl;
		this->_signed = true;
	}
}


//Members functions
void	AForm::beSigned(Bureaucrat &a){

	try{
		std::cout << a.getName() <<" bureaucrat trying to signe " << this->_name << " AForm." << std::endl;
		this->setSigned(a);
	}
	catch(AForm::GradeTooHighException &e) {
		std::cerr << a.getName() << " can't signe " << this->getName() << " AForm because grade is too high." << std::endl;
		std::cerr << e.what() << std::endl;
	}
	catch(AForm::GradeTooLowException &e) {
		std::cerr << a.getName() << " can't signe " << this->getName() << " AForm because grade is too low." << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

void AForm::execute(Bureaucrat const &executor)const{
	if (executor.getGrade() > this->getGradeExecuted())
		throw Bureaucrat::GradeTooLowException();
	else if (this->getSigned() == false)
		throw AForm::FormNotSignedException();
}


//Exception
const char*	AForm::GradeTooHighException::what() const throw(){
	return "Grade too high.";
}

const char*	AForm::GradeTooLowException::what() const throw(){
	return "Grade too low.";
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form must be signed before executing it.");
};