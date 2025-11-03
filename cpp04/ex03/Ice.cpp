#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor called." << std::endl;
}

Ice::Ice(const Ice &other) : AMateria("ice")
{
    std::cout << "Ice Copy constructor called." << std::endl;
    *this = other;
}

Ice &Ice::operator=(const Ice &other)
{
    std::cout << "Ice assignment operator called." << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice Destructor called." << std::endl;
}

AMateria *Ice::clone() const
{
    return (new Ice());
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}