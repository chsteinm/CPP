#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
	std::cout << "a french insult is ready for be used" << std::endl;
}

Weapon::~Weapon() {
	std::cout << "the french insult is destructed" << std::endl;
}

const std::string&	Weapon::getType() {
	return this->_type;
}

void			Weapon::setType(std::string newType) {
	this->_type = newType;
}