#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name) {
	std::cout << name << " is ready to attack" << std::endl;
}

HumanB::~HumanB() {
	std::cout << this->name << " kill itself" << std::endl;
}

void	HumanB::attack() const {
	std::cout << this->name << " attacks with their " << this->weapon->getType() 
	<< std::endl;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->weapon = &weapon;
}