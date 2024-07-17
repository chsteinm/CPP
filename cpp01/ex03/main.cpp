#include "HumanB.hpp"

int main() {
	{
		Weapon frenchInsult = Weapon("\"Casse-toi pov'con !\"");

		HumanA sarko("Sarko", frenchInsult);
		sarko.attack();
		frenchInsult.setType("\"Quelle indignite !\"");
		sarko.attack();
	}
	{
		Weapon frenchInsult = Weapon("\"Abrutis, menteur !\"");

		HumanB someone("Meluch");
		someone.setWeapon(frenchInsult);
		someone.attack();
		frenchInsult.setType("\"Fromages lyophilisés !\"");
		someone.attack();
	}

	return 0;
}
