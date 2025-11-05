#include "AMateria.hpp"

AMateria::AMateria()
{
    std::cout << "AMateria default constructor called." << std::endl;
}

AMateria::AMateria(std::string const &type) : type(type)
{
    std::cout << "AMateria constructor called." << std::endl;
}

AMateria::AMateria(const AMateria &other)
{
    std::cout << "AMateria Copy constructor called." << std::endl;
    *this = other;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    std::cout << "AMateria assignment operator called." << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria Destructor called." << std::endl;
}

std::string const &AMateria::getType() const 
{
    return type;
}