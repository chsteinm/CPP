#include "Zombie.hpp"

int	main() {
	Zombie	zombie("Facho");
	Zombie*	newZombie;

	newZombie = zombie.newZombie("neoFacho");
	zombie.randomChump("Macron");
	zombie.annonce();
	newZombie->annonce();
	delete newZombie;
	return 0;
}