#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
  public:
    ScavTrap();
    ScavTrap(const ScavTrap &scavtrap);
    ScavTrap &operator=(const ScavTrap &scavtrap);
    ~ScavTrap();
    ScavTrap(string name);
    void attack(const string &target);
    void guardGate(void);
};

#endif
