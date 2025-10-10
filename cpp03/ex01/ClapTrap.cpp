#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("default"), hit(10), energy(10), damage(0) {
    std::cout << "ClapTrap Default constructor called" << std::endl;
};

ClapTrap::ClapTrap(const std::string& name) : name(name), hit(10), energy(10), damage(0) {
    std::cout << "ClapTrap: " << name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other){
    std::cout << "ClapTrap: " << other.name << 
        " Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    std::cout << "ClapTrap: " << other.name <<
        " Copy assignment operator called" << std::endl; 
    if (this != &other){
        this->name = other.name;
        this->hit = other.hit;
        this->energy = other.energy;
        this->damage = other.damage;
    }
    return *this;   
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap: " << name <<
        " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (energy <= 0 || hit <= 0){
        std::cout << "ClapTrap: " << name << " Can't attack 0 point left" << std::endl;
        return ;
    }
    std::cout << "ClapTrap: " << name << " attacks " <<
        target << ", causing " << damage << " points of damage!"
        << std::endl;
    energy--;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (hit <= 0){
        std::cout << "ClapTrap: " << name << " Can't take damage 0 point left" << std::endl;
        return ;
    }
    std::cout << name << " takes " << amount <<
        " points of damage!" << std::endl;
    if ((int)amount > hit)
        hit = 0;
    else
        hit -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (hit <= 0 || energy <= 0){
        std::cout << "ClapTrap: " << name << " Can't berepaired 0 point left" << std::endl;
        return ;
    }
    hit += amount;
    energy--;
    std::cout << name << " is repaired by " << amount
          << " points! Energy left: " << energy << std::endl;
}