#include "iter.hpp"

void increment(int &n)
{
    n *= 10;
}

void print(int x)
{
    std::cout << x << std::endl;
}
int main()
{
    int array[4] = {1, 2, 3, 4};
    ::iter(array, 4, increment);
    ::iter(array, 4, print);
}