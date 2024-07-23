#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	// const Animal* meta = new Animal();
	// const Animal* d = new Dog();
	// const Animal* c = new Cat();

	// std::cout << std::endl << d->getType() << std::endl;
	// std::cout << c->getType() << std::endl << std::endl;

	// c->makeSound();
	// d->makeSound();
	// meta->makeSound();
	// std::cout << std::endl;

	// delete meta;
	// delete d;
	// delete c;
	// std::cout << std::endl;

	// const WrongAnimal* wrongCat = new WrongCat();
	// const WrongAnimal* wrongAnimal = new WrongAnimal();

	// std::cout << std::endl << wrongCat->getType() << std::endl << std::endl;

	// wrongAnimal->makeSound();
	// wrongCat->makeSound();
	// std::cout << std::endl;

	// delete wrongAnimal;
	// delete wrongCat;
	{
		int N = 2;
		Animal* animals[N];
		for (int i = 0; i < N; i++) {
			if (i % 2)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}
		std::cout << std::endl;

		animals[1]->makeSound();
		Cat* a = new Cat();
		*a = *dynamic_cast<Cat*>(animals[1]);
		std::cout << dynamic_cast<Cat*>(animals[1])->getIdea(10) << std::endl;
		std::cout << dynamic_cast<Cat*>(a)->getIdea(10) << std::endl;
		std::cout << std::endl;

		dynamic_cast<Cat*>(animals[1])->setIdea(10, "I want some hug");
		*a = *dynamic_cast<Cat*>(animals[1]);
		std::cout << dynamic_cast<Cat*>(animals[1])->getIdea(10) << std::endl;
		std::cout << dynamic_cast<Cat*>(a)->getIdea(10) << std::endl;
		std::cout << std::endl;

		for (int i = 0; i < N; i++)
			delete animals[i];
		delete a;
	}

		std::cout << std::endl;
		std::cout << std::endl;

	{
		Dog basic;
		{
			Dog tmp = basic;
		}
	}
		std::cout << std::endl;
		std::cout << std::endl;

	Dog basic2;
	{
		Dog tmp(basic2);
	}
	return 0;
}