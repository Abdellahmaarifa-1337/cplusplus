#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"



void print_err(const std::exception& e)
{
	std::cout << "\n*****************************************************************\n";
	std::cout << "\t" << e.what();
	std::cout << "\n*****************************************************************\n\n";
};

void shrubbery_test()
{
	ShrubberyCreationForm data("home");
	try
	{
		try 
		{
			// data can't be signed not enaugh grade
			Bureaucrat abd("abdellah", 146);
			data.beSigned(abd);
		}
		catch(const std::exception& e)
		{
			print_err(e);
		}
		
		try 
		{
			// data can be signed but can't execute!
			Bureaucrat abd("abdellah", 138);
			data.beSigned(abd);
			data.execute(abd);
		}
		catch(const std::exception& e)
		{
			print_err(e);
		}

		// this will work just fine!
		Bureaucrat abd("abdellah", 130);
		abd.executeForm(data);
		// Error!! abd can not execute teh form!
		Bureaucrat bde("abdellah", 180);
		bde.executeForm(data);
	}
	catch(const std::exception& e)
	{
		print_err(e);
	}
}


void robotomy_test()
{
	RobotomyRequestForm data("home");
	try
	{
		try 
		{
			// data can't be signed not enaugh grade
			Bureaucrat abd("abdellah", 73);
			data.beSigned(abd);
		}
		catch(const std::exception& e)
		{
			print_err(e);
		}
		
		try 
		{
			// data can be signed but can't execute!
			Bureaucrat abd("abdellah", 71);
			data.beSigned(abd);
			data.execute(abd);
		}
		catch(const std::exception& e)
		{
			print_err(e);
		}

		// this will work just fine!
		Bureaucrat abd("abdellah", 40);
		abd.executeForm(data);
		// Error!! abd can not execute teh form!
		Bureaucrat bde("abdellah", 50);
		bde.executeForm(data);
	}
	catch(const std::exception& e)
	{
		print_err(e);
	}
}

void presidential_test()
{
	PresidentialPardonForm data("home");
	try
	{
		try 
		{
			// data can't be signed not enaugh grade
			Bureaucrat abd("abdellah", 26);
			data.beSigned(abd);
		}
		catch(const std::exception& e)
		{
			print_err(e);
		}
		
		try 
		{
			// data can be signed but can't execute!
			Bureaucrat abd("abdellah", 6);
			data.beSigned(abd);
			data.execute(abd);
		}
		catch(const std::exception& e)
		{
			print_err(e);
		}

		// this will work just fine!
		Bureaucrat abd("abdellah", 2);
		abd.executeForm(data);
		// Error!! abd can not execute teh form!
		Bureaucrat bde("abdellah", 7);
		bde.executeForm(data);
	}
	catch(const std::exception& e)
	{
		print_err(e);
	}
}

int main()
{
	std::cout << GREEN 
	<< "-------------------------------------------------------\n\n" << WHITE;
	shrubbery_test();
	robotomy_test();
	presidential_test();
	std::cout << RED 
	<< "\n-------------------------------------------------------\n" << WHITE;
	return 0;
}