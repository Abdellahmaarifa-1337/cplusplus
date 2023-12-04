# include <iostream>
# include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump( std::string name );

int main()
{
	Zombie *zm;

	zm = newZombie("Foo");
	delete zm;
	randomChump("Baar");
	return (0);
}