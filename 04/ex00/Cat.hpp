#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"

class Cat : public Animal {
	public:
	Cat();
	Cat(std::string type);
	Cat(Cat &Cat);
	virtual ~Cat();
	Cat &operator=(Cat &Cat);
	void makeSound() const;
};

#endif