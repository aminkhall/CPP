#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    int i = (rand() % 10);

    if (i > 8)
        i -= 2;
    i /= 3;
    switch (i)
    {
    case 0:
        return (new A());
    case 1:
        return (new B());
    case 2:
        return (new C());
    default:
        std::cout << "NULL" << std::endl;
        return (NULL);
    }
}

void identify(Base* p){

    if (dynamic_cast<A*>(p))
        std::cout << "Base*: It is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Base*: It is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Base*: It is C" << std::endl;
    else
        std::cerr << "Unknown Type" << std::endl;
}

void identify(Base& p){
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Base&: It is A" << std::endl;
        return;
    }
    catch(const std::exception& e){}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Base&: It is B" << std::endl;
        return;
    }
    catch(const std::exception& e){}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Base&: It is C" << std::endl;
        return;
    }
    catch(const std::exception& e){}
    std::cerr << "Unknown Type" << std::endl;
}

int main()
{
    srand(time(0));
    Base *test = generate();
    if (test){
        identify(test);
        identify(*test);
        delete test;
    }
    return (0);
}