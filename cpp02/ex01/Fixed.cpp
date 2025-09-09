#include "Fixed.hpp"

const int FIXED::fractional = 8;

FIXED::FIXED() : fix_point(0){
    std::cout << "Default constructor called" << std::endl;
}

FIXED::FIXED(const int num){
    std::cout << "Int constructor called" << std::endl;
}

FIXED::FIXED(const float num){
    std::cout << "Float constructor called" << std::endl;
}

FIXED::FIXED(const FIXED& other){
    std::cout << "Copy constructor called" << std::endl;
}

FIXED& FIXED::operator=(const FIXED& other){
    std::cout << "Copy assignment operator called" << std::endl;
}

FIXED::~FIXED(){
    std::cout << "Destructor called" << std::endl;
}

float FIXED::toFloat(void) const{

}

int FIXED::toInt(void) const{

}
