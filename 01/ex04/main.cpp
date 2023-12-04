#include <iostream>
#include <fstream>
#include <sstream>


using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::ofstream;

void replace_string(char **av)
{
	ifstream infile;
	ofstream outfile;
	string fname = string(av[1]);
	string s1 = string(av[2]);
	string s2 = string(av[3]);
	infile.open(av[1]);
	if (!infile.is_open())
	{
		cout << "Can't open the file\n";
		return ;
	}
	outfile.open(fname + ".replace");
	if (!outfile.is_open())
	{
		cout << "Can't create or write to the file\n";
		return ;
	}
	string data;

	std::ostringstream ss;
	ss << infile.rdbuf();
	data = ss.str();

	infile.close();

	size_t end = data.length();
	size_t start = 0;
	while ((end = data.find(s1, start)) != string::npos)
	{
		outfile << data.substr(start, end - start) << s2;
		start = end + s1.length();
	}
	outfile << data.substr(start, end - start);
	outfile.close();
}

int main(int ac, char **av)
{

	if (ac != 4)
	{
		cout << "Argument error!\n";
		return (0);
	}
	replace_string(av);
	return (0);
}