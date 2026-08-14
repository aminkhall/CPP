#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void easyfind(T &container, int second);

class NotFoundException : public std::exception
{
public:
    const char *what() const throw()
    {
        return "not found.";
    }
};

#include "easyfind.tpp"

#endif