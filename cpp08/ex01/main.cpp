#include "Span.hpp"

int main()
{
    std::srand(std::time(NULL));

    Span span(11000);
    std::vector<int> randomNumbers;

    for (size_t i = 0; i < 11000; i++)
    {
        randomNumbers.push_back(std::rand());
    }

    try
    {
        // for (size_t i = 0; i < randomNumbers.size(); i++)
        // {
        //     span.addNumber(randomNumbers[i]);
        // }
        span.addNumbers(randomNumbers.begin(), randomNumbers.end());

        const Span span2(span);

        std::cout << span.shortestSpan() << std::endl;
        std::cout << span2.shortestSpan() << std::endl;
        std::cout << span.longestSpan() << std::endl;
        std::cout << span2.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}