#include "Fixed.hpp"

int main( void ) {
    FIXED a;
    FIXED b( a );
    FIXED c;
    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0;
}