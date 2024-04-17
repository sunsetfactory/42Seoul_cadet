#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _Hit_point = 100;
    _Max_hit_point = 100;
    _Energy_point = 50;
    _Attack_damage = 20;
    cout << get_Name() << " product was produced with scavtrap" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
    cout << "Copy of the ScavTrap " << scavtrap.get_Name() << " model is complete" << endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
    cout << "Assignation of the ScavTrap " << scavtrap.get_Name() << " model is complete" << endl;
    _Name = scavtrap._Name;
    _Hit_point = scavtrap._Hit_point;
    _Max_hit_point = scavtrap._Max_hit_point;
    _Energy_point = scavtrap._Energy_point;
    _Attack_damage = scavtrap._Attack_damage;
    return *this;
}

ScavTrap::~ScavTrap()
{
    cout << "ScavTrap " << get_Name() << " was " RED "destroyed" RESET << endl;
}

ScavTrap::ScavTrap(string name) : ClapTrap(name)
{
    _Hit_point = 100;
    _Max_hit_point = 100;
    _Energy_point = 50;
    _Attack_damage = 20;
    cout << get_Name() << " product was produced with scavtrap" << endl;
}

void ScavTrap::attack(const string &target)
{
    cout << "ScavTrap " << get_Name() << " attacks " RED << target << RESET " causing " << _Attack_damage
         << " points of damage!" << endl;
}

void ScavTrap::guardGate(void)
{
    cout << "ScavTrap " << get_Name() << " have enterred in Gate keeper mode." << endl;
}
