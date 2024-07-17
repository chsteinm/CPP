#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon) {
	std::cout << name << " is ready to attack" << std::endl;
}

HumanA::~HumanA() {
	std::cout << this->_name << " is incarcerated" << std::endl;
}

void			HumanA::attack() {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() 
	<< std::endl;
}