#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
  public:
<<<<<<< HEAD
    ScavTrap();
    ScavTrap(const ScavTrap &scavtrap);
    ScavTrap &operator=(const ScavTrap &scavtrap);
    ~ScavTrap();
    ScavTrap(string name);
=======
    ScavTrap(string name);
    ScavTrap(const ScavTrap &scavtrap);
    ScavTrap &operator=(const ScavTrap &scavtrap);
    ~ScavTrap();
>>>>>>> 2886fe13c2d8b90757605de8c0bd1332dc24116f
    void attack(const string &target);
    void guardGate(void);
};

#endif
