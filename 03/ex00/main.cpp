#include "ClapTrap.hpp"

int main()
{
    ClapTrap clap_1("clap_1");
    ClapTrap clap_2("clap_2");
    clap_1.setAttackDamage(0);
    clap_2.setAttackDamage(2);

    clap_1.attack(clap_2.getName());
    clap_2.takeDamage(clap_1.getAttackDamage());
    clap_1.state("Attack");
    clap_2.state("Attack");

    clap_2.attack(clap_1.getName());
    clap_1.takeDamage(clap_2.getAttackDamage());
    clap_1.state("Attack");
    clap_2.state("Attack");

    clap_1.beRepaired(3);
    clap_2.beRepaired(3);
    clap_1.state("repaired");
    clap_2.state("repaired");
    return (0);
}