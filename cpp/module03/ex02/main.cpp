#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <cmath>

int main()
{
    cout << YELLOW "==================Fragline=================" RESET << endl;
    FragTrap fragtrap("Frag-01");
    fragtrap.attack("seokjyan");
    fragtrap.takeDamage(10);
    fragtrap.beRepaired(10);
    fragtrap.highFivesGuys();
    cout << endl;

    cout << YELLOW "==================Scavline=================" RESET << endl;
    ScavTrap scavtrap("Scav-01");
    scavtrap.attack("Frag-01");
    scavtrap.takeDamage(10);
    scavtrap.beRepaired(10);
    scavtrap.guardGate();
    cout << endl;

    cout << YELLOW "==================Clapline1=================" RESET << endl;
    ClapTrap claptrap("clap-01");
    claptrap.attack("Frag-01");
    claptrap.takeDamage(10);
    claptrap.beRepaired(10);
    cout << endl;

    cout << YELLOW "==================Copyline2=================" RESET << endl;
    fragtrap.attack("seokjyan");
    // fragtrap.get_status(fragtrap);
    fragtrap.takeDamage(50);
    fragtrap.takeDamage(50);
    fragtrap.takeDamage(50);
    fragtrap.beRepaired(10);
    FragTrap fragtrap2(fragtrap);
    // fragtrap2.get_status(fragtrap);
    fragtrap2.attack("seokjyan");
    fragtrap2.takeDamage(50);
    ScavTrap scavtrap2(scavtrap);
    cout << scavtrap2.get_Name() << endl;
    ClapTrap claptrap2(claptrap);
    cout << claptrap2.get_Name() << endl;
    cout << endl;

    cout << YELLOW "==================SetingLine=================" RESET << endl;
    FragTrap fragtrap3("Frag-02");
    FragTrap fragtrap4;
    cout << endl;

    ScavTrap scavtrap3("Scav-02");
    ScavTrap scavtrap4;
    cout << endl;

    ClapTrap claptrap3("clap-02");
    ClapTrap claptrap4;
    cout << endl;

    fragtrap4 = fragtrap3;
    scavtrap4 = scavtrap3;
    claptrap4 = claptrap3;
    cout << endl;

    return 0;
}
