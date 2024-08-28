#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
	std::cout << "Default RobotomyRequestForm constructor called" << std::endl;
	this->_target = "home";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) {
	std::cout << "Copy RobotomyRequestForm constuctor called" << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destuctor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &src) {
	this->_target = src.getTarget();
	if (src.isSigned() == true && this->isSigned() == false)
		this->beSigned(Bureaucrat("God", 1));
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	std::cout << "Parametric RobotomyRequestForm constructor called" << std::endl;
	this->_target = target;
}

std::string RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void	RobotomyRequestForm::executeAction() const {
	static int	n;
	if (n++ % 2)
		std::cout << this->_target + " has been robotomized successfully (─‿0)╯" << std::endl;
	else
		std::cout << this->_target + " robotomization failed (-_-)" << std::endl;

}