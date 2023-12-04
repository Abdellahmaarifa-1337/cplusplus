#include "Cat.hpp"
#include "Brain.hpp"


Cat::Cat(): Animal()
{
	std::cout << "Cat default construction called\n";
	this->br = new Brain();
	type = "Cat";
};
Cat::Cat(std::string type) : Animal("animal")
{
	std::cout << "Cat paramitrized construction called\n";
	this->br = new Brain();
	type = this->type;
};

Cat::Cat(Cat &cat) : Animal(cat)
{
	this->type = cat.type;
};
Cat &Cat::operator=(Cat &cat)
{
	this->type = cat.type;
	if (this->br)
		delete this->br;
	Brain *newbr = new Brain();
	*newbr = *(cat.br);
	this->br = newbr;
	return *this;
};

Cat::~Cat()
{
	delete this->br;
	std::cout << "Cat destruction called\n";
};

void Cat::makeSound() const
{
	std::cout << "mewoooo mewoooo mewooo\n";
};

void Cat::setBrainIdeas(std::string idea)
{
	this->br->setIdeas(idea);
};

std::string *Cat::getBrainIdeas()
{
	return this->br->getIdeas();
};