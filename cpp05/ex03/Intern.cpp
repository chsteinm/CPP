#include "Intern.hpp"

Intern::Intern() {
	 std::cout << "Default Intern constuctor called" << std::endl;
	 this->_f[0] = &Intern::makeShrubbery;
	 this->_f[1] = &Intern::makeRobot;
	 this->_f[2] = &Intern::makePresident;
	 this->_form[0] = "ShrubberyCreationForm";
	 this->_form[1] = "RobotomyRequestForm";
	 this->_form[2] = "PresidentialPardonForm";
}

Intern::Intern(const Intern& src) {
	 std::cout << "Copy Intern constuctor called" << std::endl;
	*this = src;
}

Intern::~Intern() {
	 std::cout << "Intern Destructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern& src) {
	 std::cout << "Copy assignment Intern operator called" << std::endl;
	 (void)src;
	return *this;
}

AForm*	Intern::makeForm(std::string name, std::string target) {
	AForm* ret;
	int	iForm = -1;
	while (++iForm < 3)
		if (this->_form[iForm] == name)
			break;
	switch (iForm) {
		case 0:
			ret = (this->*_f[0])(target);
			break;
		case 1:
			ret = (this->*_f[1])(target);
			break;
		case 2:
			ret = (this->*_f[2])(target);
			break;
		default :
			std::cout << "Name doesn't correspond to any form :/" << std::endl;
			return NULL;
	}
	std::cout << "Intern creates " + ret->getName() << std::endl;
	return ret;
}

AForm*	Intern::makeShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::makeRobot(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::makePresident(std::string target) {
	return new PresidentialPardonForm(target);
}
