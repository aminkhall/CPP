#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

bool RPN::isOperator(char c) const
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void RPN::performOperation(char op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error");
    long long second = _stack.top();
    _stack.pop();
    long long first = _stack.top();
    _stack.pop();
    long long result;
    switch (op)
    {
    case '+':
        result = first + second;
        break;
    case '-':
        result = first - second;
        break;
    case '*':
        result = first * second;
        break;
    case '/':
        if (second == 0)
            throw std::runtime_error("Error");
        result = first / second;
        break;
    default:
        throw std::runtime_error("Error");
        break;
    }

    _stack.push(result);
}

void RPN::calculate(const std::string &input)
{
    std::stringstream ss(input);
    std::string arg;

    while (ss >> arg)
    {
        if (arg.length() == 1 && std::isdigit(arg[0]))
            _stack.push(arg[0] - '0');
        else if (arg.length() == 1 && isOperator(arg[0]))
            performOperation(arg[0]);
        else
            throw std::runtime_error("Error");
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error");
    std::cout << _stack.top() << std::endl;
}