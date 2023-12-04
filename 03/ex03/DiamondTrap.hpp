#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP
#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap :  public ScavTrap,  public FragTrap{

    private:
    std::string _name;
    public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(DiamondTrap &diamondTrap);
    ~DiamondTrap();
    void whoAmI();
};

#endif