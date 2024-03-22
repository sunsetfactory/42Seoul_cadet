#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {

    protected:
        static int count;
    private:
        std::string breed;
    public:
        Dog();
        Dog(std::string name, int age, std::string breed);
        virtual ~Dog();
        Dog(const Dog &src);
        Dog &operator=(const Dog &src);
        virtual void makeSound() const;
        void wagTail() const;
};

#endif