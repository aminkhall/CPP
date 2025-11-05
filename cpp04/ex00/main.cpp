#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    Animal *meta = new Animal();
    Animal *j = new Dog();
    Animal *i = new Cat();
    WrongAnimal *wr = new WrongAnimal();
    WrongAnimal *wrcat = new WrongCat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    std::cout << wrcat->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();
    wrcat->makeSound();
    wr->makeSound();
    delete i;
    delete j;
    delete meta;
    delete wr;
    delete wrcat;
    return 0;
}