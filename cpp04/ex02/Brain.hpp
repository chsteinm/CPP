# ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {

protected :
	std::string	ideas[100];

public :
	Brain();
	Brain(const Brain& src);
	~Brain();
	Brain&	operator=(const Brain& src);
	void	setIdea(int i, std::string newIdea);
	std::string	getIdea(int i) const;
};

#endif
