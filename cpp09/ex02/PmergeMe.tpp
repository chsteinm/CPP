#include "PmergeMe.hpp"

template <typename Container>
void	affContainer(Container& numbers) {
	typename Container::iterator it = numbers.begin();
	while (it != numbers.end())
		std::cout << *it++ << " ";
	std::cout << std::endl;
}

template <typename Container>
void	printSortedOrNot(Container &numbers) {
	typename Container::iterator it = numbers.begin();
	int prev = *it;
	while (++it != numbers.end() && numbers.size() > 1) {
		if (prev > *it) {
			std::cout << "\nThe container is not sorted :(" << std::endl;
			return;
		}
		prev = *it;
	}
	std::cout << "The container is properly sorted. =D\n" << std::endl;
}

template <typename IT>
void	swapAllNumbersInPairs(IT it, int jump) {
	IT end = it + jump;

	for (; it != end; ++it)
		std::iter_swap(it, it + jump);
}

template <typename Container>
void	swapPairs(Container& numbers, int pairLevel, std::size_t& cmp) {
	int jump = pow(2, pairLevel);
	typename Container::iterator it = numbers.begin();
	while (std::distance(it, numbers.end()) >= jump * 2) {
		if (*(it + jump - 1) > *(it + (jump * 2) - 1))
			swapAllNumbersInPairs(it, jump);
		cmp++;
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
std::vector<std::pair<int, int> > mirroring(Container& main, Container& pend, int jump) {
    std::vector<std::pair<int, int> > result;
	if (main.size() / jump < 3)
		return result;
    typename Container::iterator itEnd = main.begin() + 2 * jump;
    typename Container::iterator itPend = pend.begin();
	
    for (unsigned int i = jump; i <= std::min((unsigned int)main.size() - jump, (unsigned int)pend.size() - jump); i += jump) {
        result.push_back(std::make_pair(*(itEnd + i - jump), *(itPend + i - jump)));
		if (DEBUG)
			std::cout << "(" << *(itEnd + i - jump) << ", " << *(itPend + i - jump) << ")";
	}
	if (DEBUG)
		std::cout << std::endl;
    return result;
}

template <typename Container>
void	binaryInsert(Container& main, typename Container::iterator& it, int jump, int end, std::size_t& cmp) {
	int start = 0;
	int middle;
	int endCpy = end;
	int cmpN = 0;
	while (start < end) {
		middle = start + (end - start) / 2;
		if (*(it + jump - 1) < main[middle * jump + jump - 1]) {
                end = middle;
            }
		else {
			start = middle + 1;
		}
		cmpN++;
		cmp++;
	}
	if (DEBUG) {
		std::cout << "\nNumber of cmp for insering " << *(it + jump - 1) << ": " << cmpN << " in the first :"
		<< endCpy << " elements of:\n"; 
		affContainer(main);
	}
	main.insert(main.begin() + start * jump, it, it + jump);
}

template <typename Container>
void	insertPairs(Container& main, Container& pend, int pairLevel, std::size_t& cmp) {
	int jump = pow(2, pairLevel);
	std::vector<std::pair<int, int> > mirror = mirroring(main, pend, jump);
	typename Container::iterator it;
	typename Container::iterator itEnd;
	int end;
	int currJacobsthal;
	int jacobsthalDiff;
	int jacobsthalIndex = 1;
	int prevJacobsthal = genJacobsthalNumber(jacobsthalIndex);
	while (++jacobsthalIndex) {
		currJacobsthal = genJacobsthalNumber(jacobsthalIndex);
		jacobsthalDiff = currJacobsthal - prevJacobsthal;
		if (currJacobsthal > static_cast<int>(mirror.size() + 1))
			break;
		for (int i = 0; i < jacobsthalDiff; i++) {
			itEnd = std::find(main.begin(), main.end(), mirror[currJacobsthal - 2 - i].first);
			end = std::distance(main.begin(), itEnd) / jump;
			it = std::find(pend.begin(), pend.end(), mirror[currJacobsthal - 2 - i].second);
			binaryInsert(main, it, jump, end, cmp);
			pend.erase(it, it + jump);
		}
		prevJacobsthal = currJacobsthal;
	}
	for (int i = prevJacobsthal + 1; i < static_cast<int>(mirror.size()); i++) {
		itEnd = std::find(main.begin(), main.end(), mirror[i - 2].first);
		end = std::distance(main.begin(), itEnd) / jump;
		it = std::find(pend.begin(), pend.end(), mirror[i - 2].second);
		binaryInsert(main, it, jump, end, cmp);
		pend.erase(it, it + jump);
	}
	it = pend.begin();
	while (it != pend.end()) {
        end = main.size() / jump;
		binaryInsert(main, it, jump, end, cmp);
		it = pend.erase(it, it + jump);
    }
}

template <typename Container>
void	PmergeMe::mergeInsertionSort(Container& numbers) {
	int nSize = numbers.size();
	int pairLevel = -1;
	while (++pairLevel == 0|| nSize / 2 >= pow(2, pairLevel)) {
		swapPairs(numbers, pairLevel, this->_cmp);
		if (DEBUG) {
			std::cout << "\nend of swapPairs in Level " << pairLevel << " :\n";
			affContainer(numbers);
		}
	}
	Container pend;
	while (--pairLevel >= 0) {
		movePairsInPend(numbers, pend, pairLevel);
		insertPairs(numbers, pend, pairLevel, this->_cmp);
		if (DEBUG) {
			std::cout << "\nend of insertPairs in Level " << pairLevel << " :\n";
			affContainer(numbers);
		}
	}
}