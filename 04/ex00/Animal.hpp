#ifndef ANIMAL_HP	
#define ANIMAL_HP
#include <iostream>

class Animal {
	public:
	Animal();
	Animal(std::string type);
	Animal(Animal &animal);
	virtual ~Animal();
	Animal &operator=(Animal &animal);
	virtual void makeSound() const;
	std::string getType() const;
	void setType(std::string type);
	protected:
	std::string type;
};

#endif