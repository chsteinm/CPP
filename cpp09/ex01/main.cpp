#include "RPN.hpp"

int err(std::string error) {
    std::cerr << error << std::endl;
    return 1;
}

int main(int ac, char **av) {
    if (ac != 2)
        return err("Error: please enter 1 arg");
    RPN rpn;
    return rpn.calculator(av[1]);
}