#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP
#include <iostream>

class WrongAnimal {
	public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(WrongAnimal &wrongAnimal);
	WrongAnimal &operator=(WrongAnimal &wrongAnimal);
	virtual ~WrongAnimal();
	void makeSound() const;
	std::string getType() const;
	void setType(std::string type);
	protected:
	std::string type;
};
#endif