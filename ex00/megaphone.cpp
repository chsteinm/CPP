#include <iostream>
#include <string>
#include <cctype>

int main(int argc, char **argv)
{
	std::string str_;

	if (argc == 1)
		str_ = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		str_ = "";
		while (--argc)
			str_ = str_ + *(++argv);
		for (char& c : str_)
			c = std::toupper(c);
	}
	std::cout << str_ << std::endl;
	return 0;
}