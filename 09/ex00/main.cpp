#include <iostream>
#include <map>
#include <exception>
#include "BitcoinExchange.hpp"

using namespace std;
#define db_path "./data.csv"


int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "usage: ./btc [input_file]\n";
		return (1);
	}

	BitcoinExchange btc(std::string(db_path));
	btc.eval(av[1]);
	return 0;
}