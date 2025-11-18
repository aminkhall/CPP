#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>


#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    const int gradeToSign;
    const int gradeToExecute;
    bool sign;
    
public:
    Form();
    Form(const Form &other);
    Form &operator=(const Form &other);
    ~Form();

    Form(std::string name, int gradeTosign, int gradeToExecute);
    std::string getName() const;
    std::string getSign() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat &bureaucrat);

    class GradeTooHighException : public std::exception
    {
    public:
        const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
    public:
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, const Form &other);

#endif