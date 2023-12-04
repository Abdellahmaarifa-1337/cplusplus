#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << GREEN 
	<< "-------------------------------------------------------\n\n" << WHITE;
	try {
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete rrf;
	}catch(std::exception &e)
	{
		std::cout << "\t" << e.what();
	}
	std::cout << GREEN 
	<< "-------------------------------------------------------\n\n" << WHITE;
	try {
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("shrubbery creation", "Tender");
		delete rrf;
	}catch(std::exception &e)
	{
		std::cout << "\t" << e.what();
	}
	std::cout << GREEN 
	<< "-------------------------------------------------------\n\n" << WHITE;
	try {
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Ok");
		delete rrf;
	}catch(std::exception &e)
	{
		std::cout << "\t" << e.what();
	}
	std::cout << GREEN 
	<< "-------------------------------------------------------\n\n" << WHITE;
	try {
		Intern someRandomIntern;
		Form* rrf;
		rrf = someRandomIntern.makeForm("random stuff", "Ok");
		delete rrf;
	}catch(std::exception &e)
	{
		std::cout << "\t" << e.what();
	}
	std::cout << RED 
	<< "\n-------------------------------------------------------\n" << WHITE;
	return 0;
}