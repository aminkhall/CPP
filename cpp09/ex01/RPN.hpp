#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <stdexcept>

class RPN
{
private:
    std::stack<long long> _stack;
    bool isOperator(char) const;
    void performOperation(char);

public:
    RPN();
    RPN(const RPN &);
    RPN &operator=(const RPN &);
    ~RPN();

    void calculate(const std::string &);
};

#endif