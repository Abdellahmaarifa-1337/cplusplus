#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
};

std::string Weapon::getType(void)
{
	const std::string &typeRef = type;
	return (typeRef);
};

void	Weapon::setType(std::string type)
{
	this->type = type;
}