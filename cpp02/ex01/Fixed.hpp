#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class FIXED
{
private:
    int fix_point;
    static const int fractional;

public:
    FIXED();
    FIXED(const int num);
    FIXED(const float num);
    FIXED(const FIXED &other);
    FIXED &operator=(const FIXED &other);
    ~FIXED();
    int getRawBits(void) const;
    void setRawBits(int const raw);
    float toFloat(void) const;
    int toInt(void) const;
};
std::ostream &operator<<(std::ostream &o, const FIXED &other);

#endif