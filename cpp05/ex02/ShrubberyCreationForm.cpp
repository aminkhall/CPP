#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default target")
{
    std::cout << "ShrubberyCreationForm default constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other)
{
    std::cout << "ShrubberyCreationForm Copy constructor called." << std::endl;
    *this = other;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "ShrubberyCreationForm Copy assignment operator called." << std::endl;
    if (this != &other)
        this->target = other.target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "ShrubberyCreationForm Destructor called." << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    try
    {
        if (getSign() == "No")
            throw NotSign();
        if (executor.getGrade() < getGradeToSign())
            throw GradeTooLowException();
        std::ofstream outFile(target + "_shrubbery");
        if (!outFile)
            throw Error();

        outFile << "   *" << std::endl;
        outFile << "  ***" << std::endl;
        outFile << " *****" << std::endl;
        outFile << "*******" << std::endl;
        outFile << "   |" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

const char *ShrubberyCreationForm::Error::what() const throw()
{
    return "Error: Could not open file";
}