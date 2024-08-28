# ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm {

private :
	std::string		_target;

public :
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& src);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

	PresidentialPardonForm(std::string target);

	std::string	getTarget() const;
	void		executeAction() const;
};

#endif