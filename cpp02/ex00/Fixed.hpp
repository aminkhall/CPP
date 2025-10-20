#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class FIXED
{
private:
    int fix_point;
    static const int fractional;

public:
    FIXED();
    FIXED(const FIXED &other);
    FIXED &operator=(const FIXED &other);
    ~FIXED();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

#endif