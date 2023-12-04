#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name)
{
    std::cout << "DiamondTrap parametrized constructor called\n";
    _name = name;
    ClapTrap::_name = name + "_clap_name";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;

};

DiamondTrap::DiamondTrap()
{
    std::cout << "DiamondTrap default constructor called\n";
     _name = "default";
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
};

DiamondTrap::DiamondTrap(DiamondTrap &diamondTrap) : ClapTrap(diamondTrap),  ScavTrap(diamondTrap), FragTrap(diamondTrap)
{
    std::cout << "DiamondTrap copy constructor called\n";
    _name = diamondTrap._name;
    _hitPoints = diamondTrap._hitPoints;
    _energyPoints = diamondTrap._energyPoints;
    _attackDamage = diamondTrap._attackDamage;
};

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called\n";

};
// void DiamondTrap::attack(const std::string& target)
// {
//     ScavTrap::attack(target);
// };
void DiamondTrap::whoAmI()
{
    std::cout << "name : " << _name << " | " << "ClapTrap name : " << ClapTrap::_name << "\n";
};