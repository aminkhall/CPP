#include "IMateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
    std::cout << "IMateriaSource default constructor called." << std::endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &other)
{
    std::cout << "IMateriaSource Copy constructor called." << std::endl;
    *this = other;
}

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &other)
{
    (void) other;
    std::cout << "IMateriaSource assignment operator called." << std::endl;
    return *this;
}

IMateriaSource::~IMateriaSource()
{
    std::cout << "IMateriaSource Destructor called." << std::endl;
}