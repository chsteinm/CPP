#include "Form.hpp"

Form::Form() : _name("Pierre"), _grade(50) {
	 std::cout << "Default Form constuctor called" << std::endl;
}

Form::Form(const Form& src) {
	 std::cout << "Copy Form constuctor called" << std::endl;
	*this = src;
}

Form::~Form() {
	 std::cout << "Form Destructor called" << std::endl;
}

Form&	Form::operator=(const Form& src) {
	 std::cout << "Copy assignment Form operator called" << std::endl;
	 this->_grade = src.getGrade();
	return *this;
}

Form::Form(std::string name, int grade) : _name(name), _grade(grade) {
	std::cout << "Parametric Form constuctor called" << std::endl;
	if (this->_grade < 1)
		throw Form::GradeTooHighException();
	if (this->_grade > 150)
		throw Form::GradeTooLowException();
}

const std::string	Form::getName() const {
	return this->_name;
}

int	Form::getGrade() const {
	return this->_grade;
}

std::ostream& operator<<(std::ostream& o, const Form& src) {
	o << src.getName() + ", Form grade " << src.getGrade();
	return o;
}
