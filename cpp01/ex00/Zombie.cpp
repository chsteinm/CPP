#include "Zombie.hpp"

Zombie::Zombie(std::string name) : name(name) {
	std::cout << name << " emerges from the ground" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->name << " sinks back to the ground" << std::endl;
}

void	Zombie::annonce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}