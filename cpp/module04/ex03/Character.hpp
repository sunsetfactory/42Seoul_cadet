#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
  private:
    std::string _name;
    AMateria *_inventory[4];
    AMateria *_materia;

  public:
    Character();
    Character(Character const &src);
    ~Character();
    Character &operator=(Character const &src);

    Character(std::string const &name);

    std::string const &getName() const;
    void equip(AMateria *m);
    void unequip(int idx);
    void use(int idx, ICharacter &target);
    AMateria *getMateria() const;
};

#endif