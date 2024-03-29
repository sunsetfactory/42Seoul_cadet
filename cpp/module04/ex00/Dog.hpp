#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {
    public:
        Dog();
        virtual ~Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &src);\
        virtual void makeSound() const;
};

#endif