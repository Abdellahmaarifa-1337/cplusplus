#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;

	const WrongAnimal *wa = new WrongAnimal();
	const WrongAnimal *c = new WrongCat();
	const WrongCat *d = new WrongCat();
	std::cout << c->getType() << " " << std::endl;
	c->makeSound();
	wa->makeSound();
	d->makeSound();
	delete wa;
	delete c;
	delete d;
	return 0;
}