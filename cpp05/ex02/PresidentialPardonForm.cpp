#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default target")
{
    std::cout << "PresidentialPardonForm default constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
    std::cout << "PresidentialPardonForm Copy constructor called." << std::endl;
    *this = other;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << "PresidentialPardonForm Copy assignment operator called." << std::endl;
    if (this != &other)
        this->target = other.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << "PresidentialPardonForm Destructor called." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    try
    {
        if (getSign() == "No")
            throw NotSign();
        if (executor.getGrade() > getGradeToSign())
            throw GradeTooLowException();
        std::cout << target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}