#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    private:
        static int count;
    protected:
        std::string name;
        int age;
    public:
        Animal();
        Animal(std::string name, int age);
        virtual ~Animal();
        Animal(const Animal &src);
        Animal &operator=(const Animal &src);
        virtual void makeSound() const = 0;
        void printInfo() const;
};

#endif