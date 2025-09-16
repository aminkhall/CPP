#include "phonebook.hpp"

int check_space(std::string str){
    size_t i = 0;
    while (std::isspace(str[i]))
        ++i;
    if (i == str.size())
        return (0);
    return (1);
}

int is_valid(std::string str)
{
    int i;

    if (str.empty())
        return (std::cout << "Invalid input" << std::endl, 0);
    if (!check_space(str))
        return (std::cout << "Invalid input" << std::endl, 0);
    i = 0;
    while (str[i])
    {
        if (!isprint(str[i]))
            return (std::cout << "Invalid input" << std::endl, 0);
        ++i;
    }
    return (1);
}

int is_digit(std::string str)
{
    int i;

    if (str.empty())
        return (std::cout << "Invalid index " << std::endl, 0);
    i = 0;
    while (str[i])
    {
        if (!isdigit(str[i]))
            return (std::cout << "Invalid index (Enter a digit)" << std::endl, 0);
        ++i;
    }
    return (1);
}