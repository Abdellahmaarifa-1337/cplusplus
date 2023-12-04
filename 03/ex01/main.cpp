#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{

    ScavTrap clap_1("clap_1");
    ScavTrap clap_2("clap_2");
    clap_1.setAttackDamage(5);
    clap_2.setAttackDamage(2);

    clap_1.attack("clap_2");
    clap_2.takeDamage(clap_1.getAttackDamage());
    clap_1.state("Attack");
    clap_2.state("Attack");


    clap_2.attack("clap_1");
    clap_1.takeDamage(clap_2.getAttackDamage());
    clap_1.state("Attack");
    clap_2.state("Attack");

    clap_1.beRepaired(3);
    clap_2.beRepaired(3);
    clap_1.state("repaired");
    clap_2.state("repaired");

	clap_1.guardGate();
    return (0);
}