#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
  private:
    Brain *brain;

  public:
    Cat();
    Cat(const Cat &cat);
    Cat &operator=(const Cat &cat);
    virtual ~Cat();
    virtual void makeSound() const;
    Brain *getBrain() const;
};

#endif