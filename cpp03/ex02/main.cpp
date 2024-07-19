#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main( void ) {
	FragTrap c("C");

	c.printInfo();
	c.attack("A");
	c.takeDamage(90);
	c.printInfo();
	c.highFivesGuys();
	return 0;
}