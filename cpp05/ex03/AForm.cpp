#include "AForm.hpp"

AForm::AForm() : _name("defaultAForm"), _gradeToSign(1), _gradeToExec(50) {
	 std::cout << "Default AForm constuctor called" << std::endl;
}

AForm::AForm(const AForm& src) : _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {
	 std::cout << "Copy AForm constuctor called" << std::endl;
	*this = src;
}

AForm::~AForm() {
	 std::cout << "AForm Destructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm& src) {
	 std::cout << "Copy assignment AForm operator called" << std::endl;
	 this->_signed = src._signed;
	return *this;
}

std::ostream& operator<<(std::ostream& o, const AForm& src) {
	if (src.isSigned())
		o << src.getName() + " is signed";
	else
		o << src.getName() + " isn't signed";
	o << " and must have grade " << src.getGradeToSign() << " to be signed, and " << src.getGradeToExec() << " to be exec";
	return o;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	std::cout << "Parametric AForm constuctor called" << std::endl;
	this->_signed = false;
	if (this->_gradeToSign < 1 || this->_gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (this->_gradeToSign > 150 || this->_gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

const std::string	AForm::getName() const {
	return this->_name;
}

int	AForm::getGradeToSign() const {
	return this->_gradeToSign;
}

int	AForm::getGradeToExec() const {
	return this->_gradeToExec;
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "Grade too low ¯\\_( ͡° ͜ʖ ͡°)_/¯";
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "Grade too high (ʘ‿ʘ)╯";
}

const char*	AForm::FormAlreadySignedException::what() const throw() {
	return "Form is already signed ¯\\_(O‿o)╯";
}

const char*	AForm::FormNotSignedException::what() const throw() {
	return "Form isn't signed ¯\\_(*~*)_/¯";
}

bool	AForm::isSigned() const {
	return this->_signed;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	else if (this->_signed == true)
		throw AForm::FormAlreadySignedException();
	this->_signed = true;
}

void	AForm::execute(const Bureaucrat& executor) const {
	if (executor.getGrade() > this->_gradeToExec)
		throw AForm::GradeTooLowException();
	else if (this->_signed == false)
		throw AForm::FormNotSignedException();
}