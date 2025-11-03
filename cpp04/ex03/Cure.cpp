#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called." << std::endl;
}

Cure::Cure(const Cure &other) : AMateria("cure")
{
    std::cout << "Cure Copy constructor called." << std::endl;
    *this = other;
}

Cure &Cure::operator=(const Cure &other)
{
    std::cout << "Cure assignment operator called." << std::endl;
    if (this != &other)
        this->type = other.type;
    return *this;
}

Cure::~Cure()
{
    std::cout << "Cure Destructor called." << std::endl;
}

AMateria *Cure::clone() const
{
    return (new Cure());
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target.getName() << " ’s wounds *" << std::endl;
}
