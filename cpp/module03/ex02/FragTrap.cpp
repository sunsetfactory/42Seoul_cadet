#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    _Hit_point = 100;
    _Max_hit_point = 100;
    _Energy_point = 100;
    _Attack_damage = 30;
    cout << get_Name() << " product has been upgraded to Fragtrap" << endl;
}

FragTrap::FragTrap(string name) : ClapTrap()
{
    cout << get_Name() << " produced " GREEN << name << RESET << endl;
    _Name = name;
    _Hit_point = 100;
    _Max_hit_point = 100;
    _Energy_point = 100;
    _Attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap &FragTrap) : ClapTrap(FragTrap)
{
    cout << "Copy of the FragTrap " << FragTrap.get_Name() << " model is complete" << endl;
}

FragTrap &FragTrap::operator=(const FragTrap &FragTrap)
{
    cout << get_Name() << " was set the same as " << FragTrap.get_Name() << endl;
    _Name = FragTrap._Name;
    _Hit_point = FragTrap._Hit_point;
    _Max_hit_point = FragTrap._Max_hit_point;
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
    if (_Energy_point == 0)
    {
        cout << "FragTrap " << get_Name() << " has no energy" << endl;
        return;
    }
    if (_Hit_point == 0)
    {
        cout << "FragTrap " << get_Name() << " is already dead" << endl;
        return;
    }
    cout << "FragTrap " << get_Name() << " attacks " RED << target << RESET " causing " << _Attack_damage
         << " points of damage!" << endl;
    _Energy_point -= 1;
}

void FragTrap::highFivesGuys(void)
{
    cout << "FragTrap " << get_Name() << " high fives guys!" << endl;
}
