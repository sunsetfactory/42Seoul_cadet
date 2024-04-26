#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
  public:
    Ice();
    Ice(Ice const &src);
    Ice &operator=(Ice const &src);
    ~Ice();

    AMateria *clone() const;
    virtual void use(ICharacter &target);
};

#endif