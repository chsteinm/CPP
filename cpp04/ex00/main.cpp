#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	const Animal* meta = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();

	std::cout << std::endl << d->getType() << std::endl;
	std::cout << c->getType() << std::endl << std::endl;

	c->makeSound();
	d->makeSound();
	meta->makeSound();
	std::cout << std::endl;

	delete meta;
	delete d;
	delete c;
	std::cout << std::endl;

	const WrongAnimal* wrongCat = new WrongCat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();

	std::cout << std::endl << wrongCat->getType() << std::endl << std::endl;

	wrongAnimal->makeSound();
	wrongCat->makeSound();
	std::cout << std::endl;

	delete wrongAnimal;
	delete wrongCat;
	return 0;
}