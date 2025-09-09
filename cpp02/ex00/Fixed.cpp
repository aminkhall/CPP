#include "Fixed.hpp"

const int FIXED::fractional = 8;

FIXED::FIXED() : fix_point(0){
    std::cout << "Default constructor called" << std::endl;
}

FIXED::FIXED(const FIXED& other){
    std::cout << "Copy constructor called" << std::endl;
    fix_point = other.getRawBits();
}

FIXED& FIXED::operator=(const FIXED& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    fix_point = other.getRawBits();
    return *this;
}

FIXED::~FIXED(){
    std::cout << "Destructor called" << std::endl;
}

int FIXED::getRawBits(void) const{
    std::cout << "getRawBits member function called" << std::endl;
    return fix_point;
}

void FIXED::setRawBits(int const raw){
    fix_point = raw;
}