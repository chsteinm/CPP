#include "ClapTrap.hpp"

int	main( void ) {
	ClapTrap a("A");
	ClapTrap b;

	a.printInfo();
	a.attack("B");
	a.takeDamage(8);
	a.printInfo();
	a.beRepaired(1);
	a.printInfo();
	b = a;
	b.setName("B");
	b.printInfo();
	a.takeDamage(3);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	b.beRepaired(1);
	return 0;
}