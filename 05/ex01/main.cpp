#include <iostream>
#include "Bureaucrat.hpp"


void print_err(std::exception &e)
{
	std::cout << "\n****************************************\n";
	std::cout << "\t" << e.what();
	std::cout << "****************************************\n\n";
};

int main()
{
	std::cout << GREEN 
	<< "-------------------------------------------------------\n\n" << WHITE;



	// abdellah can't signed data, beSigned will be throw an error !!
	try {
		Bureaucrat a("abdellah", 22);
		std::cout << a;
		Form f("data", 21, 15); 
		try {
			// Error !! the grade of a isn't higher then 21! 
			f.beSigned(a);
		} catch(std::exception &e)
		{
			print_err(e);
		}
		try {
			// Error!! f isn't signed!
			a.signForm(f);
		}
		catch(std::exception &e)
		{
			print_err(e);
		}
		
		try
		{
			// Error the grade is too low
			Form("data", 152, 150);
		}
		catch(std::exception& e)
		{
			print_err(e);
		}

		try
		{
			// teh grade is too hiegh
			Form("data", 0, 0);
		}
		catch(std::exception& e)
		{
			print_err(e);
		}
		// this will throw an error
		Bureaucrat d("abdellah", 0);
	}
	catch (std::exception &e)
	{
		print_err(e);
	}
	std::cout << RED 
	<< "\n-------------------------------------------------------\n" << WHITE;
	return 0;
}