#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB{
private:
    Weapon weapon;
    std::string name;
public:
    HumanB(const std::string& name);
    HumanB(const std::string& name, const Weapon wp);
    void setWeapon(Weapon wp);
    void attack();
};

#endif