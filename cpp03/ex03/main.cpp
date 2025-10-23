#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap D1("FOO");
    D1.attack("MM");
    D1.takeDamage(80);
    D1.attack("MM");
    D1.guardGate();
    D1.guardGate();
    return 0;
}