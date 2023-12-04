#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap parametrized constructor called\n";
    _name = name;
    ClapTrap::_hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
};

ScavTrap::ScavTrap()
{
     std::cout << "ScavTrap default constructor called\n";
    _name = "undefined";
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
};

ScavTrap::ScavTrap(ScavTrap &scavTrap) : ClapTrap(scavTrap)
{
    std::cout << "ScavTrap copy constructor called\n";
    _name = scavTrap._name;
    _hitPoints = scavTrap._hitPoints;
    _energyPoints = scavTrap._energyPoints;
    _attackDamage = scavTrap._attackDamage;
};

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called\n";

};

void ScavTrap::attack(const std::string &target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " can't attack!\n";
        return ;
    };
    _energyPoints -= 1;
    std::cout << "ScavTrap " << _name << " attacks " << target << ", ";
    std::cout << "causing " << _attackDamage << " points of damage!\n";
};

void ScavTrap::guardGate()
{
    std::cout << " ScavTrap is now in Gate keeper mode\n";
};