#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
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