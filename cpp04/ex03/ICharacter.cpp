#include "ICharacter.hpp"

ICharacter::ICharacter()
{
    std::cout << "ICharacter default constructor called." << std::endl;
}

ICharacter::ICharacter(const ICharacter &other)
{
    std::cout << "ICharacter Copy constructor called." << std::endl;
    *this = other;
}

ICharacter &ICharacter::operator=(const ICharacter &other)
{
    (void) other;
    std::cout << "ICharacter assignment operator called." << std::endl;
    return *this;
}

ICharacter::~ICharacter()
{
    std::cout << "ICharacter Destructor called." << std::endl;
}