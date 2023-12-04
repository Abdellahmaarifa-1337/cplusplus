#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{
	Animal *an[4];
	//init the array
	std::cout << "\n--------- create animals ---------\n\n";
	for(int i = 0; i < 4; i++)
	{
		if (i < 2)
		{
			an[i] = new Dog();
		}
		else
			an[i] = new Cat();
	};

	//delete the array
	std::cout << "\n--------- delete animals ---------\n\n";

	for(int i = 0; i < 4; i++)
	{
		delete an[i];
	};

	//test copy vs shallow copy
	std::cout << "\n--------- Test Copy animals ---------\n\n";

	{

		Dog dj1 ;
		Dog dj2 ;
		dj1.setBrainIdeas("I am hungry");
		dj2.setBrainIdeas("I am sleepy");
		std::string *ideas = dj1.getBrainIdeas();

		std::cout << "------ before copy ------------\n";
		for(int i = 0; i < 2; i++)
			std::cout << ideas[i] << "\n";
		ideas = dj2.getBrainIdeas();
		for(int i = 0; i < 2; i++)
			std::cout << ideas[i] << "\n";
		
		dj1 = dj2;
		dj2.setBrainIdeas("i wanaa fly");
		std::cout << "------ after copy ------------\n";
		ideas = dj1.getBrainIdeas();
		for(int i = 0; i < 2; i++)
			std::cout << ideas[i] << "\n";
		ideas = dj2.getBrainIdeas();
		for(int i = 0; i < 2; i++)
			std::cout << ideas[i] << "\n";
	}
	return 0;
}