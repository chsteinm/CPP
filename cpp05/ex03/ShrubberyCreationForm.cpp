#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "Default ShrubberyCreationForm constructor called" << std::endl;
	this->_target = "home";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) {
	std::cout << "Copy ShrubberyCreationForm constuctor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destuctor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src) {
	this->_target = src.getTarget();
	if (src.isSigned() == true && this->isSigned() == false)
		this->beSigned(Bureaucrat("God", 1));
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137) {
	std::cout << "Parametric ShrubberyCreationForm constructor called" << std::endl;
	this->_target = target;
}

std::string ShrubberyCreationForm::getTarget() const {
	return this->_target;
}

void	ShrubberyCreationForm::executeAction() const {
	std::ofstream	file;
	std::string filenameReplace = this->_target;
	filenameReplace.append("_shrubbery");
	file.open(filenameReplace.c_str());
	if (file.is_open() == false)
		throw ShrubberyCreationForm::ErrorExecutionException();
	file << TREES;
	file.close();
}

const char*	ShrubberyCreationForm::ErrorExecutionException::what() const throw() {
	return "Error in the plantation of the Shrubbery trees";
}