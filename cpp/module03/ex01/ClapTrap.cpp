#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _Hit_point(10), _Energy_point(10), _Attack_damage(0)
{
    cout << "Create a claptrap dummy" << endl;
}

ClapTrap::ClapTrap(string Name) : _Name(Name), _Hit_point(10), _Energy_point(10), _Attack_damage(0)
{
    cout << get_Name() << " product was produced with claptrap" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
    cout << "Copy of the claptrap " << claptrap.get_Name() << " model is complete" << endl;
    *this = claptrap;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
    claptrap.get_Damage();
    cout << "Assignation of the claptrap " << claptrap.get_Name() << " model is complete" << endl;
    _Name = claptrap._Name;
    _Hit_point = claptrap._Hit_point;
    _Energy_point = claptrap._Energy_point;
    _Attack_damage = claptrap._Attack_damage;
    return *this;
}

ClapTrap::~ClapTrap()
{
    cout << "ClapTrap " << get_Name() << " was " RED "destroyed" RESET << endl;
}

unsigned int ClapTrap::get_Damage(void) const
{
    return _Attack_damage;
}

void ClapTrap::attack(const string &target)
{
    cout << "claptrap " << get_Name() << " attacks " RED << target << RESET " causing " << _Attack_damage << " points of damage!"
         << endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    cout << "claptrap " << get_Name() << " takes " << amount << " points of damage!" << endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    cout << "claptrap " << get_Name() << " is repaired by " << amount << " points!" << endl;
}
string ClapTrap::get_Name() const
{
    string expressed_name;

    expressed_name = GREEN + _Name + RESET;
    return expressed_name;
}
