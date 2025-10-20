#include "Fixed.hpp"

int main(void)
{
    FIXED a;
    FIXED const b(FIXED(5.05f) * FIXED(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << FIXED::max(a, b) << std::endl;
    return 0;
}