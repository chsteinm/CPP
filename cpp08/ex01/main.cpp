#include "Span.hpp"

int	main() {
	srand(time(NULL));

	//positive numbers test
	{
		Span sp;

		sp.addNumber(42);
		sp.addNumber(0);
		sp.addNumber(40);
		std::cout << "sp numbers : ";
		for (unsigned int i = 0; i < 3; i++)
			std::cout << sp[i] << ' ';
		std::cout << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	std::cout << std::endl;

	//negative numbers test 
	{
		Span sp;

		sp.addNumber(-42);
		sp.addNumber(0);
		sp.addNumber(-40);
		std::cout << "sp numbers : ";
		for (unsigned int i = 0; i < 3; i++)
			std::cout << sp[i] << ' ';
		std::cout << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	std::cout << std::endl;

	//negative and positive numbers test 
	{
		Span sp;

		sp.addNumber(42);
		sp.addNumber(0);
		sp.addNumber(-40);
		std::cout << "sp numbers : ";
		for (unsigned int i = 0; i < 3; i++)
			std::cout << sp[i] << ' ';
		std::cout << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	std::cout << std::endl;

	//max reach exception test
	{
		Span sp(2);

		try {
			sp.addNumber(42);
			sp.addNumber(0);
			sp.addNumber(84);
			std::cout << sp.longestSpan() << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	
	//not enought numbers exception test
	{
		Span sp(2);

		try {
			sp.addNumber(42);
			std::cout << sp.longestSpan() << std::endl;
			std::cout << sp.shortestSpan() << std::endl;
		}
		catch(const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	
	//10 000 numbers test
	{
		Span sp;
		sp.addNumber(42);
		sp.addMaxNumbers();
		std::cout << "First 3 numbers of " << sp.getSize() << " vector numbers : ";
		for (int i = 0; i < 3; i++)
			std::cout << sp[i] << " ";
		std::cout << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	std::cout << std::endl;

	//100 000 numbers test
	{
		Span sp(100000);
		sp.addNumber(42);
		sp.addMaxNumbers();
		std::cout << "First 3 numbers of " << sp.getSize() << " vector numbers : ";
		for (int i = 0; i < 3; i++)
			std::cout << sp[i] << " ";
		std::cout << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp.shortestSpan() << std::endl;
	}
	std::cout << std::endl;
	
	//canonic form tests
	{
		Span sp(3);
		sp.addMaxNumbers();
		std::cout << "Numbers of sp : ";
		for (int i = 0; i < sp.getSize(); i++)
			std::cout << sp[i] << " ";
		std::cout << std::endl;

		Span cpy(sp);
		std::cout << "Numbers of cpy : ";
		for (int i = 0; i < sp.getSize(); i++)
			std::cout << sp[i] << " ";
		std::cout << std::endl;

		Span cpy2;
		cpy2 = cpy;
		std::cout << "Numbers of cpy2 : ";
		for (int i = 0; i < sp.getSize(); i++)
			std::cout << sp[i] << " ";
		std::cout << std::endl;
	}
	return 0;
}