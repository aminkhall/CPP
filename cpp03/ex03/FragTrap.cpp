#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    this->hit = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << "FragTrap Default constructor called." << std::endl;
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
    this->hit = 100;
    this->energy = 100;
    this->damage = 30;
    std::cout << "FragTrap: " << name << " constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap: " << other.name << " Copy constructor called." << std::endl;
    *this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap: " << other.name << " Copy assignment operator called." << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit = other.hit;
        this->energy = other.energy;
        this->damage = other.damage;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap: " << name << " Destructor called." << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap: " << name << " 🙌 High fives, everyone! Great job, team!" << std::endl;
}