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
  protected:
    string _Name;
    unsigned int _Hit_point;
    unsigned int _Max_hit_point;
    unsigned int _Energy_point;
    unsigned int _Attack_damage;

  public:
    ClapTrap();
    ClapTrap(string Name);
    ClapTrap(const ClapTrap &claptrap);
    ClapTrap &operator=(const ClapTrap &claptrap);
    ~ClapTrap();
    unsigned int get_Damage(void) const;
    void attack(const string &target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    string get_Name() const;
};

#endif