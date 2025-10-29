#include "Dog.hpp"

Dog::Dog()
{
    this->brain = new Brain();
    this->type = "Dog";
    std::cout << "🐶 Dog Default constructor called." << std::endl;
}

Dog::Dog(const Dog &other) : Animal()
{
    std::cout << "🐶 Dog Copy constructor called." << std::endl;
    *this = other;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout << "🐶 Dog Copy assignment operator called." << std::endl;
    if (this != &other)
    {
        delete this->brain;
        this->brain = new Brain(*other.brain);
        this->type = other.type;
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "🐶 Dog Destructor called." << std::endl;
    delete brain;
}

void Dog::makeSound()
{
    std::cout << "🐶 Dog makes Woof." << std::endl;
}

void Dog::setIdea(const std::string &idea, const int index)
{
    this->brain->setIdea(idea, index);
}

std::string Dog::getIdea(const int index) const
{
    return (this->brain->getIdea(index));
}