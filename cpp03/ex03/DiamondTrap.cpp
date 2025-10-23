#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
    this->hit = FragTrap::hit;
    this->energy = ScavTrap::energy;
    this->damage = FragTrap::damage;
    std::cout << "DiamondTrap Default constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name")
{
    this->hit = FragTrap::hit;
    this->energy = ScavTrap::energy;
    this->damage = FragTrap::damage;
    std::cout << "DiamondTrap: " << name << " constructor called." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other)
{
    std::cout << "DiamondTrap: " << other.name << " Copy constructor called." << std::endl;
    *this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
    std::cout << "DiamondTrap: " << other.name << " Copy assignment operator called." << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit = other.hit;
        this->energy = other.energy;
        this->damage = other.damage;
    }

    return (*this);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap: " << name << " Destructor called." << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}