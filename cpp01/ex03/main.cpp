#include "HumanB.hpp"

int main() {
	{
		Weapon frenchInsult = Weapon("\"Casse-toi pov'con !\"");

		HumanA sarko("Sarko", frenchInsult);
		sarko.attack();
		frenchInsult.setType("\"Grande Perch va !\"");
		sarko.attack();
	}
	{
		Weapon frenchInsult = Weapon("\"T'es trop petit je t'entends pas !\"");

		HumanB someone("Someone");
		someone.setWeapon(frenchInsult);
		someone.attack();
		frenchInsult.setType("\"Jolie bracelet au pied en passant !\"");
		someone.attack();
	}

	return 0;
}
