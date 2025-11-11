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
        Bureaucrat b("ss", 5);

        // b.signForm(f);
        // Bureaucrat b("hamid", -1);
        // Bureaucrat c;
        // c = b;
        // b.decrement();
        AForm *form = new RobotomyRequestForm("ab");
        // RobotomyRequestForm q("ab");
        // form = &q;
        // b.signForm(*form);
        std::cout << "Before execute" << std::endl;
        form->execute(b);
        std::cout << "After execute (should not reach here if exception)" << std::endl;
        b.executeForm(*form);
        delete form;
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