#include "Character.hpp"

Character::Character() : name("default")
{
    std::cout << "Character default constructor called." << std::endl;
}

Character::Character(const Character &other)
{
    std::cout << "Character Copy constructor called." << std::endl;
    *this = other;
}

Character &Character::operator=(const Character &other)
{
    std::cout << "Character assignment operator called." << std::endl;
    if (this != &other)
        this->name = other.name;
    return *this;
}

Character::~Character()
{
    std::cout << "Character Destructor called." << std::endl;
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
}

void Character::unequip(int idx)
{
}

void Character::use(int idx, ICharacter &target)
{
    
}