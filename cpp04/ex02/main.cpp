#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main() {
	// Animal nop;
	{
		Dog basic;
		{
			Dog tmp = basic;
			basic.makeSound();
		}
	}

		std::cout << std::endl;
		std::cout << std::endl;

	Cat basic2;
	{
		Cat tmp(basic2);
		tmp.makeSound();
	}
	return 0;
}