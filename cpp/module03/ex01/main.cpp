#include "ScavTrap.hpp"

int main()
{
    ScavTrap scavtrap("CL-7");
    ScavTrap scavtrap2(scavtrap);
    cout << endl << endl;

    ScavTrap scavtrap3;
    scavtrap3 = scavtrap;
    cout << endl << endl;

    ScavTrap scavtrap4("CL-8");
    ScavTrap scavtrap5 = scavtrap4;
    cout << endl << endl;

    scavtrap.attack("seokjyan");
    scavtrap.takeDamage(5);
    scavtrap.beRepaired(5);
    cout << endl << endl;

    scavtrap2.attack("seokjyan");
    scavtrap2.takeDamage(5);
    scavtrap2.beRepaired(5);
    cout << endl << endl;

    scavtrap3.attack("seokjyan");
    scavtrap3.takeDamage(5);
    scavtrap3.beRepaired(5);
    cout << endl << endl;
    return 0;
}
