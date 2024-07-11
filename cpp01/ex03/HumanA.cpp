#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {
	std::cout << name << " is ready to attack" << std::endl;
}

HumanA::~HumanA() {
	std::cout << this->name << " kill itself" << std::endl;
}

void			HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType() 
	<< std::endl;
}