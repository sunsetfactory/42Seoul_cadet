#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _Name("None"), _Hit_point(10), _Max_hit_point(10), _Energy_point(10), _Attack_damage(0)
{
    cout << get_Name() << " product was produced with claptrap" << endl;
}

ClapTrap::ClapTrap(string Name) : _Name(Name), _Hit_point(10), _Max_hit_point(10), _Energy_point(10), _Attack_damage(0)
{
    cout << get_Name() << " product was produced with claptrap" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
    cout << "Produced the same model as " << claptrap.get_Name() << endl;
    _Name = claptrap._Name;
    _Hit_point = claptrap._Hit_point;
    _Energy_point = claptrap._Energy_point;
    _Attack_damage = claptrap._Attack_damage;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
    cout << get_Name() << " was set the same as " << claptrap.get_Name() << endl;
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
    if (_Energy_point == 0)
    {
        cout << "claptrap " << get_Name() << " has no energy" << endl;
        return;
    }
    if (_Hit_point == 0)
    {
        cout << "claptrap " << get_Name() << " is already dead" << endl;
        return;
    }
    cout << "claptrap " << get_Name() << " attacks " RED << target << RESET " causing " << _Attack_damage
         << " points of damage!" << endl;
    _Energy_point -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_Hit_point >= amount)
    {
        cout << get_Name() << " takes " << amount << " points of damage!" << endl;
        _Hit_point -= amount;
    }
    if (_Hit_point <= 0)
    {
        cout << get_Name() << " is died" << endl;
        _Hit_point = 0;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_Energy_point == 0)
    {
        cout << get_Name() << " has no energy" << endl;
        return;
    }
    if (_Hit_point <= 0)
    {
        cout << get_Name() << " is already dead" << endl;
        _Hit_point = 0;
        return;
    }
    if (_Hit_point == _Max_hit_point)
    {
        cout << get_Name() << " is already full health" << endl;
        return;
    }
    cout << get_Name() << " is repaired for " << amount << " points!" << endl;
    _Hit_point += amount;
    if (_Hit_point > _Max_hit_point)
        _Hit_point = _Max_hit_point;
    _Energy_point -= 1;
}
string ClapTrap::get_Name() const
{
    string expressed_name;

    expressed_name = GREEN + _Name + RESET;
    return expressed_name;
}
