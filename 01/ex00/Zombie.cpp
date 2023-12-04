#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
};

Zombie::~Zombie()
{
	std::cout << name << " is deleted\n";
};

void	Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...";  
};