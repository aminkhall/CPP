#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    
    try
    {
        // AForm f("f", 0, 150);
        Bureaucrat b("ss", 18);

        // b.signForm(f);
        // Bureaucrat b("hamid", -1);
        // Bureaucrat c;
        // c = b;
        // b.decrement();
        AForm *form;
        ShrubberyCreationForm q("ab");
        form = &q;
        b.signForm(*form);
        form->execute(b);
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