#include <iostream>
#include "Rpn.hpp"

int main(int ac, char **av)
{
	Rpn rpn;

	if (ac != 2)
	{
		std::cout << "Error: number of parameters is wormg!\n";
		return 1;
	}
	std::string expr(av[1]);
	std::string opr("+*-/");
	std::string::size_type i = 0;
	try {
		while (i < expr.size())
		{
			if (expr[i] >= '0' && expr[i] <= '9')
			{
				rpn.pushOperand(expr[i] - 48);		
			}
			else if (opr.find(expr[i]) != std::string::npos)
			{
				rpn.preformOperation(expr[i]);
			}
			else if (expr[i] != ' ')
			{
				std::cout << "unvalid characheter in expr!\n";
				return 1;
			}
			i++;
		}
		std::cout << rpn.getResault() << "\n";
	}
	catch(std::exception &) {
		std::cout << "Error!\n";
	}
	return (0);
}