#include "Serializer.hpp"

int main()
{
    {
        Data a;
        a.x = 42;
        a.str = "1337";
        uintptr_t i = Serializer::serialize(&a);
        
        std::cout << i << std::endl;
        std::cout << Serializer::deserialize(i) << std::endl;
    }
    return 0;
}