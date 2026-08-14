#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
    {
        _database = other._database;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.empty() || date.size() != 10)
        return false;
    if (date[4] != '-' || date[7] != '-')
        return false;
    for (size_t i = 0; i < date.size(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (!std::isdigit(date[i]))
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int mounth = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (year < 2009 || mounth > 12 || mounth < 1 || day > 31 || day < 1)
        return false;

    int dayInMounth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));

    if (isLeap)
        dayInMounth[2] = 29;
    if (day > dayInMounth[mounth])
        return false;

    return true;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, float &outValue)
{
    if (valueStr.empty())
        return false;

    std::stringstream ss(valueStr);
    float val;
    ss >> val;
    if (ss.fail() || !ss.eof())
    {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }

    if (val < 0)
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    else if (val > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    outValue = val;
    return true;
}

void BitcoinExchange::loadDatabase(const std::string &dbFileName)
{
    std::ifstream file(dbFileName.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("could not open file.");
    }
    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;
        std::string dateStr = line.substr(0, commaPos);
        std::string rateStr = line.substr(commaPos + 1);

        float rate;
        std::stringstream ss(rateStr);
        ss >> rate;

        _database[dateStr] = rate;
    }
}

void BitcoinExchange::processInput(const std::string &inputFile)
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
    {
        throw std::runtime_error("could not open file.");
    }
    std::string line;
    int i = 0;
    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        if (!i && line == "date | value")
        {
            ++i;
            continue;
        }
        ++i;
        size_t delimPos = line.find(" | ");
        if (delimPos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string dateStr = line.substr(0, delimPos);
        std::string valueStr = line.substr(delimPos + 3);
        if (!isValidDate(dateStr))
        {
            std::cerr << "Error: bad input => " << dateStr << std::endl;
            continue;
        }

        float value;
        if (!isValidValue(valueStr, value))
        {
            continue;
        }

        std::map<std::string, float>::const_iterator it = _database.lower_bound(dateStr);
        if (it == _database.end() || it->first != dateStr)
        {
            if (it == _database.begin())
            {
                std::cerr << "Error: bad input => " << dateStr << std::endl;
                continue;
            }
            --it;
        }

        std::cout << dateStr << " => " << value << " = " << value * it->second << std::endl;
    }
}