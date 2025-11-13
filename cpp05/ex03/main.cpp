#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{

    try
    {
        Intern i;
        AForm *f = i.makeForm("creation", "mmmm");
        delete f;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b;
        b.increment();
        b.decrement();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}