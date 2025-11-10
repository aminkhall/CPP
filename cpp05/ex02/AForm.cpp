#include "AForm.hpp"

AForm::AForm() : name("default"), gradeToSign(150), gradeToExecute(150), sign(false)
{
    std::cout << "AForm: " << name << " constructor called." << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    else if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    else
    {
        this->sign = false;
        std::cout << "AForm: " << name << " constructor called." << std::endl;
    }
}

AForm::AForm(const AForm &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "AForm: " << name << " Copy constructor called." << std::endl;
    *this = other;
}

AForm &AForm::operator=(const AForm &other)
{
    (void)other;
    std::cout << "AForm: " << name << " Copy assignment operator called." << std::endl;
    return *this;
}

AForm::~AForm()
{
    std::cout << "AForm: " << name << " Destructor called." << std::endl;
}

std::string AForm::getName() const
{
    return name;
}

std::string AForm::getSign() const
{
    if (sign == true)
        return "Yes";
    else
        return "No";
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
    {
        std::cout << bureaucrat.getName() << " couldn’t sign " << name << " because " << " Grade Too Low " << std::endl;
        throw AForm::GradeTooLowException();
    }
    else if (sign == false)
    {
        std::cout << bureaucrat.getName() << " signed " << name << std::endl;
        sign = true;
    }
    else
        std::cout << bureaucrat.getName() << " already signed " << name << std::endl;
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

std::ostream &operator<<(std::ostream &o, const AForm &other)
{
    o << "AForm: " << other.getName() << "\ngrade sign: " << other.getGradeToSign() << "\ngrade exec: " << other.getGradeToExecute()
      << "\nSigned: " << other.getSign();
    return o;
}