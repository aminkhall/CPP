#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>


#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    const int gradeToSign;
    const int gradeToExecute;
    bool sign;
    
public:
    AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    ~AForm();

    AForm(std::string name, int gradeTosign, int gradeToExecute);
    std::string getName() const;
    std::string getSign() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
    void beSigned(Bureaucrat &bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream &operator<<(std::ostream &o, const AForm &other);

#endif