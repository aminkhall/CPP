#include "ClapTrap.hpp"

int main()
{
    // Default constructor
    ClapTrap ct1;

    // Parameterized constructor
    ClapTrap ct2("Clappy");

    // Copy constructor
    ClapTrap ct3 = ct2;

    // Attack
    ct2.attack("Target1");

    // Take damage
    ct2.takeDamage(5);

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

    return 0;
}