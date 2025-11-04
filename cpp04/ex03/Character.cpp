#include "Character.hpp"

Character::Character() : name("default")
{
    std::cout << "Character default constructor called." << std::endl;
}

Character::Character(std::string const &name) : name(name), inventory()
{
    std::cout << "Character " << name << " constructor called." << std::endl;
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
    {
        this->name = other.name;
        for (int i = 0; i < 4; ++i)
        {
            if (this->inventory[i])
                delete this->inventory[i];
        }
        for (int i = 0; i < 4; ++i)
        {
            if (other.inventory[i])
                this->inventory[i] = other.inventory[i]->clone();
            else
                this->inventory[i] = other.inventory[i];
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; ++i)
    {
        if (this->inventory[i])
            delete this->inventory[i];
    }
    std::cout << "Character Destructor called." << std::endl;
}

std::string const &Character::getName() const
{
    return name;
}

void Character::equip(AMateria *m)
{
    if (!m)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (this->inventory[i] == m)
        {
            std::cout << "Materia already equipped!" << std::endl;
            return ;
        }
    }
    for (int i = 0; i < 4; ++i)
    {
        if (this->inventory[i] == NULL)
        {
            this->inventory[i] = m;
            std::cout << getName() << " equipped with materia " << m->getType() << std::endl;
            return;
        }
    }
    std::cout << "The inventory is full!" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx < 4 && !this->inventory[idx])
        std::cout << "No materia to unequip!" << std::endl;
    else if (idx >= 0 && idx < 4 && this->inventory[idx])
    {
        std::cout << getName() << " unequipped materia " << this->inventory[idx]->getType() << std::endl;
        this->inventory[idx] = NULL;
    }
    else 
        std::cout << "Invalid inventory index!" << std::endl;
}

void Character::use(int idx, ICharacter &target)
{
    if ((idx >= 0 && idx < 4) && this->inventory[idx])
        this->inventory[idx]->use(target);
    else if (idx >= 0 && idx < 4 && !this->inventory[idx])
        std::cout << "Empty inventory index!" << std::endl;
    else
        std::cout << "Invalid inventory index!" << std::endl;
}