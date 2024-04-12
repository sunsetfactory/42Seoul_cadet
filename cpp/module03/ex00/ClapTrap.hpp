#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

#define string std::string
#define cout std::cout
#define cin std::cin
#define endl std::endl

class ClapTrap
{
  private:
    string _Name;
    unsigned int _Hit_point;
    unsigned int _Energy_point;
    unsigned int _Attack_damage;

  public:
    ClapTrap();
    ClapTrap(string Name);
    explicit ClapTrap(const ClapTrap &claptrap);
    ClapTrap &operator=(const ClapTrap &claptrap);
    ~ClapTrap();
    unsigned int get_Damage(void) const;
    string get_Name(void) const;
    void attack(const string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};

#endif