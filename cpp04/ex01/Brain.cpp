#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Default Brain constuctor called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "I want food";
}

Brain::Brain(const Brain& src) {
	std::cout << "Copy Brain constuctor called" << std::endl;
	*this = src;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(const Brain& src) {
	std::cout << "Copy Brain assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	return *this;
}

void	Brain::setIdea(int i, std::string newIdea) {
	this->ideas[i] = newIdea;
}

std::string	Brain::getIdea(int i) const {
	return this->ideas[i];
}