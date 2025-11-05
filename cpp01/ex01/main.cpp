#include "Zombie.hpp"

int main()
{
    Zombie *Horde = zombieHorde(5, "Horde");
    for (int i = 0; i < 5; ++i)
        Horde[i].announce();
    delete[] Horde;
    return (0);
}