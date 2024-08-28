#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	{
		Form f("Dissolution", 50, 2);
		Bureaucrat a("Jean", 150);
		try {
			std::cout << a << std::endl;
			a.signForm(f);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << std::endl;
	{
		Form f("Dissolution", 50, 2);
		Bureaucrat b("Manu", 1);
		try {
			std::cout << f << std::endl;
			std::cout << b << std::endl;
			b.signForm(f);
			std::cout << f << std::endl;
			b.signForm(f);
		}
		catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}