#include "FragTrap.hpp"

int main()
{
    FragTrap F1("Hamid");
    ClapTrap C1;
    FragTrap F2(F1);
    FragTrap F3;
    F3 = F2;
    ScavTrap S1("FOO");
    ScavTrap S2("MIMI");
    S1 = S2;
    S1.attack("FOO");
    F1.attack("FOO");
    return 0;
}