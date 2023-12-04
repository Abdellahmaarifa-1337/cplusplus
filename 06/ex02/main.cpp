#include <iostream>
#include <cmath>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	srand(time(NULL));
	int n = rand() % 3;
	if (n == 0)
	{
		std::cout << "[generatev] A\n";
		return  new A();
	}
	else if (n == 1)
	{
		std::cout << "[generate] B\n";
		return  new B();
	}
	std::cout << "[generate] C\n";
	return new C();
};

void identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "[identify] type is a\n";
	if (dynamic_cast<B *>(p))
		std::cout << "[identify ] type is b\n";
	if (dynamic_cast<C *>(p))
		std::cout << "[identify] type is c\n";
}

void identify(Base &p)
{
	try {
		A a = dynamic_cast<A &>(p);
		std::cout << "[identify] type is a\n";
	} catch(std::bad_cast &e)
	{
		(void)e;
	}
	try {
		B b = dynamic_cast<B &>(p);
		std::cout << "[identify] type is b\n";
	} catch(std::bad_cast &e)
	{
		(void)e;
	}
	try {
		C c = dynamic_cast<C &>(p);
		std::cout << "[identify] type is c\n";
	} catch(std::bad_cast &e)
	{
		(void)e;
	}
	
}

int main()
{
	std::cout << "\n-------------- TEST *PTR -------------\n\n";
	identify(*generate());
	std::cout << "\n-------------- TEST &REF -------------\n\n";
	identify(generate());
	std::cout << "\n--------------------------------------\n";
	return 0;
}