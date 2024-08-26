# ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat {

protected :
	std::string const	_name;
	int					_grade;

public :
	Bureaucrat();
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat& src);
	
	Bureaucrat(std::string name, int grade);

	std::string const	getName() const;
	int					getGrade() const;
	void				incrementGrade();
	void				decrementGrade();

	class	GradeTooHighException : public std::exception {
		public :
			virtual const char* what() const throw();
	};

	class	GradeTooLowException : public std::exception {
		public :
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& src);

#endif
