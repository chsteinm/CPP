#include "Zombie.hpp"

int	main() {
	Zombie	zombie("LEPEN");
	Zombie*	zombieHorde;
	int		N;

	N = 6;
	zombieHorde = zombie.zombieHorde(N, "Facho");
	zombie.annonce();
	for (int i = 0; i < N; i++)
		zombieHorde[i].annonce();
	delete[] zombieHorde;
	return 0;
}