#include <iostream>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <cctype>

double convert_to_double(char *n)
{

    double dd;
    try
    {  
		size_t ptr;
		//check if the input is single char!
		if (strlen(n) == 1 && !isdigit(n[0]))
		{
			dd = static_cast<double> (n[0]);
			return dd; 
		}
		dd = std::stod(n, &ptr);
		if (n[ptr] && strcmp(n + ptr, "f"))
		{
			throw std::exception();
		}
    }
    catch(std::exception &)
    {
        std::cout << "char: impossible"  << "\n";
        std::cout << "int: impossible"  << "\n";
		std::cout << "float: impossible"  << "\n";
        std::cout << "double: impossible"  << "\n";
        exit(0);
    }
    return dd;

};

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error! uncorrect arguments!\n";
        return 1;
    }
    double dd = convert_to_double(av[1]);
    if (std::isnan(dd) || std::isinf(dd))
    {
        std::cout << "char: impossible"  << "\n";
        std::cout << "int: impossible"  << "\n";
    }
    else
    {
		// convert to char
        char c = static_cast<char>(dd);
        if (dd > 127 || dd < -128)
            std::cout << "char: impossible\n";
        else if (isprint(c))
            std::cout << "char: " << c << "\n";
        else
            std::cout << "char: Non displayable\n";

		// convert to int
        if (dd > 2147483647 || dd < -2147483648)
            std::cout << "int: impossible\n";
        else
            std::cout << "int: " << static_cast<int>(dd) << "\n";
    }
	// convert to float
    if (dd - static_cast<int>(dd) == 0)
        std::cout << std::setprecision(1) << std::fixed;
    std::cout << "float: " << static_cast<float>(dd) << "f\n";
	// convert to double
    std::cout << "double: " <<  dd << "\n";
    return 0;
}