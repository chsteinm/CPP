# ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm {

private :
	std::string		_target;

public :
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& src);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

	RobotomyRequestForm(std::string target);

	std::string	getTarget() const;
	void		executeAction() const;
};

#endif