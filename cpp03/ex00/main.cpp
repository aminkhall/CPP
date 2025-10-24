#include "ClapTrap.hpp"

int main()
{
    ClapTrap ct1;

    ClapTrap ct2("Clappy");

    ClapTrap ct3 = ct2;

    ct2.attack("Target1");

    ct2.takeDamage(5);

    ct2.beRepaired(3);

    ct1 = ct2;

    ct1.attack("Target2");

    ct1.takeDamage(20);

    ct1.beRepaired(5);

    return 0;
}