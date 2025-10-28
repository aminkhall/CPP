#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "😺 Cat Default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : Animal()
{
    std::cout << "😺 Cat Copy constructor called." << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "😺 Cat Copy assignment operator called." << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Cat::~Cat()
{
    std::cout << "😺 Cat Destructor called." << std::endl;
}

void Cat::makeSound()
{
    std::cout << "😺 Cat makes Meow Meow." << std::endl;
}