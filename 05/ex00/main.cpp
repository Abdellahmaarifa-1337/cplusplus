#include <iostream>
#include "Bureaucrat.hpp"


void high_grade_test()
{
	try
	{
		Bureaucrat b("two", 0);
	}
	catch(const std::exception& e)
	{
		std::cout << "\t" << RED << e.what() << WHITE;
	}
};

void low_grade_test()
{
	try
	{
		Bureaucrat d("three", 151);
	}
	catch(const std::exception& e)
	{
		std::cout << "\t" << RED << e.what() << WHITE;
	}
};

void increment_grade_test()
{
	try 
	{
		Bureaucrat b("abd", 1);
		b.increment();
	}
	catch (std::exception &e)
	{
		std::cout << "\t" << RED << e.what() << WHITE;
	}
}

void decrement_grade_test()
{
	try 
	{
		Bureaucrat b("abd", 150);
		b.decrement();
	}
	catch (std::exception &e)
	{
		std::cout << "\t" << RED << e.what() << WHITE;
	}
}

int main()
{
	std::cout << GREEN 
	<< "\n-------------------------------------------------------\n" << WHITE;
	try {
		// This is okaay!
		Bureaucrat a("one", 150);
		std::cout << a;
		// This will throw a high grade error!
		high_grade_test();
		// This will throw a Low grade error!
		low_grade_test();
		// This will throw a high grade error!
		increment_grade_test();
		// This will throw a Low grade error!
		decrement_grade_test();
	}
	catch (std::exception &e)
	{
		std::cout << "\t" << RED << e.what() << WHITE;
	}
	std::cout << RED 
	<< "\n-------------------------------------------------------\n" << WHITE;
	return 0;
}