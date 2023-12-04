#include "WrongCat.hpp"


WrongCat::WrongCat(): WrongAnimal()
{
	std::cout << "WrongCat default construction called\n";
	type = "WrongCat";
};
WrongCat::WrongCat(std::string type) : WrongAnimal("animal")
{
	std::cout << "WrongCat paramitrized construction called\n";
	type = this->type;
};

WrongCat::WrongCat(WrongCat &wrongCat) : WrongAnimal(wrongCat)
{
	this->type = wrongCat.type;
};
WrongCat &WrongCat::operator=(WrongCat &wrongCat)
{
	this->type = wrongCat.type;
	return *this;
};

WrongCat::~WrongCat(){
	std::cout << "WrongCat destruction called\n";
};

void WrongCat::makeSound() const
{
	std::cout << "WrongCat : mewoooo mewoooo mewooo\n";
};

