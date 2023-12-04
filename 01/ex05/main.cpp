#include <iostream>
#include "Harl.hpp"

using std::cout;
using std::string;

int main(void)
{
	Harl obj;
	
	std::cout << " [ INFO ] " << "\n";
	obj.complain("INFO");

	std::cout << "\n [ DEBUG ] " << "\n";
	obj.complain("DEBUG");

	std::cout << "\n [ ERROR ] " << "\n";
	obj.complain("ERROR");

	std::cout << "\n [ WARNING ] " << "\n";
	obj.complain("WARNING");

	return (0);
}