#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _Hit_point = 100;
    _Energy_point = 50;
    _Attack_damage = 20;
    cout << get_Name() << " product has been upgraded to Scavtrap" << endl;
}

ScavTrap::ScavTrap(string name) : ClapTrap()
{
    cout << get_Name() << " produced " GREEN << name << RESET << endl;
    _Name = name;
    _Hit_point = 100;
    _Energy_point = 50;
    _Attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
    cout << "Produced the same model as " << scavtrap.get_Name() << endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
    cout << get_Name() << " was set the same as " << scavtrap.get_Name() << endl;
    _Name = scavtrap._Name;
    _Hit_point = scavtrap._Hit_point;
    _Energy_point = scavtrap._Energy_point;
    _Attack_damage = scavtrap._Attack_damage;
    return *this;
}

ScavTrap::~ScavTrap()
{
    cout << "ScavTrap " << get_Name() << " was " RED "destroyed" RESET << endl;
}

void ScavTrap::guardGate(void)
{
    cout << "ScavTrap " << get_Name() << " have enterred in Gate keeper mode." << endl;
}

void ScavTrap::attack(const string &target)
{
    cout << "ScavTrap " << get_Name() << " attacks " RED << target << RESET " causing " << _Attack_damage
         << " points of damage!" << endl;
}
