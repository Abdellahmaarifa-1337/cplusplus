#include <iostream>
#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *zm = new Zombie(name);
	zm->announce();
	return (zm);
};

