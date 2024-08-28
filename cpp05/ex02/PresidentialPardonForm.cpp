#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
	std::cout << "Default PresidentialPardonForm constructor called" << std::endl;
	this->_target = "Quentin";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) {
	std::cout << "Copy PresidentialPardonForm constuctor called" << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destuctor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &src) {
	this->_target = src.getTarget();
	if (src.isSigned() == true && this->isSigned() == false)
		this->beSigned(Bureaucrat("God", 1));
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
	std::cout << "Parametric PresidentialPardonForm constructor called" << std::endl;
	this->_target = target;
}

std::string PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void	PresidentialPardonForm::executeAction() const {
		std::cout << this->_target + " has been pardoned by Zaphod Beeblebrox :o" << std::endl;
}