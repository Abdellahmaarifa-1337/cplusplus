#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;
};

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
};
void HumanB::attack(void)
{
	std::cout << name << "attacks with ";
	if (weapon)
		std::cout << "their " << weapon->getType() << "\n";
	else
		std::cout << "no weapon\n";
};
