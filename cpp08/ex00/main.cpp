#include "easyfind.hpp"

int main()
{
    try
    {
        std::vector<int> numbers;
        numbers.push_back(2);
        numbers.push_back(5);
        numbers.push_back(7);
        numbers.push_back(0);
        numbers.push_back(9);
        numbers.push_back(4);
        numbers.push_back(1);
        numbers.push_back(3);
        numbers.push_back(8);
        numbers.push_back(45);
        numbers.push_back(12);

        ::easyfind(numbers, 100);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}