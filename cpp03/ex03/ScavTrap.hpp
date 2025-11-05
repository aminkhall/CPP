#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
    bool gate;

public:
    ScavTrap();                                 
    ScavTrap(const std::string &name);          
    ScavTrap(const ScavTrap &other);            
    ScavTrap &operator=(const ScavTrap &other); 
    ~ScavTrap();                               
    void attack(const std::string &target);
    void guardGate();
};

#endif