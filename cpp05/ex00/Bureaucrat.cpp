#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Pierre"), _grade(50) {
	 std::cout << "Default Bureaucrat constuctor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) {
	 std::cout << "Copy Bureaucrat constuctor called" << std::endl;
	*this = src;
}

Bureaucrat::~Bureaucrat() {
	 std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src) {
	 std::cout << "Copy assignment Bureaucrat operator called" << std::endl;
	 this->_grade = src.getGrade();
	return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Parametric Bureaucrat constuctor called" << std::endl;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const std::string	Bureaucrat::getName() const {
	return this->_name;
}

int	Bureaucrat::getGrade() const {
	return this->_grade;
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& src) {
	o << src.getName() + ", bureaucrat grade " << src.getGrade();
	return o;
}

void	Bureaucrat::incrementGrade() {
	this->_grade--;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	this->_grade++;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low ¯\\_( ͡° ͜ʖ ͡°)_/¯";
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high (ʘ‿ʘ)╯";
}