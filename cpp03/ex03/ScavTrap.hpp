#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
public:
    ScavTrap();                                 // default con
    ScavTrap(const std::string &name);          // con init name
    ScavTrap(const ScavTrap &other);            // copy con
    ScavTrap &operator=(const ScavTrap &other); // copy assign con
    ~ScavTrap();                                // dest
    void attack(const std::string &target);
    void guardGate();
};

#endif