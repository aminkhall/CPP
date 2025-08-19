#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include "HumanA.hpp"
#include "HumanB.hpp"

class Weapon{
private:
    std::string type;
public:
    std::string getType();
    std::string setType(std::string str);
};

#endif