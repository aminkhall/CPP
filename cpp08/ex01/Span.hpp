#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

class Span
{
private:
    unsigned int N;
    std::vector<int> _span;

public:
    Span();
    Span(unsigned int);
    Span(const Span &);
    Span &operator=(const Span &);
    ~Span();

    void addNumber(int);
    template <typename It>
    void addNumbers(It begin, It end);
    long long shortestSpan() const;
    long long longestSpan() const;

    class NotEnoughNumbers : public std::exception
    {
    public:
        const char *what() const throw();
    };

    class FullSpanException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};
#include "Span.tpp"

#endif