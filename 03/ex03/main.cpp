#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
int main()
{
    DiamondTrap clap_1("d1");
	DiamondTrap clap_2("d2");
    clap_1.whoAmI();
	clap_1.highFivesGuys();
	clap_1.guardGate();
    clap_1.state("init");

	clap_1.attack(clap_2.getName());
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
    return (0);
}