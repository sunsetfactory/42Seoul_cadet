#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>

class ICharacter;

class AMateria
{
  protected:
    std::string _type;

  public:
    AMateria();
    AMateria(AMateria const &src);
    AMateria &operator=(AMateria const &src);
    virtual ~AMateria();

    AMateria(std::string const &type);
    std::string const &getType() const;
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter &target);
};

#endif