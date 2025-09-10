#include "Fixed.hpp"

const int FIXED::fractional = 8;

FIXED::FIXED() : fix_point(0){
    std::cout << "Default constructor called" << std::endl;
}

FIXED::FIXED(const int num){
    std::cout << "Int constructor called" << std::endl;
    this->fix_point = num << this->fractional;
}

FIXED::FIXED(const float num){
    std::cout << "Float constructor called" << std::endl;
    this->fix_point = roundf(num * (1 << this->fractional));
}

FIXED::FIXED(const FIXED& other){
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

FIXED& FIXED::operator=(const FIXED& other){
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        fix_point = other.getRawBits();
    return *this;
}

FIXED::~FIXED(){
    std::cout << "Destructor called" << std::endl;
}

float FIXED::toFloat(void) const{
    return ((float)this->fix_point / (1 << this->fractional));
}

int FIXED::toInt(void) const{
    return (this->fix_point >> this->fractional);
}

int FIXED::getRawBits(void) const{
    return fix_point;
}

void FIXED::setRawBits(int const raw){
    fix_point = raw;
}

std::ostream& operator<<(std::ostream& o, const FIXED& other){
    o << other.toFloat();
    return o;
}