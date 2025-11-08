#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    
    try
    {
        // Form f("f", 0, 150);
        Bureaucrat b("ss", 18);

        Form f("dsa", 15, 15);
        // b.signForm(f);
        // Bureaucrat b("hamid", -1);
        // Bureaucrat c;
        // c = b;
        // b.decrement();
        std::cout << f << std::endl;
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
    return 0;
}