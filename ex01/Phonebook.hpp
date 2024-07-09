#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class Phonebook {

private :
	Contact contacts[8];
	int		index_of_last_contacts_set;

public :
	Phonebook();
	~Phonebook();
	void displayColumns() const;
	void addContact();
};

#endif