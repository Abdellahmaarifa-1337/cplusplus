#include "Brain.hpp"

Brain::Brain(){
	std::cout << "Brain default constructor created\n";
	this->ideas = new std::string[100];
};


Brain::Brain(Brain &br)
{
	std::cout << "Brain copy constructor created\n";
	this->ideas = br.ideas;
};

Brain &Brain::operator=(Brain &br)
{
	std::cout << "Brain assgnment operator called\n";
	for(int i = 0; i < 100; i++)
	{
		this->ideas[i] = br.ideas[i];
	}
	return *this;
};

Brain::~Brain(){
	std::cout << "Brain deconstructor created\n";
	
	delete[] this->ideas;
};

void Brain::setIdeas(std::string idea)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = idea + " " + std::to_string(i);
	}	
};

std::string *Brain::getIdeas()
{
	return this->ideas;
};