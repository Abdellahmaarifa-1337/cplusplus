#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int main()
{
	Zombie *zm;

	zm = zombieHorde(10, "Foo");

	for(int i = 0; i < 10; i++)
		zm[i].announce();
	delete[] zm;
	return (0);
}