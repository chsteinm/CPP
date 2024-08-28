# ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
private :
	AForm*	(Intern::*_f[3])(std::string target);
	std::string _form[3];

public :
	Intern();
	Intern(const Intern& src);
	~Intern();
	Intern&	operator=(const Intern& src);
	
	AForm*	makeForm(std::string name, std::string target);

	AForm*	makeShrubbery(std::string target);
	AForm*	makeRobot(std::string target);
	AForm*	makePresident(std::string target);
};

#endif