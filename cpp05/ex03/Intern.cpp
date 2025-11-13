#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern default constructor called." << std::endl;
}

Intern::Intern(const Intern &other)
{
    std::cout << "Intern Copy constructor called." << std::endl;
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    std::cout << "Intern Copy assignment operator called." << std::endl;
    return *this;
}

Intern::~Intern()
{
    std::cout << "Intern Destructor called." << std::endl;
}

AForm *Intern::makeForm(std::string formName, std::string targetName)
{
    std::string arrayForm[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    for (; i < 3; ++i)
    {
        if (arrayForm[i] == formName)
            break;
    }
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << formName << std::endl;
        return (new ShrubberyCreationForm(targetName));
    case 1:
        std::cout << "Intern creates " << formName << std::endl;
        return (new RobotomyRequestForm(targetName));
    case 2:
        std::cout << "Intern creates " << formName << std::endl;
        return (new PresidentialPardonForm(targetName));
    default:
        std::cerr << "Form doesn’t exist" << std::endl;
        return NULL;
    }
}