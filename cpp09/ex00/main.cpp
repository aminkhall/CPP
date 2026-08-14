#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Invalid input" << std::endl;
        return 1;
    }

    try
    {
        std::string inputFile = av[1];
        BitcoinExchange btc;
        btc.loadDatabase("data.csv");
        btc.processInput(inputFile);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}