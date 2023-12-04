
#include <iostream>
#include "Weapon.hpp"

class HumanA 
{
	private:
	std::string name;
	Weapon &weapon;
	public:
	HumanA(std::string name, Weapon &weapon_a) : weapon(weapon_a)
	{
		this->name = name;
	};
	void attack(void);
};

