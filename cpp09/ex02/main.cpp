#include "PmergeMe.hpp"

int main(int ac, char **av) {
    PmergeMe pmergeMe;
    try {
        pmergeMe.parse(ac, av);
    }
    catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 1;
    }
    try {
        pmergeMe.vecSort();
        pmergeMe.dequeSort();
    }
    catch (const std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
        return 2;
    }

    return 0;
}