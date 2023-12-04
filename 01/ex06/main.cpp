#include <iostream>
#include "Harl.hpp"

using std::cout;
using std::string;

int get_index(char *s)
{
	string msg[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	for(i = 0; i < 4; i++)
		if (msg[i] == s)
			break;
	return i;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		cout << "Argment error!\n";
		return 1;
	}

	Harl obj;
	int i = get_index(av[1]);
	switch (i)
	{
		case 0:
			cout << "[ DEBUG ]\n";
			obj.complain("DEBUG");
			cout << "\n";
		case 1:
			cout << "[ INFO ]\n";
			obj.complain("INFO");
			cout << "\n";
		case 2:
			cout << "[ WARNING ]\n";
			obj.complain("WARNING");
			cout << "\n";
		case 3:
			cout << "[ ERROR ]\n";
			obj.complain("ERROR");
			break;
		default:
			cout << "[ Probably complaining about insignificant problems ]\n";
	}
	return (0);
}