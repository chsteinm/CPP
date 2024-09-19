#include "ScalarConverter.hpp"

int	main(int argc, char **argv) {
	// ScalarConverter nop;
	if (argc == 2) {
		ScalarConverter::convert(argv[1]);
	}
	return 0;
}