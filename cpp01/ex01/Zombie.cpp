#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "A Facho emerges from the ground" << std::endl;
}

Zombie::Zombie(std::string name) : name(name) {
	std::cout << name << " emerges from the ground" << std::endl;
}

Zombie::~Zombie() {
	std::cout << this->name << " sinks back to the ground" << std::endl;
}

void	Zombie::annonce() {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie*	Zombie::zombieHorde(int N, std::string name) {
	Zombie* zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++)
		zombieHorde[i].name = name;
	return zombieHorde;
}