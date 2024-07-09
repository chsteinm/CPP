#include <iostream>
#include <iomanip>
#include "Phonebook.hpp"
#include "Contact.hpp"

int main() {
	Phonebook	phonebook;
	std::string	buf; 
	
	while (std::cin.eof() == false) {
		std::cout << "Tape ADD / SEARCH / EXIT" << std::endl << "> ";
		std::cin >> buf;
		if (!buf.compare("ADD")) {
			phonebook.addContact();
		}
		else if (!buf.compare("SEARCH")){
			phonebook.displayColumns();
		}
		else if (!buf.compare("EXIT"))
			return 0;
	}
	return 0;
}