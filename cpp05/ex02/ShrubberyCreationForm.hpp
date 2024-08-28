# ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

#define TREES "                                  @@@\n                              @ @ @  @ @ @\n                            @  @\\/@ @ /__@\n                            @@@ @\\ / @/  @ @\n                           @\\  \\/@| @ | @\n                          @__\\@ \\ |/ \\| / @\n                             __\\|@|  ||/__/@\n                            /  \\ \\  / /__\n                           @    \\  \\/ /   @\n                                 |\" '|\n                                 |\"  |\n                                 |\"  |\n                                ~|\"  |~\n                            ~~~~       ~~~~\n                          ~~               ~~~"

class ShrubberyCreationForm : public AForm {

private :
	std::string		_target;

public :
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& src);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

	ShrubberyCreationForm(std::string target);

	std::string	getTarget() const;
	void		executeAction() const;

	class	ErrorExecutionException : public std::exception {
		public :
			virtual const char* what() const throw();
	};
};

#endif