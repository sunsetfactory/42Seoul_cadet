#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap claptrap("CL-7");
    ClapTrap claptrap2(claptrap);
    cout << endl << endl;

    ClapTrap claptrap3;
    claptrap3 = claptrap;
    cout << endl << endl;

    ClapTrap claptrap4("CL-8");
    //   ClapTrap claptrap5 = claptrap4;
    cout << endl << endl;

    claptrap.attack("seokjyan");
    claptrap.takeDamage(5);
    claptrap.beRepaired(5);
    cout << endl << endl;

    claptrap2.attack("seokjyan");
    claptrap2.takeDamage(5);
    claptrap2.beRepaired(5);
    cout << endl << endl;

    claptrap3.attack("seokjyan");
    claptrap3.takeDamage(5);
    claptrap3.beRepaired(5);
    cout << endl << endl;
    return 0;
}
