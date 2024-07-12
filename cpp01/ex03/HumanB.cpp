#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name) {
	std::cout << name << " is ready to attack" << std::endl;
}

HumanB::~HumanB() {
	std::cout << this->_name << " kill itself" << std::endl;
}

void	HumanB::attack() const {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() 
	<< std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}