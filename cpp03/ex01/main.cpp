#include "ScavTrap.hpp"

int main() {
    // Default constructor
    ClapTrap ct1;
    ScavTrap scavTrap1;
    
    
    // Parameterized constructor
    ClapTrap ct2("Clappy");

    ScavTrap scavTrap2("hello");
    
    // Copy constructor
    ClapTrap ct3 = ct2;

    ScavTrap scavTrap3 = scavTrap2;

    // Attack
    ct2.attack("Target1");

    scavTrap2.attack("Target2");


    // Take damage
    ct2.takeDamage(5);
    ct2.attack("Target1");


    // Repair
    ct2.beRepaired(3);

    // Copy assignment operator
    ct1 = ct2;

    // Show ct1 attacking after assignment
    ct1.attack("Target2");

    // Damage ct1 until zero hit points
    ct1.takeDamage(20);

    // Try repairing ct1 when hit points are 0 (should do nothing)
    ct1.beRepaired(5);
    scavTrap2.guardGate();

    return 0;
}