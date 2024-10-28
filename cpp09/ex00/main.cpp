#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
    (void)av;
    std::ifstream   data("data.csv");
    if (ac != 2 || !data)
        return 1;
    BitcoinExchange btc;
    btc.parseData(data);
    return 0;
}