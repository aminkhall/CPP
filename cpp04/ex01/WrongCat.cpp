#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    this->type = "WrongCat";
    std::cout << "WrongCat Default constructor called." << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{
    std::cout << "WrongCat Copy constructor called." << std::endl;
    *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "WrongCat Copy assignment operator called." << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called." << std::endl;
}

void WrongCat::makeSound()
{
    std::cout << "WrongCat makes Meow Meow." << std::endl;
}