#include "AAnimal.hpp"

AAnimal::AAnimal() : type("None")
{
    std::cout << "AAnimal constructor called." << std::endl;
}

AAnimal::AAnimal(const AAnimal &other)
{
    std::cout << "AAnimal Copy constructor called." << std::endl;
    *this = other;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
    std::cout << "AAnimal Copy assignment operator called." << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal Destructor called." << std::endl;
}

void AAnimal::makeSound()
{
    std::cout << "No sound!" << std::endl;
}

const std::string &AAnimal::getType() const
{
    return type;
}