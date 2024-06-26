#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap &fragTrap);
    ~FragTrap();
    void        attack(const std::string& target);
    void highFivesGuys();
};

#endif