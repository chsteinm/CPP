#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Default Cat constuctor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(const Cat& src) {
	std::cout << "Copy Cat constuctor called" << std::endl;
	this->_brain = new Brain();
	*this->_brain = *src._brain;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	if (this->_brain) {
		delete this->_brain;
	}
}

Cat&	Cat::operator=(const Cat& src) {
	std::cout << "Copy cat assignment operator called" << std::endl;
	this->_type = src._type;
	if (!this->_brain) {
		this->_brain = new Brain();
	}
	*this->_brain = *src._brain;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "Miaou :3" << std::endl;
}

void	Cat::setIdea(int i, std::string newIdea) {
	this->_brain->setIdea(i, newIdea);
}

std::string	Cat::getIdea(int i) {
	return this->_brain->getIdea(i);
}