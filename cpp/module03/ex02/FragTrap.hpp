#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
  public:
    FragTrap();
    FragTrap(string name);
    FragTrap(const FragTrap &FragTrap);
    FragTrap &operator=(const FragTrap &FragTrap);
    ~FragTrap();
    void attack(const string &target);
    void highFivesGuys(void);
};

#endif
