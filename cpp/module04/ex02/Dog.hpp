#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
{
  private:
    Brain *brain;

  public:
    Dog();
    Dog(const Dog &dog);
    Dog &operator=(const Dog &dog);
    virtual ~Dog();
    virtual void makeSound() const;
    Brain *getBrain() const;
};

#endif