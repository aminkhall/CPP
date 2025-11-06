#include "Bureaucrat.hpp"

int main()
{
    // Bureaucrat a;
    // Bureaucrat n("nn", 150);
    // n.increment();
    // std::cout << a << std::endl;
    {
        std::cout << "\033[33m" << std::endl << "Test ex01" << "\033[0m" << std::endl;

	std::cout << "\033[33m" << std::endl << "Test too high and too low creation" << "\033[0m" << std::endl;
	try
	{
		Bureaucrat Sleeper1("Bernd", 1500);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat Sleeper2("Olaf", -10);
	}
	catch(const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "\033[33m" << std::endl << "Test increasing" << "\033[0m" << std::endl;
	Bureaucrat bob("Bob", 2);
	std::cout << bob<< std::endl;
	try
	{
		bob.increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob<< std::endl;
	
	try
	{
	bob.increment();
	}
	catch(const std::exception& e)
	{
	std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << bob<< std::endl;



	std::cout << "\033[33m" << std::endl << "Test decreasing" << "\033[0m" << std::endl;
	Bureaucrat tim("Tim", 149);
	std::cout << tim<< std::endl;
	try
	{
		tim.decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim<< std::endl;
	
	try
	{
	tim.decrement();
	}
	catch(const std::exception& e)
	{
	std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << tim<< std::endl;
    }
}