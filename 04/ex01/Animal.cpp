#include "Animal.hpp"


Animal::Animal()
{
	std::cout << "Animal default construction called\n";
};
Animal::Animal(std::string type)
{
	std::cout << "Animal paramitrized construction called\n";
	type = this->type;
};

Animal::~Animal()
{
	std::cout << "Animal  destruction called\n";
};

Animal::Animal(Animal &animal)
{
	this->type = animal.type;
};
Animal &Animal::operator=(Animal &animal)
{
	this->type = animal.type;
	return *this;
};

std::string Animal::getType() const
{
	return type;
};

void Animal::setType(std::string type)
{
	this->type = type;
};

void Animal::makeSound() const
{
	std::cout << "animal sound\n";
};

