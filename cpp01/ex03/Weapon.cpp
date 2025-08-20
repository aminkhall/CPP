#include "Weapon.hpp"

Weapon::Weapon(){}

Weapon::Weapon(std::string type) : type(type){}

const std::string& Weapon::getType() const{
    return (type);
}

void Weapon::setType(const std::string& str){
    type = str;
}