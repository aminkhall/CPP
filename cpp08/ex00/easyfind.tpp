#include "easyfind.hpp"

template <typename T>
void easyfind(T &container, int second)
{
    typename T::iterator it = std::find(container.begin(), container.end(), second);
    if (it == container.end())
        throw NotFoundException();
    std::cout << "Found " << second << " at index: " << std::distance(container.begin(), it) << std::endl;
}
