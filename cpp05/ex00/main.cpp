#include "Bureaucrat.hpp"

int	main() {
	{
		Bureaucrat a("Jean", 150);
		try {
			std::cout << a << std::endl;
			a.decrementGrade();
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Bureaucrat b("Henri", 1);
		try {
			std::cout << b << std::endl;
			b.incrementGrade();
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Bureaucrat c("Artur", 2);
		try {
			std::cout << c << std::endl;
			c.incrementGrade();
			std::cout << c << std::endl;
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}