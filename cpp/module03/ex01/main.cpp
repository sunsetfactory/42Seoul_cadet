#include "ScavTrap.hpp"

int main()
{
    ScavTrap sv_tp("SV-TP");
    ClapTrap cl_tp("CL-TP");
    cout << endl << endl;

    sv_tp.attack("seokjyan");
    sv_tp.takeDamage(10);
    sv_tp.beRepaired(5);
    sv_tp.guardGate();
    cout << endl << endl;

    cl_tp.attack("seokjyan");
    cl_tp.takeDamage(10);
    cl_tp.beRepaired(5);
    cout << endl << endl;

    return 0;
}
