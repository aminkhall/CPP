#include "Cat.hpp"

Cat::Cat()
{
    this->brain = new Brain();
    this->type = "Cat";
    std::cout << "😺 Cat Default constructor called." << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal()
{
    std::cout << "😺 Cat Copy constructor called." << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "😺 Cat Copy assignment operator called." << std::endl;
    if (this != &other)
    {
        delete this->brain;
        this->brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "😺 Cat Destructor called." << std::endl;
    delete brain;
}

void Cat::makeSound()
{
    std::cout << "😺 Cat makes Meow Meow." << std::endl;
}

void Cat::setIdea(const std::string &idea, const int index)
{
    this->brain->setIdea(idea, index);
}

std::string Cat::getIdea(const int index) const
{
    return (this->brain->getIdea(index));
}