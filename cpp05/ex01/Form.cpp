#include "Form.hpp"

Form::Form() : name("default"), gradeToSign(150), gradeToExecute(150), sign(false)
{
    std::cout << "Form: " << name << " constructor called." << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    else if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    else
    {
        this->sign = false;
        std::cout << "Form: " << name << " constructor called." << std::endl;
    }
}

Form::Form(const Form &other) : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
    std::cout << "Form: " << name << " Copy constructor called." << std::endl;
    *this = other;
}

Form &Form::operator=(const Form &other)
{
    (void)other;
    std::cout << "Form: " << name << " Copy assignment operator called." << std::endl;
    return *this;
}

Form::~Form()
{
    std::cout << "Form: " << name << " Destructor called." << std::endl;
}

std::string Form::getName() const
{
    return name;
}

std::string Form::getSign() const
{
    if (sign == true)
        return "Yes";
    else
        return "No";
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
    {
        std::cout << bureaucrat.getName() << " couldn’t sign " << name << " because " << " Grade Too Low " << std::endl;
        throw Form::GradeTooLowException();
    }
    else if (sign == false)
    {
        std::cout << bureaucrat.getName() << " signed " << name << std::endl;
        sign = true;
    }
    else
        std::cout << bureaucrat.getName() << " already signed " << name << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

std::ostream &operator<<(std::ostream &o, const Form &other)
{
    o << "Form: " << other.getName() << "\ngrade sign: " << other.getGradeToSign() << "\ngrade exec: " << other.getGradeToExecute()
      << "\nSigned: " << other.getSign();
    return o;
}