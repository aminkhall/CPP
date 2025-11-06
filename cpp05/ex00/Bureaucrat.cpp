#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
    std::cout << "Bureaucrat default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
        this->grade = grade;
    std::cout << "Bureaucrat: " << name << " constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Bureaucrat: " << name << " Copy constructor called." << std::endl;
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat: " << name << " assignment operator called." << std::endl;
    if (this != &other)
        this->grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat: " << name << " Destructor called." << std::endl;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

std::string Bureaucrat::getName() const
{
    return name;
}

void Bureaucrat::increment()
{
    if (grade == 150)
        throw GradeTooLowException();
    else
        ++grade;
}

void Bureaucrat::decrement()
{
    if (grade == 1)
        throw GradeTooLowException();
    else
        --grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade Too High";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade Too Low";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &other)
{
    o << other.getName() << ", bureaucrat grade " << other.getGrade();
    return o;
}