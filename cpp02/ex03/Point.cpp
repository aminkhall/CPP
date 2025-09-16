#include "Point.hpp"

Point::Point() : x(0), y(0){}

Point::Point(const float _x, const float _y) : x(_x), y(_y){}

Point::Point(const Point& other) : x(other.get_x()), y(other.get_y()){}


Point& Point::operator=(const Point& other){
    (void) other;
    return (*this);
}

Point::~Point(){}

const FIXED Point::get_x() const{
    return x;
}

const FIXED Point::get_y() const{
    return y;
}

std::ostream& operator<<(std::ostream& o, const Point& other){
    o << "(" << other.get_x() << ", " << other.get_y() << ")";
    return o;
}