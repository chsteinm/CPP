#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv) {
	std::string str;

	if (argc == 1)
		str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else {
		str = "";
		while (--argc)
			str = str + *(++argv);
		for (std::string::size_type i = 0; i < str.size(); i++)
			str[i] = std::toupper(str[i]);
	}
	std::cout << str << std::endl;
	return 0;
}