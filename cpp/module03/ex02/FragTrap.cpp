#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _Hit_point = 100;
    _Energy_point = 100;
    _Attack_damage = 30;
    cout << get_Name() << " product has been upgraded to Fragtrap" << endl;
}

FragTrap::FragTrap(string name) : ClapTrap()
{
    cout << get_Name() << " produced " GREEN << name << RESET << endl;
    _Name = name;
    _Hit_point = 100;
    _Energy_point = 100;
    _Attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &FragTrap) : ClapTrap(FragTrap)
{
    cout << "Produced the same model as " << FragTrap.get_Name() << endl;
}

FragTrap &FragTrap::operator=(const FragTrap &FragTrap)
{
    cout << get_Name() << " was set the same as " << FragTrap.get_Name() << endl;
    _Name = FragTrap._Name;
    _Hit_point = FragTrap._Hit_point;
    _Energy_point = FragTrap._Energy_point;
    _Attack_damage = FragTrap._Attack_damage;

    return *this;
}

FragTrap::~FragTrap()
{
    cout << "FragTrap " << get_Name() << " was " RED "destroyed" RESET << endl;
}

void FragTrap::attack(const string &target)
{
    cout << "FragTrap " << get_Name() << " attacks " RED << target << RESET " causing " << _Attack_damage
         << " points of damage!" << endl;
}

void FragTrap::highFivesGuys(void)
{
    cout << "FragTrap " << get_Name() << " high fives guys!" << endl;
}
