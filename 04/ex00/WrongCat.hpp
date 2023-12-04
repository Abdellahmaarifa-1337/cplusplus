#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP	
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
	WrongCat();
	WrongCat(std::string type);
	WrongCat(WrongCat &WrongCat);
	WrongCat &operator=(WrongCat &wrongat);
	virtual ~WrongCat();
	void makeSound() const;
};
#endif