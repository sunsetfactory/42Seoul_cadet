#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
  public:
    WrongCat();
    WrongCat(const WrongCat &wrongCat);
    WrongCat &operator=(const WrongCat &wrongCat);
    virtual ~WrongCat();
    virtual void makeSound() const;
};

#endif
