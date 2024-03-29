#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
  protected:
    std::string type;
    std::string name;

  public:
    Animal();
    Animal(std::string name);
    virtual ~Animal();
    Animal(const Animal &animal);
    Animal &operator=(const Animal &animal);
    virtual void makeSound() const = 0;
    std::string getType() const;
    std::string getName() const;
};

#endif
