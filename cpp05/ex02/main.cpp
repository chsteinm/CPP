#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	Bureaucrat p("Macron", 1);
	ShrubberyCreationForm s("Garden");
	RobotomyRequestForm	r("Population");
	PresidentialPardonForm pp("Quentin");

	std::cout << p << std::endl << s << std::endl;
	p.signForm(s);
	p.executeForm(s);
	std::cout << std::endl << r << std::endl;
	p.signForm(r);
	p.executeForm(r);
	p.executeForm(r);
	p.executeForm(r);
	p.executeForm(r);
	std::cout << std::endl << pp << std::endl;
	p.executeForm(pp);
	p.signForm(pp);
	p.executeForm(pp);
	return 0;
}