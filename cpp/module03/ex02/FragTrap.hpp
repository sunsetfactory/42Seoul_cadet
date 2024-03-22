#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>

# define string std::string
# define cout std::cout
# define cin std::cin
# define endl std::endl

class FragTrap{
    private:
        string _Name;
        int _Hit_point;
        int _Energy_point;
        int _Attack_damage;
    public:
        FragTrap();
        FragTrap(string Name);
        FragTrap(const FragTrap &fragtrap);
        FragTrap &operator=(const FragTrap &fragtrap);
        ~FragTrap();
        unsigned int get_Damage(void) const;
        void attack(const string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};

#endif