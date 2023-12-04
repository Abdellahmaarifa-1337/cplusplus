#include <iostream>

int main()
{
	std::string name = "HI THIS IS BRAIN";
	std::string *stringPTR = &name;
	std::string &stringREF = name;

	std::cout << "the address of name : " << &name <<"\n";
	std::cout << "the address held by stringPTR : " << stringPTR << "\n";
	std::cout << "the address held by string REF : " << &stringREF << "\n";
	std::cout <<"\n";
	std::cout << "the value of name : " << name <<"\n";
	std::cout << "the value pointed to by stringPTR : " << *stringPTR << "\n";
	std::cout << "the value pointed to by string REF : " << stringREF << "\n";

	return (0);
}