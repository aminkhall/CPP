#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <map>
#include <cctype>
#include <stdexcept>

class BitcoinExchange
{
private:
    std::map<std::string, float> _database;

    bool isValidDate(const std::string &) const;
    bool isValidValue(const std::string &, float &);

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &);
    BitcoinExchange &operator=(const BitcoinExchange &);
    ~BitcoinExchange();

    void loadDatabase(const std::string &);
    void processInput(const std::string &);
};

#endif