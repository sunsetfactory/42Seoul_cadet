#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include "brain.hpp"
#include <iostream>

class AAnimal
{
  protected:
    std::string type;

  public:
    AAnimal();
    AAnimal(std::string name);
    virtual ~AAnimal();
    AAnimal(const AAnimal &Animal);
    AAnimal &operator=(const AAnimal &Animal);
    virtual void makeSound() const = 0; // 순수 가상 함수
    std::string getType() const;
};

#endif
