#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include "brain.hpp"
#include <iostream>

class Animal
{
  protected:
    std::string type;

  public:
    Animal();
    Animal(std::string name);
    virtual ~Animal();
    Animal(const Animal &animal);
    Animal &operator=(const Animal &animal);
    virtual void makeSound() const = 0; // 순수 가상 함수
    std::string getType() const;
};

#endif
