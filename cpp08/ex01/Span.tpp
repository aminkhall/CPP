#include "Span.hpp"

template <typename It>
void Span::addNumbers(It begin, It end)
{
    if (std::distance(begin, end) + _span.size() > N)
        throw FullSpanException();

    _span.insert(_span.end(), begin, end);
}