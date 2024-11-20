#include "BitcoinExchange.hpp"

int err(std::string error) {
    std::cerr << error << std::endl;
    return 1;
}

int main(int ac, char **av) {
    std::ifstream   data("data.csv");
    if (ac != 2 || !data)
        return err("Error: could not open file.");
    std::ifstream input(av[1]);
    if (!input)
        return err("Error: could not open file.");
    BitcoinExchange btc;
    btc.parseData(data);
    btc.getChange(input);
    return 0;
}