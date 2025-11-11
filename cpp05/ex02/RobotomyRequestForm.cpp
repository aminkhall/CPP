#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default target")
{
    std::cout << "RobotomyRequestForm default constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    std::cout << "RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
    std::cout << "RobotomyRequestForm Copy constructor called." << std::endl;
    *this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << "RobotomyRequestForm Copy assignment operator called." << std::endl;
    if (this != &other)
        this->target = other.target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << "RobotomyRequestForm Destructor called." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    try
    {
        if (getSign() == "No")
            throw NotSign();
        if (executor.getGrade() < getGradeToSign())
            throw GradeTooLowException();
        srand(time(0));
        int x = rand() % 100 + 1;
        if (x % 2 == 0)
            std::cout << target << " has been robotomized successfully" << std::endl;
        else
            std::cout << target << " robotomy failed" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}