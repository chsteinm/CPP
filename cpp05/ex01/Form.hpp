# ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

protected :
	const std::string	_name;
	bool				_signed;
	const int			_gradeToSign;
	const int			_gradeToExec;

public :
	Form();
	Form(const Form& src);
	~Form();
	Form&	operator=(const Form& src);
	
	Form(std::string name, int gradeToSign, int gradeToExec);

	std::string const	getName() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;
	void				beSigned(const Bureaucrat& bureaucrat);
	bool				isSigned() const;

	class	GradeTooHighException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception {
		public :
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const Form& src);

#endif
