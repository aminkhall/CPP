#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
    Character c("salim");
    AMateria *m = new Ice();
    AMateria *m2 = new Cure();
    AMateria *m1 = new Ice();
    AMateria *m3 = new Cure();


    Character c1("samir");
    c.equip(m2);
    c.equip(m);
    c1.equip(m1);
    c1.equip(m3);

    c1.use(1, c);
    c.use(3, c);
    c.use(6, c);
    c1.use(0, c);

    c1.unequip(0);
    c.equip(m1);
    // delete m1;

}