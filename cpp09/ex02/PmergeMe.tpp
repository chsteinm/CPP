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

	for (; it != end; ++it)
		std::iter_swap(it, it + jump);
}

template <typename Container>
void	swapPairs(Container& numbers, int pairLevel) {
	int jump = pow(2, pairLevel);
	typename Container::iterator it = numbers.begin();
	while (std::distance(it, numbers.end()) >= jump * 2) {
		if (*(it + jump - 1) > *(it + (jump * 2) - 1))
			swapAllNumbersInPairs(it, jump);
		it += jump * 2;
	}
}

template <typename Container>
void	movePairsInPend(Container& main, Container& pend, int pairLevel) {
	int jump = pow(2, pairLevel);
	typename Container::iterator it = main.begin() + jump * 2;
	while (std::distance(it, main.end()) >= jump) {
		pend.insert(pend.end(), it, it + jump);
		it = main.erase(it, it + jump);
		if (std::distance(it, main.end()) < jump)
			break;
		it += jump;
	}

	if (DEBUG) {
		std::cout << "\n-- end of movePairs level " << pairLevel << " :\n"; 
		affContainer(pend);
		affContainer(main);
	}
}

int genJacobsthalNumber(int n) { 
	return round((pow(2, n + 1) + pow(-1, n)) / 3);
}

template <typename Container>
void	insertPairs(Container& main, Container& pend, int pairLevel, int nSize) {
	(void)nSize;
	int jump = pow(2, pairLevel);
	// int jacobsthalDiff;
	// int currJacobsthal = genJacobsthalNumber(jacobsthalIndex);
	// int prevJacobsthal = genJacobsthalNumber(jacobsthalIndex - 1);
	int pSize = pend.size();
	int numberOfInsert = 0;
	typename Container::iterator it = pend.begin() + jump - 1;
	int jacobsthalIndex = 1;
	while (pSize / jump + 1 >= genJacobsthalNumber(++jacobsthalIndex)) {
		// jacobsthalDiff = currJacobsthal - prevJacobsthal;
		it += (genJacobsthalNumber(jacobsthalIndex) - numberOfInsert) * jump;
		while () {

		}
	}
	while (it != pend.end()) {
        int start = 0;
        int end = main.size() / jump;

        while (start < end) {
            int middle = start + (end - start) / 2;
            if (*(it + jump - 1) < main[middle * jump + jump - 1]) {
                end = middle;
            }
			else {
                start = middle + 1;
            }
        }

        main.insert(main.begin() + start * jump, it, it + jump);

        it = pend.erase(it, it + jump);
    }
}

template <typename Container>
void	PmergeMe::mergeInsertionSort(Container& numbers) {
	int nSize = numbers.size();
	int pairLevel = -1;
	while (++pairLevel == 0 || nSize / pairLevel >= pow(2, pairLevel)) {
		swapPairs(numbers, pairLevel);
		if (DEBUG) {
			std::cout << "\nend of swapPairs in Level " << pairLevel << " :\n";
			affContainer(numbers);
		}
	}
	Container pend;
	while (--pairLevel >= 0) {
		movePairsInPend(numbers, pend, pairLevel);
		insertPairs(numbers, pend, pairLevel, nSize);
		if (DEBUG) {
			std::cout << "\nend of insertPairs in Level " << pairLevel << " :\n";
			affContainer(numbers);
		}
	}
}