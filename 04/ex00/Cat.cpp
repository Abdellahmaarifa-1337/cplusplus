#include "Cat.hpp"


Cat::Cat(): Animal()
{
	std::cout << "Cat default construction called\n";
	type = "Cat";
};
Cat::Cat(std::string type) : Animal("animal")
{
	std::cout << "Cat paramitrized construction called\n";
	type = this->type;
};

Cat::Cat(Cat &cat) : Animal(cat)
{
	this->type = cat.type;
};
Cat &Cat::operator=(Cat &cat)
{
	this->type = cat.type;
	return *this;
};

Cat::~Cat()
{
	std::cout << "Cat destruction called\n";
};

void Cat::makeSound() const
{
	std::cout << "mewoooo mewoooo mewooo\n";
};