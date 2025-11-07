#include "Bureaucrat.hpp"

int main()
{
    
    try
    {
        Bureaucrat b("hamid", -1);
        Bureaucrat c;
        c = b;
        b.decrement();
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b;
        b.increment();
        b.decrement();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}