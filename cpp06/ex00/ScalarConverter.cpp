#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "Default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "Destructor called" << std::endl;
}

static bool isPrint(const std::string &literal)
{
	int len = literal.length();
	for (int i = 0; i < len; ++i)
	{
		if (!std::isprint(literal[i]))
			return (false);
	}
	return (true);
}

static bool isValid(const std::string &literal)
{
	if (literal == "+inf" || literal == "-inf" || literal == "-inff" || literal == "+inff" || literal == "nan" || literal == "nanf" || literal == "inf" || literal == "inff")
		return (true);
	int len = literal.length();
	int i = 0;
	int countPoint = 0;
	if ('-' == literal[i] || '+' == literal[i])
		++i;
	for (; i < len; i++)
	{
		if (!isdigit(literal[i]))
		{
			if ('f' == literal[i] && literal[i + 1])
				return false;
			else if (len != 1 && !i && '.' == literal[i] && literal[i + 1] && !isdigit(literal[i + 1]))
				return (false);
			else if ('.' == literal[i])
				++countPoint;
			else if (len != 1 && 'f' == literal[i] && !countPoint)
				return (false);
			else if (len != 1 && ('f' != literal[i] && '.' != literal[i]))
				return (false);
		}
		if (countPoint > 1)
			return false;
	}
	return (true);
}

static bool checkInput(const std::string &literal)
{
	if (literal.empty() || !isPrint(literal) || !isValid(literal))
		return (false);
	return (true);
}

static type checkType(const std::string &literal)
{
	int len = literal.length();

	if (len == 1 && !isdigit(literal[0]))
		return (CHAR);
	else if (literal.find(".", 0) == std::string::npos)
		return (INT);
	else if (literal.find("f", 0) != std::string::npos)
		return (FLOAT);
	else if (literal.find(".", 0) != std::string::npos)
		return (DOUBLE);
	return (UNKNOWN);
}

static void printImpossible(int flag)
{
	if (flag)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
	}
}

static void printChar(const char c, int flag)
{
	if (!flag)
		std::cout << "char: impossible" << std::endl;
	else if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

static void convertChar(const std::string &literal)
{
	char c = static_cast<char>(literal[0]);
	int flag = 1;
	if (c < 0 || c > 127)
		flag = 0;
	printChar(c, flag);
	int i = static_cast<int>(c);
	std::cout << "int: " << i << std::endl;
	float f = static_cast<float>(c);
	std::cout << "float: " << f << ".0f" << std::endl;
	double d = static_cast<double>(c);
	std::cout << "double: " << d << ".0" << std::endl;
}

static void convertInt(const std::string &literal)
{
	double tmp = atof(literal.c_str());
	if (tmp < INT_MIN || tmp > INT_MAX)
		printImpossible(1);
	else
	{
		int i = static_cast<int>(tmp);
		int flag = 1;
		if (i < 0 || i > 127)
			flag = 0;
		printChar(i, flag);
		std::cout << "int: " << i << std::endl;
		float f = static_cast<float>(i);
		std::cout << "float: " << f << ".0f" << std::endl;
		double d = static_cast<double>(i);
		std::cout << "double: " << d << ".0" << std::endl;
	}
}

static void convertFloat(const std::string &literal)
{
	double tmp = atof(literal.c_str());
	float f = static_cast<float>(tmp);
	if (std::isnan(f) || std::isinf(f))
		printImpossible(1);
	else
	{
		int flag = 1;
		if (tmp < 0 || tmp > 127)
			flag = 0;
		printChar(tmp, flag);
		if (tmp < INT_MIN || tmp > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else
		{
			int i = static_cast<int>(tmp);
			std::cout << "int: " << i << std::endl;
		}
		size_t pos = literal.find('.');
		int digits = 0;
		if (pos != std::string::npos)
			digits = literal.size() - pos - 1;
		else
			digits = 1;
		std::cout << "float: " << std::fixed << std::setprecision(digits) << f << "f" << std::endl;
		double d = static_cast<double>(tmp);
		std::cout << "double: " << std::fixed << std::setprecision(digits) << d << std::endl;
	}
}

static void convertDouble(const std::string &literal)
{
	double tmp = atof(literal.c_str());
	if (std::isnan(tmp) || std::isinf(tmp))
		printImpossible(1);
	else
	{
		int flag = 1;
		if (tmp < 0 || tmp > 127)
			flag = 0;
		printChar(tmp, flag);
		if (tmp < INT_MIN || tmp > INT_MAX)
			std::cout << "int: impossible" << std::endl;
		else
		{
			int i = static_cast<int>(tmp);
			std::cout << "int: " << i << std::endl;
		}
		size_t pos = literal.find('.');
		int digits = 0;
		if (pos != std::string::npos)
			digits = literal.size() - pos - 1;
		else
			digits = 1;
		float f = static_cast<float>(tmp);
		std::cout << "float: " << std::fixed << std::setprecision(digits) << f << "f" << std::endl;
		double d = static_cast<double>(tmp);
		std::cout << "double: " << std::fixed << std::setprecision(digits) << d << std::endl;
	}
}

static void nanInfLiteral(const std::string &literal)
{
	if (literal == "-inf" || literal == "-inff")
	{
		printImpossible(0);
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (literal == "+inf" || literal == "+inff")
	{
		printImpossible(0);
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (literal == "inf" || literal == "inff")
	{
		printImpossible(0);
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
	}
	else if (literal == "nan" || literal == "nanf")
	{
		printImpossible(0);
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &literal)
{
	if (!checkInput(literal))
		printImpossible(1);
	else
	{
		if (literal.find("nan") != std::string::npos || literal.find("inf") != std::string::npos)
		{
			nanInfLiteral(literal);
			return;
		}
		type t = checkType(literal);
		switch (t)
		{
		case CHAR:
			convertChar(literal);
			break;
		case INT:
			convertInt(literal);
			break;
		case FLOAT:
			convertFloat(literal);
			break;
		case DOUBLE:
			convertDouble(literal);
			break;
		default:
			break;
		}
	}
}