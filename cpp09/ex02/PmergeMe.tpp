#include "PmergeMe.hpp"

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
	while (std::distance(it, numbers.end()) >= jump * 2) {
		if (*(it + jump - 1) > *(it + (jump * 2) - 1))
			swapAllNumbersInPairs(it, jump);
		it += jump * 2;
	}
}

template <typename Container>
void	movePairsInPend(Container& main, Container& pend, int pairLevel) {
//void	movePairsInPend(Container& main, Container& pend, int pairLevel, int mSize) {
	int jump = pow(2, pairLevel);
	// typename Container::iterator it = main.begin();
	// for (int i = 2; i <= mSize / jump; i += 2) {
	// 	pend.insert(pend.end(), main.begin() + jump * i, main.begin() + jump * i + jump);
	// }
	typename Container::iterator it = main.begin() + jump * 2;
	while (std::distance(it, main.end()) >= jump) {
		pend.insert(pend.end(), it, it + jump);
		it = main.erase(it, it + jump);
		if (std::distance(it, main.end()) < jump)
			break;
		it += jump;
	}

	std::cout << "\n-- end of movePairs level " << pairLevel << " :\n"; 
	affContainer(pend);
	affContainer(main);
}

template <typename Container>
void	insertPairs(Container& main, Container& pend, int pairLevel, int nSize) {
	int jump = pow(2, pairLevel);
	typename Container::iterator pendIt = pend.begin() + jump - 1;
	
}

template <typename Container>
void	PmergeMe::mergeInsertionSort(Container& numbers) {
	int nSize = numbers.size();
	int pairLevel = -1;
	while (++pairLevel == 0 || nSize / pairLevel >= pow(2, pairLevel)) {
		swapPairs(numbers, pairLevel);
		std::cout << "end of swapPairs in Level  " << pairLevel << " :\n";
		affContainer(numbers);
	}
	Container pend;
	while (--pairLevel >= 0) {
		movePairsInPend(numbers, pend, pairLevel);
		insertPairs(numbers, pend, pairLevel, nSize);
	}
}