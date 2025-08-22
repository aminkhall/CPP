#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), weapon(nullptr){}

void HumanB::setWeapon(Weapon& wp){
    weapon = &wp;
}

void HumanB::attack(){
    if (weapon)
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " attacks without weapon " << std::endl;
}