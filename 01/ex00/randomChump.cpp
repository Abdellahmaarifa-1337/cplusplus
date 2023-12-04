#include <iostream>
#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie zm(name);
	zm.announce();
};
