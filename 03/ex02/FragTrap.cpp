#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap parametrized constructor called\n";
    _name = name;
    ClapTrap::_hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
};

FragTrap::FragTrap()
{
     std::cout << "FragTrap default constructor called\n";
    _name = "undefined";
    ClapTrap::_hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
};

FragTrap::FragTrap(FragTrap &fragTrap) : ClapTrap(fragTrap)
{
    std::cout << "FragTrap copy constructor called\n";
    _name = fragTrap._name;
    _hitPoints = fragTrap._hitPoints;
    _energyPoints = fragTrap._energyPoints;
    _attackDamage = fragTrap._attackDamage;
};

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called\n";

};

void FragTrap::attack(const std::string &target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " can't attack!\n";
        return ;
    };
    _energyPoints -= 1;
    std::cout << "FragTrap " << _name << " attacks " << target << ", ";
    std::cout << "causing " << _attackDamage << " points of damage!\n";
};

void FragTrap::highFivesGuys()
{
    std::cout << "high Fives Guys!\n";
};