#include "iter.hpp"

void	ft_putstr(std::string str) {
	std::cout << str + " ";
}

int	main() {
	int		array[] = {1, 2, 3};
	char	str[] = "Hello World !";
	std::string	strings[3] = {"H3ll0", "W0rld", "!"};

	::iter(array, 3, f<int>);
	for (size_t i = 0; i < 3; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;

	::iter(str, 5, f<char>);
	std::cout << str << std::endl;

	::iter(strings, 3, ft_putstr);
    std::cout << std::endl;
	return 0;
}