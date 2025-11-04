#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : inventory()
{
    std::cout << "MateriaSource default constructor called." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    std::cout << "MateriaSource Copy constructor called." << std::endl;
    *this = other;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
    std::cout << "MateriaSource assignment operator called." << std::endl;
    if (this != &other)
    {
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
                this->inventory[i] = NULL;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; ++i)
    {
        if (this->inventory[i])
            delete this->inventory[i];
    }
    std::cout << "MateriaSource Destructor called." << std::endl;
}

void MateriaSource::learnMateria(AMateria *materia)
{
    if (!materia)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (materia && this->inventory[i] == NULL)
        {
            std::cout << "Learned materia " << materia->getType() << " at index " << i << std::endl;
            this->inventory[i] = materia;
            return;
        }
    }
    std::cout << "No empty materia slot available!" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; ++i)
    {
        if (this->inventory[i] && this->inventory[i]->getType() == type)
        {
            std::cout << "Materia " << this->inventory[i]->getType() << " was created successfully!" << std::endl;
            return this->inventory[i]->clone();
        }
    }
    std::cout << "No match of the type passed in the slot!" << std::endl;
    return NULL;
}