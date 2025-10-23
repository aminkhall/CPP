#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->hit = 100;
    this->energy = 50;
    this->damage = 20;
    this->gate = false;
    std::cout << "ScavTrap Default constructor called." << std::endl;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
    this->hit = 100;
    this->energy = 50;
    this->damage = 20;
    this->gate = false;
    std::cout << "ScavTrap: " << name << " constructor called." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap: " << other.name << " Copy constructor called." << std::endl;
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap: " << other.name << " Copy assignment operator called." << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->hit = other.hit;
        this->energy = other.energy;
        this->damage = other.damage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap: " << name << " Destructor called." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (energy <= 0 || hit <= 0)
    {
        std::cout << "ScavTrap: " << name << " Can't attack 0 point left." << std::endl;
        return;
    }
    std::cout << "ScavTrap: " << name << " attacks " << target << ", causing " << damage << " points of damage!"
              << std::endl;
    energy--;
}

void ScavTrap::guardGate()
{
    if (energy <= 0 || hit <= 0)
    {
        std::cout << "ScavTrap: " << name << " Can't enter Gate Keeper mode 0 point left." << std::endl;
        return;
    }
    if (false == gate)
    {
        gate = true;
        std::cout << "ScavTrap: " << name << " has entered Gate Keeper mode 🔒. No one shall pass!" << std::endl;
    }
    else
        std::cout << "ScavTrap: " << name << " is already in Gate Keeper mode 🔒!" << std::endl;
}