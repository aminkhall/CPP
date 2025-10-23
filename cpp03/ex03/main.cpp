#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap D1("FOO");
    DiamondTrap D2("FOO2");
    D1.attack("MM");
    D1.takeDamage(80);
    D1.attack("MM");
    D1.guardGate();
    D1.guardGate();
    D1.whoAmI();
    D2.whoAmI();
    return 0;
}