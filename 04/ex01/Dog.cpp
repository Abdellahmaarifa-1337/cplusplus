#include "Dog.hpp"
#include "Brain.hpp"


Dog::Dog(): Animal()
{
	std::cout << "Dog default construction called\n";
	type = "Dog";
	this->br = new Brain();
};
Dog::Dog(std::string type) : Animal("animal")
{
	std::cout << "Dog paramitrized construction called\n";
	type = this->type;
	this->br = new Brain();
};

Dog::Dog(Dog &dog) : Animal(dog)
{
	this->type = dog.type;
};
 
Dog &Dog::operator=(Dog &dog)
{
	this->type = dog.type;
	if (this->br)
		delete this->br;
	Brain *newbr = new Brain();
	*newbr = *(dog.br);
	this->br = newbr;
	return *this;
};

Dog::~Dog()
{
	std::cout << "Dog destruction called\n";
	delete this->br;
};

void Dog::makeSound() const
{
	std::cout << "Haaw Haaw Haaw\n";
};

void Dog::setBrainIdeas(std::string idea)
{
	this->br->setIdeas(idea);
};

std::string *Dog::getBrainIdeas()
{
	return this->br->getIdeas();
};