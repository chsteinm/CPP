#include "PmergeMe.hpp"

// template <typename Container>
// void	swapPairs(Container& numbers) {
// 	typename Container::iterator it = numbers.begin();
// 	while (std::distance(it, numbers.end()) > 1) {
// 		if (*it > *(it + 1))
// 			std::iter_swap(it, (it + 1));
// 		it += 2;
// 	}
// }

template <typename Container>
void	affContainer(Container& numbers) {
	typename Container::iterator it = numbers.begin();
	while (it != numbers.end())
		std::cout << *it++ << " ";
	std::cout << std::endl;
}


template <typename IT>
void	swapAllNumbersInPairs(IT it, int jump) {
	IT end = it + jump;
	// std::cout << "IT = " << *it << " and jump = " << jump << '\n';

	for (; it != end; ++it)
		// std::swap(*it, *(it + jump));
		std::iter_swap(it, it + jump);
}

template <typename Container>
void	swapPairs(Container& numbers, int pairLevel) {
	int jump = pow(2, pairLevel);
	// std::cout << "pair and jump = " << pairLevel << " " << jump << '\n';
	typename Container::iterator it = numbers.begin();
	while (std::distance(it, numbers.end()) > jump + 1) {
		if (*(it + jump - 1) > *(it + (jump * 2) - 1))
			swapAllNumbersInPairs(it, jump);
		it += jump * 2;
	}
}

template <typename Container>
void	PmergeMe::mergeInsertionSort(Container& numbers) {
	int nSize = numbers.size();
	int pairLevel = -1;
	while (++pairLevel == 0 || nSize / pairLevel >= pow(2, pairLevel)) {
		// if (pairLevel)
			// std::cout << "numbers.size() / pairLevel = " << nSize / pairLevel << '\n';
		swapPairs(numbers, pairLevel);
		// affContainer(numbers);
	}
	
}