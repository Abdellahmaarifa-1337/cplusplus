#include "main.hpp"

int is_digit(std::string str)
{
	int i;
	const char *s = str.c_str();
	if (!s)
		return (0);
	while (s[i])
	{
		if (!std::isdigit(s[0]))
			return 0;
		i++;
	}
	return (1);
}

void get_string(std::string &s)
{
	while (1)
	{
		getline(CIN, s);
		if (CIN.eof())
			exit(1);
		if (!s[0])
		{
			COUT << "Please try again! :\n";
			continue ;
		}
		break ;
	}
}

void get_number(std::string &n)
{
	int num;
	while (1)
	{
		getline(CIN, n);
		if (CIN.eof())
			exit(1);
		if (!n[0])
		{
			COUT << "Please try again! :\n";
			continue ;
		}
		if (!is_digit(n))
		{
			COUT << "Please try again! :\n";
			continue ;
		}
		break;	
	}
	return ;
}