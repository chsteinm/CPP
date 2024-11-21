#include "easyFind.hpp"

int main() {
	std::vector<int> numbers;
	numbers.push_back(3);
	numbers.push_back(1);
	numbers.push_back(5);
	numbers.push_back(2);
	numbers.push_back(8);
	numbers.push_back(-12);
	numbers.push_back(0);
	int	n;
	std::cout << "Enter a number : " << std::endl << "> ";
	while (!(std::cin >> n)) {
		if (std::cin.eof())
			return 0;
		std::cout << "Error, please tape only a number" << std::endl << "> ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << std::endl;
    std::vector<int>::iterator it = ::easyFind(numbers, n);
	if (it == numbers.end())
		std::cout << "No occurence found";
	else
		std::cout << "Occurence found on index " << std::distance(numbers.begin(), it);
	std::cout << std::endl;
    return 0;
}