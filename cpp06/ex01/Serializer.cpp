#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Serializer &Serializer::operator=(const Serializer &other)
{
    (void)other;
    std::cout << "Copy assignment operator called" << std::endl;
    return *this;
}

Serializer::~Serializer()
{
    std::cout << "Destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data *ptr)
{
    std::cout << "serialize called" << std::endl;
    return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    std::cout << "deserialize called" << std::endl;
    return reinterpret_cast<Data*>(raw);
}