#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "A Facho emerges from the ground" << std::endl;
}

Zombie::Zombie(std::string name) : _name(name) {
	std::cout << name << " emerges from the ground" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->_name << " sinks back to the ground" << std::endl;
}

void	Zombie::annonce() const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}