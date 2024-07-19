#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void ) {
	ScavTrap b("B");
	ScavTrap c;

	b.printInfo();
	b.attack("A");
	b.takeDamage(10);
	c = b;
	c.setName("C");
	c.printInfo();
	b.guardGate();
	b.takeDamage(90);
	for (int x = 0; x < 49; x++)
		c.beRepaired(1);
	return 0;
}