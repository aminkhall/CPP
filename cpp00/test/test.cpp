#include <iostream>

class Hello{
    public:
        int id;
        Hello()
        {
            id = 0;
            std::cout << "Called Hereeee" << std::endl;
            std::cout << id << std::endl;
        }
        Hello(int i)
        {
            id = i;
            std::cout << id << std::endl;
        }
};

int main()
{
    Hello hello;
    Hello(5);
}