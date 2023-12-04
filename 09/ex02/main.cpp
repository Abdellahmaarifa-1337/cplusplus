#include <iostream>
#include "PmergeMe.hpp"

using namespace std;



int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "usage: ./PmergeMe [ ... ]\n";
		return(1);
	}
	PmergeMe test(++av, --ac);
	test.sort();
	test.display();
	//test.test();
	return 0;
}