#include "Span.hpp"

Span::Span() : N(0) {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->_span = other._span;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
    if (_span.size() >= N)
        throw FullSpanException();
    _span.push_back(number);
}

long long Span::shortestSpan() const
{
    if (_span.size() < 2)
        throw NotEnoughNumbers();
    std::vector<int> sorted = _span;
    std::sort(sorted.begin(), sorted.end());

    long long minSpan = (long long)sorted[1] - (long long)sorted[0];
    for (size_t i = 1; i < sorted.size() - 1; i++)
    {
        long long diff = (long long)sorted[i + 1] - (long long)sorted[i];
        if (diff < minSpan)
            minSpan = diff;
    }
    return minSpan;
}

long long Span::longestSpan() const
{
    if (_span.size() < 2)
        throw NotEnoughNumbers();

    std::vector<int>::const_iterator maxIt = std::max_element(_span.begin(), _span.end());
    std::vector<int>::const_iterator minIt = std::min_element(_span.begin(), _span.end());
    return ((long long)*maxIt - (long long)*minIt);
}

const char *Span::NotEnoughNumbers::what() const throw()
{
    return "Not enough numbers";
}

const char *Span::FullSpanException::what() const throw()
{
    return "Span is full";
}