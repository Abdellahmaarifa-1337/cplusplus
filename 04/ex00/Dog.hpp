#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
	public:
	Dog();
	Dog(std::string type);
	Dog(Dog &dog);
	Dog &operator=(Dog &dog);
	virtual ~Dog();
	void makeSound() const;
};

#endif