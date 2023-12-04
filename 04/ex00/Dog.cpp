#include "Dog.hpp"


Dog::Dog(): Animal()
{
	std::cout << "Dog default construction called\n";
	type = "Dog";
};
Dog::Dog(std::string type) : Animal("animal")
{
	std::cout << "Dog paramitrized construction called\n";
	type = this->type;
};

Dog::Dog(Dog &dog) : Animal(dog)
{
	this->type = dog.type;
};
Dog &Dog::operator=(Dog &dog)
{
	this->type = dog.type;
	return *this;
};

Dog::~Dog()
{
	std::cout << "Dog destruction called\n";
};

void Dog::makeSound() const
{
	std::cout << "Haaw Haaw Haaw\n";
};

