#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type) {
	std::cout << "a french insult is ready for be used" << std::endl;
}

Weapon::~Weapon() {
	std::cout << "the french insult is destructed" << std::endl;
}

std::string&	Weapon::getType() {
	return this->type;
}

void			Weapon::setType(std::string newType) {
	this->type = newType;
}