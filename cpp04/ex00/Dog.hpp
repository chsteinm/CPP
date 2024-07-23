# ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {

public :
	Dog();
	Dog(std::string type);
	Dog(const Dog& src);
	~Dog();
	Dog&	operator=(const Dog& src);

	void		makeSound() const; //override
};

#endif