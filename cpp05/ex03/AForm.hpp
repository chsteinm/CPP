# ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private :
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExec;

public :
	AForm();
	AForm(const AForm& src);
	virtual ~AForm();
	AForm&	operator=(const AForm& src);
	
	AForm(std::string name, int gradeToSign, int gradeToExec);

	std::string const	getName() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;
	bool				isSigned() const;
	void				beSigned(const Bureaucrat& bureaucrat);
	void				execute(const Bureaucrat& executor) const;
	virtual void		executeAction() const = 0;

	class	GradeTooHighException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

	class	FormAlreadySignedException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

	class	FormNotSignedException : public std::exception {
		public :
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const AForm& src);

#endif
