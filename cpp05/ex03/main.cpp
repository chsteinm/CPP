#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main() {
	Intern i;
	Bureaucrat god("God", 1);
	AForm* r = i.makeForm("RobotomyRequestForm", "Population");

	god.signForm(*r);
	god.executeForm(*r);
	delete r;
	r = i.makeForm("RoboomyRequestForm", "Population");
	delete r;
	return 0;
}