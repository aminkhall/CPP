#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point{
private:
    const FIXED x;
    const FIXED y;
public:
    Point();
    Point(const float _x, const float _y);
    Point(const Point& other);
    Point& operator=(const Point& other);
    ~Point();
    const FIXED get_x(void) const;
    const FIXED get_y(void) const;
};
std::ostream& operator<<(std::ostream& o, const Point& other);
bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif