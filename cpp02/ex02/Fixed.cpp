#include "Fixed.hpp"

const int FIXED::fractional = 8;

FIXED::FIXED() : fix_point(0){}

FIXED::FIXED(const int num){
    this->fix_point = num << this->fractional;
}

FIXED::FIXED(const float num){
    this->fix_point = roundf(num * (1 << this->fractional));
}

FIXED::FIXED(const FIXED& other){
    *this = other;
}

FIXED& FIXED::operator=(const FIXED& other){
    if (this != &other)
        fix_point = other.getRawBits();
    return *this;
}

FIXED::~FIXED(){}

bool FIXED::operator>(const FIXED& other){
    return this->fix_point > other.fix_point;
}

bool FIXED::operator<(const FIXED& other){
    return this->fix_point < other.fix_point;
}

bool FIXED::operator==(const FIXED& other){
    return this->fix_point == other.fix_point;
}

bool FIXED::operator<=(const FIXED& other){
    return this->fix_point <= other.fix_point;
}

bool FIXED::operator>=(const FIXED& other){
    return this->fix_point >= other.fix_point;
}

bool FIXED::operator!=(const FIXED& other){
    return this->fix_point != other.fix_point;
}

FIXED FIXED::operator+(const FIXED& other){
    this->fix_point += other.toFloat();
    return *this;
}

FIXED FIXED::operator-(const FIXED& other){
    this->fix_point -= other.toFloat();
    return *this;
}

FIXED FIXED::operator*(const FIXED& other){
    this->fix_point *= other.toFloat();
    return *this;
}

FIXED FIXED::operator/(const FIXED& other){
    this->fix_point /= other.toFloat();
    return *this;
}

FIXED FIXED::operator++(){
    ++this->fix_point;
    return *this;
}

FIXED FIXED::operator++(int){
    FIXED tmp = *this;
    this->fix_point++;
    return tmp;
}

FIXED FIXED::operator--(){
    --this->fix_point;
    return *this;
}

FIXED FIXED::operator--(int){
    FIXED tmp = *this;
    this->fix_point++;
    return tmp;
}

FIXED& FIXED::min(FIXED &first, FIXED &second){
    if (first.fix_point <= second.fix_point)
        return first;
    else
        return second;
}

const FIXED& FIXED::min(const FIXED &first, const FIXED &second){
    if (first.fix_point <= second.fix_point)
        return first;
    else
        return second;
}

FIXED& FIXED::max(FIXED &first, FIXED &second){
    if (first.fix_point <= second.fix_point)
        return first;
    else
        return second;
}

const FIXED& FIXED::max(const FIXED &first, const FIXED &second){
    if (first.fix_point >= second.fix_point)
        return first;
    else
        return second;
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