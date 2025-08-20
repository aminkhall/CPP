#include "HumanB.hpp"

HumanB::HumanB(const std::string& name){
    this->name = name;
}

HumanB::HumanB(const std::string& name, const Weapon wp){
    this->name = name;
    this->weapon = wp;
}

void HumanB::setWeapon(Weapon wp){
    weapon = wp;
}

void HumanB::attack(){
    std::cout << name << " attacks with their " << weapon.getType() << std::endl; 
}