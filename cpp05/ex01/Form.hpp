# ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>

class Form {

protected :
	std::string const	_name;
	int					_grade;

public :
	Form();
	Form(const Form& src);
	~Form();
	Form&	operator=(const Form& src);
	
	Form(std::string name, int grade);

	std::string const	getName() const;
	int					getGrade() const;

	class	GradeTooHighException : public std::exception {
		public :
			virtual const char* what() const throw() {
				return "Grade too high (ʘ‿ʘ)╯";
			}
	};

	class	GradeTooLowException : public std::exception {
		public :
			virtual const char* what() const throw() {
				return "Grade too low ¯\\_( ͡° ͜ʖ ͡°)_/¯";
			}
	};
};

std::ostream& operator<<(std::ostream& o, const Form& src);

#endif
