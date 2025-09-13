#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
    std::cout << "Default constructor called" << std::endl;
};

ClapTrap::ClapTrap(const std::string& name){
    std::cout << name << " constructor called" << std::endl;
    this->name = name;
    this->hit = 10;
    this->energy = 10;
    this->damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other){
    std::cout << other.name << 
        " Copy constructor called" << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    std::cout << other.name <<
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
    std::cout << name <<
        " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (energy <= 0 || hit <= 0)
        return ;
    std::cout << "ClapTrap " << name << " attacks " <<
        target << ", causing " << damage << " points of damage!"
        << std::endl;
    energy--;
}

void ClapTrap::takeDamage(unsigned int amount){
    if (hit <= 0)
        return ;
    std::cout << name << " takes " << amount <<
        " points of damage!" << std::endl;
    if ((int)amount > hit)
        hit = 0;
    else
        hit -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
    if (hit <= 0 || energy <= 0)
        return ;
    hit += amount;
    energy--;
    std::cout << name << " is repaired by " << amount
          << " points! Energy left: " << energy << std::endl;

}