#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <iomanip>

class ClapTrap
{
    public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(ClapTrap &ClapTrap);
    ClapTrap &operator=(ClapTrap &ClapTrap);
    ~ClapTrap();
    void        attack(const std::string& target);
    void        takeDamage(unsigned int amount);
    void        beRepaired(unsigned int amount);
    void        setName(std::string name);
    std::string getName(void) const;
    void        setHitPoints(int hitPoints);
    int         getHitPoints(void) const;
    void        setEnergyPoints(int energyPoints);
    int         getEnergyPoints(void) const;
    void        setAttackDamage(int attackDamage);
    int         getAttackDamage(void) const;
    void        state(std::string st);
    protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;
};
#endif
