#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main() {
	Bureaucrat p("Macron", 5);
	ShrubberyCreationForm s("Garden");
	RobotomyRequestForm	r("Population");
	PresidentialPardonForm pp("Quentin");

	std::cout << std::endl << p << std::endl << s << std::endl;
	p.executeForm(s);
	p.signForm(s);
	p.executeForm(s);
	std::cout << std::endl << r << std::endl;
	p.executeForm(r);
	p.signForm(r);
	p.executeForm(r);
	p.executeForm(r);
	p.executeForm(r);
	p.executeForm(r);
	std::cout << std::endl << pp << std::endl;
	p.signForm(pp);
	p.decrementGrade();
	p.executeForm(pp);
	p.incrementGrade();
	p.executeForm(pp);
	std::cout << std::endl;
	return 0;
}