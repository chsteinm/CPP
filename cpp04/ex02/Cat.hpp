# ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private :
	Brain*	_brain;

public :
	Cat();
	Cat(const Cat& src);
	~Cat();
	Cat&	operator=(const Cat& src);

	void	makeSound() const; //override

	void		setIdea(int i, std::string newIdea);
	std::string	getIdea(int i);
};

#endif