#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default construction called\n";
};
WrongAnimal::WrongAnimal(std::string type)
{
	std::cout << "WrongAnimal paramitrized construction called\n";
	type = this->type;
};

WrongAnimal::WrongAnimal(WrongAnimal &wrongAnimal)
{
	this->type = wrongAnimal.type;
};

WrongAnimal &WrongAnimal::operator=(WrongAnimal &wrongAnimal)
{
	this->type = wrongAnimal.type;
	return *this;
};

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destruction called\n";
};

void WrongAnimal::setType(std::string type)
{
	this->type = type;
};

std::string WrongAnimal::getType() const
{
	return type;
};
void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal animal sound\n";
};