#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	// ScalarConverter nop;
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
	}
	else
		std::cout << "Please enter a parameter like \"./convert 42\"" << std::endl;
	return 0;
}