#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {

private :
	Contact contacts[8];

public :
	Phonebook();
	~Phonebook();
	void displayColumns();
};

#endif