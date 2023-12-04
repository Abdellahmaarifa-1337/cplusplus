#include <iostream>
#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*zm = new Zombie[N];

	for (int i = 0; i < N; i++)
		zm[i].setName(name);
	return (zm);
}
