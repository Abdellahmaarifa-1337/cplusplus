#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>

class Brain {
	public:
	Brain();
	Brain(Brain &br);
	Brain &operator=(Brain &br);
	~Brain();
	void setIdeas(std::string idea);
	std::string *getIdeas();
	private:
	std::string *ideas;
};

#endif