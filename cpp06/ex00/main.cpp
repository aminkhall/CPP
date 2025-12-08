#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (2 != ac)
    {
        std::cout << "Invalid arg" << std::endl;
        return 1;
    }
    std::string str = av[1];
    ScalarConverter::convert(str);
    return 0;
}