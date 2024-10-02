#include "Span.hpp"

int	main() {

	//basic test
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
		sp.addMaxNumbers();
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
	return 0;
}