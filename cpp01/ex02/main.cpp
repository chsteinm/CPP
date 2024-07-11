#include <iostream>

int	main() {
	
	std::string		str = "HI THIS IS BRAIN";
	std::string*	stringPTR = &str;
	std::string&	stringREF = str;

	std::cout << std::endl;

	std::cout << "addr of str :         " << &str << std::endl;
	std::cout << "addr held by strPTR : " << stringPTR << std::endl;
	std::cout << "addr held by strREF : " << &stringREF << std::endl << std::endl;

	std::cout << "value of str :               " << str << std::endl;
	std::cout << "value pointed to by strPTR : " << *stringPTR << std::endl;
	std::cout << "value pointed to by strREF : " << stringREF << std::endl;

	return 0;
}