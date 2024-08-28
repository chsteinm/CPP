#include "Form.hpp"

Form::Form() : _name("defaultForm"), _gradeToSign(1), _gradeToExec(50) {
	 std::cout << "Default Form constuctor called" << std::endl;
}

Form::Form(const Form& src) : _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	 std::cout << "Copy Form constuctor called" << std::endl;
	*this = src;
}

Form::~Form() {
	 std::cout << "Form Destructor called" << std::endl;
}

Form&	Form::operator=(const Form& src) {
	 std::cout << "Copy assignment Form operator called" << std::endl;
	 this->_signed = src._signed;
	return *this;
}

std::ostream& operator<<(std::ostream& o, const Form& src) {
	if (src.isSigned())
		o << src.getName() + " is signed";
	else
		o << src.getName() + " isn't signed";
	o << " and must have grade " << src.getGradeToSign() << " to be signed, and " << src.getGradeToExec() << " to be exec";
	return o;
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	std::cout << "Parametric Form constuctor called" << std::endl;
	this->_signed = false;
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw Form::GradeTooLowException();
}

const std::string	Form::getName() const {
	return this->_name;
}

int	Form::getGradeToSign() const {
	return this->_gradeToSign;
}

int	Form::getGradeToExec() const {
	return this->_gradeToExec;
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Grade too low to sign the form ¯\\_( ͡° ͜ʖ ͡°)_/¯";
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Grade too high (ʘ‿ʘ)╯";
}

const char*	Form::FormAlreadySignedException::what() const throw() {
	return "Form is already signed ¯\\_(O‿o)╯";
}

bool	Form::isSigned() const {
	return this->_signed;
}

void	Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	else if (this->_signed == true)
		throw Form::FormAlreadySignedException();
	this->_signed = true;
}