#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void ) {
	DiamondTrap d("D");

	d.printInfo();
	d.attack("A");
	d.takeDamage(90);
	d.printInfo();
	d.guardGate();
	d.highFivesGuys();
	d.whoAmI();
	return 0;
}