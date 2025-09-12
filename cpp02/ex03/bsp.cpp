#include "Point.hpp"

static float area(const Point a, const Point b, const Point c){
    float ax = a.get_x().toFloat();
    float ay = a.get_y().toFloat();
    float bx = b.get_x().toFloat();
    float by = b.get_y().toFloat();
    float cx = c.get_x().toFloat();
    float cy = c.get_y().toFloat();

    float _area =(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) / 2;
    if (_area < 0)
        _area = -_area;

    return _area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point){
    bool res = false;

    float A  = area(a, b, c);
    float A1 = area(point, b, c);
    float A2 = area(a, point, c);
    float A3 = area(a, b, point);

    if (A1 == 0 || A2 == 0 || A3 == 0)
        res = false;
    else if (A == A1 + A2 + A3)
        res = true;
    return (res);
}