#include <iostream>
#include <cctype>

void    to_UpperCase(std::string str)
{
    int i;
    if (str.empty())
        return ;
    i = 0;
    while (str[i])
    {
        if (isalpha(str[i]))
        {
            str[i] = std::toupper(str[i]);
            std::cout << str[i];
        }
        else
            std::cout << str[i];
        ++i;
    }
}

int main(int ac, char **av)
{
    int i;
    if (ac < 2)
        return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 1);
    i = 1;
    while (av[i])
    {
        to_UpperCase(av[i]);
        ++i;
    }
    std::cout << std::endl;
    return (0);
}