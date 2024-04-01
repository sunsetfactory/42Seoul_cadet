#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "brain.hpp"
#include <iostream>

class Animal
{
  protected:
    std::string type;
    Brain *brain;

  public:
    Animal();
    Animal(std::string name);
    virtual ~Animal();
    Animal(const Animal &animal);
    Animal &operator=(const Animal &animal);
    virtual void makeSound() const;
    std::string getType() const;
    virtual Brain *getBrain() const;
};

#endif
