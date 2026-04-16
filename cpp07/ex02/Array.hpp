#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cmath>


template <typename T>
class Array
{
private:
    T *_elements;
    unsigned int _size;

public:
    Array();
    Array(unsigned int size);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
    class OutOfBoundsException : public std::exception{
        public:
            const char *what() const throw();
    };
};

#include "Array.tpp"

#endif