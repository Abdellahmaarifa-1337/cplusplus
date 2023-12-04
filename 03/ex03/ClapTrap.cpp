#include "ClapTrap.hpp"
#include <stdlib.h>
#include <sstream>

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap default constructor called\n";
    _name = "undefined";
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0;
};

ClapTrap::ClapTrap(std::string name)
{
    std::cout << "ClapTrap parametrized constructor called\n";
    _name = name;
    _hitPoints = 10;
    _energyPoints = 10;
    _attackDamage = 0; 
};

ClapTrap::ClapTrap(ClapTrap &ClapTrap)
{
    std::cout << "ClapTrap copy constructor called\n";
    _name = ClapTrap._name;
    _hitPoints = ClapTrap._hitPoints;
    _energyPoints = ClapTrap._energyPoints;
    _attackDamage = ClapTrap._attackDamage;
};

ClapTrap &ClapTrap::operator=(ClapTrap &ClapTrap)
{
    std::cout << "ClapTrap copy assignment operator called\n";
     _name = ClapTrap._name;
    _hitPoints = ClapTrap._hitPoints;
    _energyPoints = ClapTrap._energyPoints;
    _attackDamage = ClapTrap._attackDamage;
    return *this;
};

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called\n";
};



void ClapTrap::attack(const std::string &target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "ClapTrap " << _name << " can't attack!\n";
        return ;
    };
    _energyPoints -= 1;
    std::cout << "CLapTrap " << _name << " attacks " << target << ", ";
    std::cout << "causing " << _attackDamage << " points of damage!\n";
};

void ClapTrap::takeDamage(unsigned int amount)
{
    _hitPoints -= amount;
    std::cout <<  _name << " lost " << amount << " of hit points!\n";
};

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)   
    {
        std::cout  << _name << " can't repaire!\n";
        return ;
    }
    _hitPoints += amount;
    _energyPoints -= 1;
    std::cout  << _name << " gets " << amount << " of hit points back!\n";
};

// Setters and Getters

void    ClapTrap::setName(std::string name)
{
    _name = name;
};

std::string ClapTrap::getName(void) const
{
    return _name;
};

void    ClapTrap::setHitPoints(int hitPoints)
{
    _hitPoints = hitPoints;
};

int ClapTrap::getHitPoints(void) const
{
    return _hitPoints;
};

void    ClapTrap::setEnergyPoints(int energyPoints)
{
    _energyPoints = energyPoints;
};

int ClapTrap::getEnergyPoints(void) const
{
    return _energyPoints;
};

void    ClapTrap::setAttackDamage(int attackDamage)
{
    _attackDamage = attackDamage;
};

int ClapTrap::getAttackDamage(void) const
{
    return _attackDamage;
};

std::string to_str(int x)
{
    std::string s;
    std::stringstream ss;
    ss << x;
    ss >> s;
    return s;
};

void ClapTrap::state(std::string st)
{
    std::cout << "\n" << std::setfill('*') << std::setw(62) << "\n" ;
    std::cout << std::setfill('*') << std::setw(5) << "";
    std::cout << std::setfill(' ') << std::setw(50) << " " + _name + " State after : " + st << " ";
    std::cout << std::setfill('*') << std::setw(5) << "" << "\n";

    std::cout << std::setfill('*') << std::setw(5) << "";
    std::cout << std::setfill(' ') << std::setw(50) << "Hit Points: " +  to_str(_hitPoints) << " "; 
    std::cout << std::setfill('*') << std::setw(5) << "" << "\n";

    std::cout << std::setfill('*') << std::setw(5) << "";
    std::cout << std::setfill(' ') << std::setw(50)  << "Attack Damage: " + to_str(_attackDamage) << " "; 
    std::cout << std::setfill('*') << std::setw(5) << "" << "\n";

    std::cout << std::setfill('*') << std::setw(5) << "";
    std::cout << std::setfill(' ') << std::setw(50)  << "Energy Points: " + to_str(_energyPoints) << " ";
    std::cout << std::setfill('*') << std::setw(5) << "";

    std::cout << "\n" << std::setfill('*') << std::setw(62) << "\n" ;

};